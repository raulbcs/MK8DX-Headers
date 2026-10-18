#!/usr/bin/env python3
"""Map unmapped vtables to construction sites.

Pipeline (proven on this binary):
 1. .rela.dyn stride-8 runs of func ptrs in .data = vtables (tools/vts_unmapped_tiers.json).
 2. GOT cells (raw qwords, no reloc) hold vt-0x10..vt+0x10; code reaches vtables
    via adrp+ldr on those GOT cells (direct adrp+add is NOT used).
 3. adrp+ldr scan of .text -> consumption/install sites -> candidate ctor (lowest
    address site; the ctor usually dominates).

Usage: python3 tools/vt_ctors.py [--top N] [--elf path]
Output: tools/vt_ctors.tsv  vt, slots, tier, got_cells, sites
"""
import struct, re, subprocess, sys, json

ELF = '/Users/raul/projects/mk8dx-400/data/main.elf'
TIERS = 'tools/vts_unmapped_tiers.json'

def readelf_sections(elf):
    out = subprocess.check_output(['/opt/homebrew/opt/llvm/bin/llvm-readelf','-S','-W',elf]).decode()
    sec = {}
    for l in out.splitlines():
        m = re.match(r"\s*\[\s*\d+\]\s+(\S+)\s+\S+\s+([0-9a-f]+)\s+([0-9a-f]+)\s+([0-9a-f]+)\s", l)
        if m: sec[m.group(1)] = (int(m.group(2),16), int(m.group(3),16), int(m.group(4),16))
    return sec

def main():
    args = sys.argv[1:]
    top = int(args[args.index('--top')+1]) if '--top' in args else None
    elf = args[args.index('--elf')+1] if '--elf' in args else ELF
    sec = readelf_sections(elf)
    blob = open(elf,'rb').read()
    va, voff, vsize = sec['.text']

    tiers = json.load(open(TIERS))
    targets = {}
    for tier in ('game','mid','framework'):
        for a,n in tiers[tier]:
            targets[a] = (n, tier)
    if top:
        order = sorted(targets.items(), key=lambda kv: (-kv[1][0], kv[1][1]!='game'))
        keep = {a for a,_ in order[:top]}
        targets = {a:t for a,t in targets.items() if a in keep}

    # 1. GOT cell index: value -> [cells]
    got_index = {}
    for name in ('.got','.got.plt'):
        if name not in sec: continue
        a,o,s = sec[name]
        for i in range(s//8):
            v = struct.unpack_from('<Q', blob, o+i*8)[0]
            got_index.setdefault(v, []).append(a+i*8)

    # 2. vt -> relevant GOT cells
    vt_cells = {}
    for a in targets:
        cells = []
        for d in range(-16, 24, 8):
            cells += got_index.get(a+d, [])
        if cells: vt_cells[a] = cells
    cell2vt = {}
    for a, cells in vt_cells.items():
        for c in cells: cell2vt.setdefault(c, set()).add(a)

    # 3. adrp+ldr scan of .text
    code = blob[voff:voff+vsize]
    n = vsize//4
    adrp_last = {}
    sites = {}   # vt -> [(site, cell)]
    for i in range(n):
        w = struct.unpack_from('<I', code, i*4)[0]
        if (w & 0x9f000000) == 0x90000000:
            rd = w & 31
            immlo = (w >> 29) & 3
            immhi = (w >> 5) & 0x7ffff
            imm = (immhi << 2) | immlo
            if imm & 0x100000: imm -= 0x200000
            # PC for ADRP is the page address of the instruction (BUGFIX: was unaligned)
            adrp_last[rd] = (((va + i*4) & ~0xfff) + (imm << 12), i)
        elif (w & 0xffc00000) == 0xf9400000:  # ldr Xt, [Xn, #imm12*8]
            rn = (w >> 5) & 31
            imm = ((w >> 10) & 0xfff) * 8
            if rn in adrp_last:
                page, j = adrp_last[rn]
                if i - j <= 12:
                    addr = page + imm
                    if addr in cell2vt:
                        for vt in cell2vt[addr]:
                            sites.setdefault(vt, []).append((va + i*4, addr))
    rows = sorted(targets.items(), key=lambda kv: (-kv[1][0], kv[1][1]!='game'))
    with open('tools/vt_ctors.tsv','w') as f:
        f.write('vt\tslots\ttier\tgot_cells\tsites\n')
        nf = 0
        for a,(nslots,tier) in rows:
            cs = ','.join(hex(c) for c in vt_cells.get(a,[]))
            st = ';'.join(f'{hex(s)}@{hex(c)}' for s,c in sites.get(a,[])[:8])
            if st: nf += 1
            f.write(f'{hex(a)}\t{nslots}\t{tier}\t{cs}\t{st}\n')
    print(f'{len(rows)} targets, {len(vt_cells)} with GOT cell, {nf} with code sites -> tools/vt_ctors.tsv')

if __name__ == '__main__':
    main()
