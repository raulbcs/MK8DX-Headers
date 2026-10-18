# nn::nex::NATTraversalReportInternalProtocolClient

## Identity

- nex RTTI record at 0x12f6040: name
  `"N2nn3nex40NATTraversalReportInternalProtocolClientE"`, base record
  0x12e62e0 = `nn::nex::ClientProtocol`.
- Assigned tsv row 0x12f5d88 is the nex-record slot; table head:
  0x12f5d80 = 0 (offset-to-top), 0x12f5d88 = record pointer,
  vptr = 0x12f5d90.
- vptr convention: GOT cell 0x1315880 holds 0x12f5d80 (vt-0x10, RELA addend);
  installed vptr = cell + 0x10 = 0x12f5d90.

## Member notes

- Size 0x90 (own D0 0xb179f8: `mov w0, #0x90; bl 0x573f04`); no own fields
  beyond ClientProtocol.
- No standalone C1 found: the vptr is only materialized inlined —
  (a) inside the NATTraversalRelayProtocolImpl D0 0xb16948 (new 0x130): the
  Impl embeds this class at +0x98 — ClientProtocol C1 0xa27e78(+0x98, 1) at
  0xb169a8, then vptr 0x12f5d90 stored at [this+0x98] (0xb169ac..0xb169c0);
  the same Impl also heap-allocates a NATTraversalProtocolClient (new 0x90,
  C1 0xb16a50 with cmd 3) and stores the pointer at +0x90;
  (b) the same inlined sequence inside the relay composite ctor around
  0xb15d5c..0xb15d7c;
  (c) its own D0 0xb179f8 site 0xb17a24 (heap path, cmd 1).
- Slot0 = shared complete-dtor thunk 0xa3045c (0x456 bytes): re-installs the
  nn::nex::Protocol vptr (cell 0x13140930 + 0x10) and releases the refcounted
  member at +0x88. Slot1 = 0xb179d4 (D2: 0xa3045c then operator delete
  0x573f48), slot2 = 0xb179f8 (D0/factory).
- 24 vtable slots at 0x12f5d90..0x12f5e50 (slot23 = 0xa287c0). The record at
  0x12f5e50 (`_Proto_NATTraversalProtocolServer`, base ServerProtocol
  0x12e6300) is a separate class record, not extra slots.

## Construction / init order

1. (embedded path, 0xb16948) owner `operator new(0x130)`; Impl base ctor
   0xa2df70; Impl vptr 0x12f5e78 at +0 (cell 0x1315878 + 0x10).
2. inner `operator new(0x90)` (0xb1697c) -> NATTraversalProtocolClient C1
   0xb16a50(x, 3) -> stored at owner +0x90.
3. ClientProtocol base ctor 0xa27e78(this+0x98, 1) (0xb169a8).
4. vptr = cell 0x1315880 + 0x10 -> 0x12f5d90 at [owner+0x98]
   (0xb169ac..0xb169c0).
