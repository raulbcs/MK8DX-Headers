# nn::pia::lan::LanMatchLeaveSessionJob

## Identity

RTTI-named: typeinfo data 0x12dcfb0, name "N2nn3pia3lan23LanMatchLeaveSessionJobE" (string 0xf80f60). Typeinfo-slot row at 0x12dcf20 (offset-to-top 0 at 0x12dcf18; typeinfo slot -> 0x12dcfb0); installed vptr 0x12dcf28. GOT cell 0x13135c0 holds 0x12dcf18 (vptr - 0x10). 17 virtual slots (0x12dcf28-0x12dcfa8). No secondary vtable.

## Member notes

- Slot 0 = C2 0x977dd4 (tail 0x9850a4), slot 1 = D1 0x977dd8 (0x9850a4 then operator delete 0x60b470). Slots 2/3 = 0xb4a654/0xb4a67c (shared pia job-interface override pair), slot 4 = 0x933314; slots 6-10/12-13/16 use the 0x985xxx stub cluster shared with nn::pia::local::LocalMatchLeaveSessionJob.
- C1 0x977da4 calls base ctor 0x985060, then stores the vptr — no other field stores, so the body beyond the vptr belongs to the base subobject (0x08..0x97).

## Construction / init order

- Factory 0x96d2c4: operator new(0x98) via 0x568aa0, then C1 0x977da4 — size 0x98 proven (0x96d2d8-0x96d2ec).
- C1 order: base 0x985060 -> vptr 0x12dcf28 (0x977db8-0x977dc4).
