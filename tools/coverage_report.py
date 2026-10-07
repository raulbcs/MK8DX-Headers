#!/usr/bin/env python3
"""Coverage report for the MK8DX-Headers package.

Classifies every .hpp under include/ into one of five statuses (parsed from
filenames, docblocks and comments — nothing is inferred or invented):

  NAMED-PROVEN  semantic name + extent cited, path NOT in the
                NO_EXTENT_ALLOWLIST embedded in check_extents.py
  NAMED         semantic name but path in the allowlist (no cited extent)
  PROVISIONAL   docblock contains "PROVISIONAL", or the name is a generic
                Vt<addr> / RaceDirectorVt* placeholder outside include/object/
  PLACEHOLDER   generic Vt<addr> name under include/object/
  DOCBLOCK-ONLY no field declarations (comment/reference-only header)

For each header it also extracts:
  anchors  — cited vptr/vtable/cell/ctor/factory/alloc-site addresses
  tags     — RTTI-confirmed / unproven / SDK-internal / Baptism audit
  gaps     — count of "unproven gap" / "no ctor evidence" notes

Outputs:
  COVERAGE.md    commitable summary (per-directory table + totals)
  coverage.html  self-contained clickable treemap (NOT committed)

Usage: python3 tools/coverage_report.py
"""

import html
import json
import re
import sys
from datetime import datetime
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
INCLUDE = ROOT / "include"

sys.path.insert(0, str(ROOT / "tools"))
from check_extents import NO_EXTENT_ALLOWLIST  # noqa: E402

ALLOWLIST = set(
    l.strip()[2:].strip()
    for l in NO_EXTENT_ALLOWLIST.splitlines()
    if l.strip().startswith("#   ")
)

RE_FIELD = re.compile(r"^\s*\w[\w\[\]<>:*,\s]*;\s*//")
RE_EXTENT = re.compile(r"\bextent\b\s*(?:>=?\s*)?0x[0-9a-fA-F]+", re.I)
RE_ANCHOR = re.compile(
    r"\b(vptr|vtable|cell|ctor|factory|alloc\s+site|site|dispatch|thunk)"
    r"[^\n0-9]{0,30}?(0x[0-9a-fA-F]{4,})",
    re.I,
)
RE_SEMANTIC_VT = re.compile(r"^(RaceDirectorVt|Vt)[0-9a-fA-F]+$")
RE_OBJECT_VT = re.compile(r"^Vt[0-9a-fA-F]+$")

TAGS = ["RTTI-confirmed", "unproven", "SDK-internal", "Baptism audit"]

STATUS_ORDER = ["NAMED-PROVEN", "NAMED", "PROVISIONAL", "PLACEHOLDER", "DOCBLOCK-ONLY"]

STATUS_COLORS = {
    "NAMED-PROVEN": "#43a047",
    "NAMED": "#fdd835",
    "PROVISIONAL": "#fb8c00",
    "PLACEHOLDER": "#9e9e9e",
    "DOCBLOCK-ONLY": "#b3e5fc",
}


def classify(rel: str, stem: str, text: str, n_fields: int) -> str:
    if n_fields == 0:
        return "DOCBLOCK-ONLY"
    if rel.startswith("include/object/") and RE_OBJECT_VT.match(stem):
        return "PLACEHOLDER"
    if "PROVISIONAL" in text or RE_SEMANTIC_VT.match(stem):
        return "PROVISIONAL"
    if rel.startswith("include/object/") and RE_OBJECT_VT.match(stem):
        return "PLACEHOLDER"
    if rel in ALLOWLIST:
        return "NAMED"
    return "NAMED-PROVEN"


def scan():
    headers = []
    for path in sorted(INCLUDE.rglob("*.hpp")):
        rel = path.relative_to(ROOT).as_posix()
        text = path.read_text(encoding="utf-8", errors="replace")
        stem = path.stem
        lines = text.splitlines()
        n_fields = sum(1 for l in lines if RE_FIELD.search(l))
        gaps = len(re.findall(r"unproven gap|no ctor evidence", text, re.I))
        anchors = []
        for m in RE_ANCHOR.finditer(text):
            label = re.sub(r"\s+", "", m.group(1).lower())
            addr = m.group(2).lower()
            entry = f"{label} {addr}"
            if entry not in anchors:
                anchors.append(entry)
        tags = [t for t in TAGS if re.search(re.escape(t), text, re.I)]
        vptr = next((a.split()[-1] for a in anchors if a.startswith("vptr")), "")
        ctor = next((a.split()[-1] for a in anchors if a.startswith("ctor")), "")
        headers.append({
            "path": rel,
            "dir": str(path.parent.relative_to(INCLUDE)),
            "name": stem,
            "status": classify(rel, stem, text, n_fields),
            "fields": n_fields,
            "gaps": gaps,
            "vptr": vptr,
            "ctor": ctor,
            "anchors": anchors,
            "tags": tags,
        })
    return headers


def pct(part, total):
    return round(100.0 * part / total, 1) if total else 0.0


def write_md(headers):
    now = datetime.now().strftime("%Y-%m-%d %H:%M")
    totals = {s: sum(1 for h in headers if h["status"] == s) for s in STATUS_ORDER}
    total = len(headers)
    out = [
        "# Header coverage report",
        "",
        f"Generated {now} by `tools/coverage_report.py` — {total} headers.",
        "",
        "| Status | Headers | % |",
        "|---|---:|---:|",
    ]
    for s in STATUS_ORDER:
        out.append(f"| {s} | {totals[s]} | {pct(totals[s], total)} |")
    green = totals["NAMED-PROVEN"] + totals["NAMED"]
    out += [
        f"| **Green (NAMED + NAMED-PROVEN)** | **{green}** | **{pct(green, total)}** |",
        "",
        "Legend: NAMED-PROVEN = semantic name + cited extent; NAMED = semantic "
        "name, extent pending (allowlist); PROVISIONAL = name flagged or generic "
        "Vt* outside object/; PLACEHOLDER = generic Vt<addr> under object/; "
        "DOCBLOCK-ONLY = no fields.",
        "",
    ]
    dirs = sorted({h["dir"] for h in headers})
    out += ["| Directory | Total | " + " | ".join(STATUS_ORDER) + " | Green % |",
            "|---|---:|" + "---:|" * (len(STATUS_ORDER) + 1)]
    for d in dirs:
        hs = [h for h in headers if h["dir"] == d]
        row = {s: sum(1 for h in hs if h["status"] == s) for s in STATUS_ORDER}
        g = row["NAMED-PROVEN"] + row["NAMED"]
        out.append(
            f"| {d} | {len(hs)} | " + " | ".join(str(row[s]) for s in STATUS_ORDER)
            + f" | {pct(g, len(hs))} |"
        )
    (ROOT / "COVERAGE.md").write_text("\n".join(out) + "\n", encoding="utf-8")


HTML_TMPL = """<!DOCTYPE html>
<html lang="en"><head><meta charset="utf-8">
<title>MK8DX-Headers coverage treemap</title>
<style>
body{margin:0;font:13px/1.4 system-ui,sans-serif;background:#14161a;color:#ddd;overflow:hidden}
#bar{padding:8px 12px;background:#0c0d10;position:fixed;top:0;left:0;right:0;z-index:10;display:flex;gap:10px;align-items:center;border-bottom:1px solid #2a2d33}
.leg{display:inline-flex;align-items:center;gap:5px;cursor:pointer;padding:2px 8px;border-radius:10px;border:1px solid transparent;user-select:none}
.leg.off{opacity:.25}
.sw{width:11px;height:11px;border-radius:2px;display:inline-block}
#hint{color:#889;margin-left:auto;font-size:11px}
#msg{color:#8f8}
svg{display:block;cursor:grab}
svg.panning{cursor:grabbing}
rect{stroke:#14161a;stroke-width:1;cursor:pointer}
rect:hover{stroke:#fff;stroke-width:2}
text{pointer-events:none;font:10px system-ui;fill:#000}
#tip{position:fixed;display:none;background:#000d;color:#fff;padding:8px 10px;border-radius:4px;max-width:440px;pointer-events:none;z-index:9;white-space:pre-wrap}
</style></head><body>
<div id="bar">
<b>MK8DX-Headers coverage</b>
<span class="leg" data-s="NAMED-PROVEN"><span class="sw" style="background:#3fb950"></span>named-proven</span>
<span class="leg" data-s="NAMED"><span class="sw" style="background:#d29922"></span>named</span>
<span class="leg" data-s="PROVISIONAL"><span class="sw" style="background:#f0883e"></span>provisional</span>
<span class="leg" data-s="PLACEHOLDER"><span class="sw" style="background:#a371f7"></span>placeholder</span>
<span class="leg" data-s="DOCBLOCK-ONLY"><span class="sw" style="background:#57606a"></span>docblock-only</span>
<span id="msg"></span>
<span id="hint">scroll = zoom &middot; drag = pan &middot; dblclick = reset &middot; click tile = copy path &middot; click legend = filter</span>
</div>
<svg id="tm"></svg><div id="tip"></div>
<script>
const DATA = __DATA__;
const COLOR={"NAMED-PROVEN":"#3fb950","NAMED":"#d29922","PROVISIONAL":"#f0883e","PLACEHOLDER":"#a371f7","DOCBLOCK-ONLY":"#57606a"};
const svg=document.getElementById('tm'),tip=document.getElementById('tip'),msg=document.getElementById('msg');
const world=document.createElementNS('http://www.w3.org/2000/svg','g');
svg.appendChild(world);
function worstOf(row,side,total){const s=row.reduce((a,r)=>a+r.w,0);const thick=side*s/total;let worst=1e9;for(const r of row){const len=r.w/s*side;const a=len/thick;worst=Math.min(worst,Math.max(a,1/a));}return worst;}
function layout(items,x,y,w,h){
 if(!items.length)return[];
 if(items.length===1)return[{it:items[0],x,y,w,h}];
 const total=items.reduce((s,i)=>s+i.w,0);
 items=items.slice().sort((a,b)=>b.w-a.w);
 let i=0,rest=total,xx=x,yy=y,ww=w,hh=h,out=[];
 while(i<items.length){
  const row=[items[i]];let rowSum=items[i].w;i++;
  const horiz=ww<hh;
  while(i<items.length){
   const cur=worstOf(row,horiz?ww:hh,total);
   row.push(items[i]);
   if(worstOf(row,horiz?ww:hh,total)>cur){row.pop();break;}
   rowSum+=items[i].w;i++;
  }
  const frac=rowSum/rest;
  if(horiz){const rh=hh*frac;let rx=xx;for(const r of row){const rw=ww*r.w/rowSum;out.push({it:r,x:rx,y:yy,w:rw,h:rh});rx+=rw;}yy+=rh;hh-=rh;}
  else{const rw=ww*frac;let ry=yy;for(const r of row){const rh=hh*r.w/rowSum;out.push({it:r,x:xx,y:ry,w:rw,h:rh});ry+=rh;}xx+=rw;ww-=rw;}
  rest-=rowSum;
 }
 return out;
}
let visible=DATA.slice(),tiles=[];
function render(){
 world.innerHTML='';
 const W=innerWidth,H=innerHeight-38;
 svg.setAttribute('width',W);svg.setAttribute('height',H+38);
 tiles=layout(visible,0,38,W-4,H-4);
 for(const t of tiles){
  const it=t.it;
  const r=document.createElementNS('http://www.w3.org/2000/svg','rect');
  r.setAttribute('x',t.x);r.setAttribute('y',t.y);r.setAttribute('width',Math.max(t.w-1,.5));r.setAttribute('height',Math.max(t.h-1,.5));
  r.setAttribute('fill',COLOR[it.status]||'#888');
  r.addEventListener('mousemove',e=>{tip.style.display='block';tip.style.left=(e.clientX+14)+'px';tip.style.top=(e.clientY+14)+'px';
   tip.textContent=`${it.path}\nstatus: ${it.status}\nfields: ${it.fields}  gaps: ${it.gaps}`+
    (it.vptr?`\nvptr: ${it.vptr}`:'')+(it.ctor?`\nctor: ${it.ctor}`:'')+
    (it.anchors.length?`\nanchors: ${it.anchors.slice(0,8).join(', ')}${it.anchors.length>8?' …':''}`:'')+
    (it.tags.length?`\ntags: ${it.tags.join(', ')}`:'');});
  r.addEventListener('mouseleave',()=>tip.style.display='none');
  r.addEventListener('click',e=>{e.stopPropagation();const done=()=>{msg.textContent='— copied '+it.path;setTimeout(()=>msg.textContent='',1500);};
   if(navigator.clipboard){navigator.clipboard.writeText(it.path).then(done).catch(()=>fallback(it.path,done));}else fallback(it.path,done);});
  world.appendChild(r);
  if(t.w>52&&t.h>16){const tx=document.createElementNS('http://www.w3.org/2000/svg','text');
   tx.setAttribute('x',t.x+4);tx.setAttribute('y',t.y+13);tx.textContent=it.name.slice(0,Math.floor(t.w/6.2));world.appendChild(tx);}
 }
}
// zoom & pan
let scale=1,tx=0,ty=0;
function apply(){world.setAttribute('transform',`translate(${tx},${ty}) scale(${scale})`);}
svg.addEventListener('wheel',e=>{e.preventDefault();const k=e.deltaY<0?1.2:1/1.2;const ns=Math.min(40,Math.max(.2,scale*k));
 const mx=e.clientX,my=e.clientY-0;tx=mx-(mx-tx)*(ns/scale);ty=my-(my-ty)*(ns/scale);scale=ns;apply();},{passive:false});
let drag=null;
svg.addEventListener('mousedown',e=>{drag={x:e.clientX,y:e.clientY,tx,ty};svg.classList.add('panning');});
addEventListener('mousemove',e=>{if(!drag)return;tx=drag.tx+e.clientX-drag.x;ty=drag.ty+e.clientY-drag.y;apply();});
addEventListener('mouseup',()=>{drag=null;svg.classList.remove('panning');});
svg.addEventListener('dblclick',()=>{scale=1;tx=0;ty=0;apply();});
// legend filter
document.querySelectorAll('.leg').forEach(el=>{
 el.addEventListener('click',()=>{const s=el.dataset.s;el.classList.toggle('off');
  const off=new Set([...document.querySelectorAll('.leg.off')].map(e=>e.dataset.s));
  visible=DATA.filter(d=>!off.has(d.status));render();});
});
function fallback(s,done){const ta=document.createElement('textarea');ta.value=s;document.body.appendChild(ta);ta.select();try{document.execCommand('copy');done();}catch(e){}ta.remove();}
addEventListener('resize',()=>render());
render();
</script></body></html>
"""


def write_html(headers):
    data = [
        {
            "path": h["path"],
            "name": h["name"],
            "status": h["status"],
            "w": max(h["fields"], 1),
            "fields": h["fields"],
            "gaps": h["gaps"],
            "vptr": h["vptr"],
            "ctor": h["ctor"],
            "anchors": h["anchors"],
            "tags": h["tags"],
            "color": STATUS_COLORS[h["status"]],
        }
        for h in headers
    ]
    payload = json.dumps(data).replace("</", "<\\/")
    html_text = HTML_TMPL.replace("__DATA__", payload)
    (ROOT / "coverage.html").write_text(html_text, encoding="utf-8")


def main():
    headers = scan()
    write_md(headers)
    write_html(headers)
    totals = {s: sum(1 for h in headers if h["status"] == s) for s in STATUS_ORDER}
    print(f"{len(headers)} headers: " + ", ".join(f"{s}={totals[s]}" for s in STATUS_ORDER))
    print("COVERAGE.md + coverage.html written")


if __name__ == "__main__":
    main()
