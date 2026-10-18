# nn::pia::local::LocalMatchJoinSessionJob

RTTI-named (typeinfo 0x12e1c00, mangled "N2nn3pia5local24LocalMatchJoinSessionJobE"; base typeinfo 0x12ddc70 = nn::pia::session::JoinSessionJob). Typeinfo-slot variant: assigned row 0x12e1b60 is the typeinfo slot, offset-to-top 0 at 0x12e1b58, installed vptr = 0x12e1b68. GOT cell 0x13140d8 holds vptr-0x10 (0x12e1b58). 18 slots (vt+0x08..vt+0x98), all unrecovered in functions.csv.

Size 0x128: sole construction site 0x9c3ea4 (factory 0x9c3e6c) allocates 0x128 bytes via 0x568aa0.

## Member notes

- [this+0x08..0x117] — base JoinSessionJob region. Base C1 0x9823d8 (its vptr via GOT cell 0x1313760): zeroes +0x58, inits subobject at +0x60 via 0x929ec0 and +0x80 via 0x9b1fe8, zeroes +0xf8, byte +0x100, u32 +0x108, +0x110. Interior unverified.
- [this+0x118] u64 — zeroed by C1 0x9d2140 (stp low half).
- [this+0x120] void* — C1 stores its x1 argument; both dtors (0x9d2178/0x9d2190) zero it.

Slot map: slot0 = D1 0x9d2178 (zero +0x120, re-assert vptr, tail-call base dtor 0x98242c), slot1 = D0 0x9d2190 (same then operator delete 0x60b470); slot5 0x9d27f0, slot12 0x9d21c8 (starts by saving x8 = sPiaContext via cell 0x13123e0 and indexing [ctx+0x142]); remaining slots 0xb4a654, 0xb4a67c, 0x933314, 0x983248, 0x976ff4, 0x983158, 0x983180, 0x9831a4, 0x941184, 0x9831a0, 0x9d2744, 0x9d2788, 0x9d27b0, 0x9d27d0 — all unrecovered, override set unverified.

## Construction / init order

- Factory 0x9c3e6c: new(0x128) at 0x9c3e8c (0x568aa0), then C1 0x9d2140 at 0x9c3ea4 with x1 = value from global cell 0x1312638 through helper 0x563b70.
- C1 0x9d2140: base C1 0x9823d8 → [this+0x118]=0 → [this+0x120]=x1 → vptr install.
- D1/D0 both zero [this+0x120] before the base destroy chain (identical-code-folding clones sharing cell 0x13140d8).
