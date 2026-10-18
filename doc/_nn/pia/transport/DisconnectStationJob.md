# nn::pia::transport::DisconnectStationJob

## Identity

- vtable row 0x12deca0 (tsv row = typeinfo slot), vptr 0x12deca8 = row + 8, 9 slots.
  GOT cell 0x1313af0 holds 0x12dec98 = vptr - 0x10 (offset-to-top 0x12dec98 = 0,
  typeinfo slot 0x12deca0 = 0x12decf0); installed vptr = cell + 0x10.
- RTTI: typeinfo 0x12decf0 = {0x10, name 0xf82160, base 0x12f8d30}; name =
  "N2nn3pia9transport20DisconnectStationJobE"; base =
  nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x9a2f04, 1 D0 0x9a2f08, 2 ret 0xb4a654, 3 ret 0xb4a67c,
  4 ret 0x933314, 5 `ret` 0x9a3358, 6 `ret` 0x9a335c, 7 0x9a2f38 (unrecovered).
- D1 0x9a2f04 is a tail call to 0xb4a62c (shared job-base D0; no member
  dtors). D0 0x9a2f08: base D0 then operator delete 0x60b470.
- extent 0x80 EXACT: operator new 0x80 (orr w0, #0x80) at 0x9a48a8-0x9a48bc,
  C1 0x9a2eb8 immediately after. The caller 0x937578 then overrides [this]
  with a further-derived vptr (cell 0x13120a30), so this class also serves as
  an in-place base (unverified identity of the deriving class).

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- +0x60 = 4000 and +0x78 = 500 look like timeout/interval constants (ms);
  semantics unverified.
- +0x68/+0x70 zeroed as a pair (stp xzr, xzr).

## Construction / init order

1. C1 0x9a2eb8: base C1 0xb4a5e0(this) (0x9a2ec8).
2. [this+0x58] = 0 (0x9a2ecc); [0x68]/[0x70] = 0 (0x9a2ed8).
3. vptr 0x12deca8 -> [this] (0x9a2eec, cell 0x1313af0 + 0x10).
4. [this+0x60] = 4000 (0x9a2ee4); [this+0x7c] byte = 0 (0x9a2ee8);
   [this+0x78] = 500 (0x9a2ef4).
