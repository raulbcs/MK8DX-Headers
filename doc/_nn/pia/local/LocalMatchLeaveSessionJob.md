# nn::pia::local::LocalMatchLeaveSessionJob

## Identity

RTTI-named: typeinfo data 0x12e1cb0, name "N2nn3pia5local25LocalMatchLeaveSessionJobE" (string 0xf83690). Typeinfo-slot row at 0x12e1c20 (offset-to-top 0 at 0x12e1c18; typeinfo slot -> 0x12e1cb0); installed vptr 0x12e1c28. GOT cell 0x1314108 holds 0x12e1c18 (vptr - 0x10). 17 virtual slots (0x12e1c28-0x12e1ca8). No secondary vtable.

## Member notes

- Slot 0 = C2 0x9d282c (tail 0x9850a4), slot 1 = D1 0x9d2844 (0x9850a4 then operator delete 0x60b470). Slots 2/3 = 0xb4a654/0xb4a67c (shared pia job-interface pair), slot 4 = 0x933314; slots 6-9/12-13/15-16 use the 0x985xxx stub cluster shared with nn::pia::lan::LanMatchLeaveSessionJob.
- this+0x98: C1 second argument (x1) stored verbatim (0x9d2814).

## Construction / init order

- Factory 0x9c3eb8: operator new(0xa0) via 0x568aa0, then C1 0x9d27f4(this, x1 = factory's saved global) — size 0xa0 proven (0x9c3ed8-0x9c3ef0).
- C1 order: base 0x985060 -> arg store @0x98 -> vptr 0x12e1c28 (0x9d2808-0x9d281c).
