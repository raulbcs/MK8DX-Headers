# MonitoringDataSendJob (nn::pia::inet::MonitoringDataSendJob)

- Typeinfo slot 0x12ddae0 -> typeinfo 0x12ddb30, name string 0xf81380
  "N2nn3pia4inet21MonitoringDataSendJobE". Primary vptr 0x12ddae8; GOT cell
  0x13136f0 holds 0x12ddad8 (vt-0x10, RELATIVE reloc).
- Size unverified; 0x90 is a lower bound (derived ctor store at +0x88).

## Identity

nn::pia::inet job class; abstract-ish base — no direct factory allocates it.
The only caller of its C2 is a derived-class ctor (0x710093f0e8, installs its
own vptr from runtime cell 0x1312d38) that extends the object to >=0x90.

## Slots

7 slots (0x12ddae8..0x12ddaf8+0x28): slot 0 = 0x710097f618 (D0: installs
vptr, finalizes the +0x68 subobject via 0x7100929ee0, tail 0x7100b4a62c ->
operator delete), slot 1 = 0x710097f64c (D1, same without delete), slots
2-4 = shared base wrappers 0x7100b4a654 / 0x7100b4a67c / 0x7100933314,
slot 5 = 0x710097f760 (unrecovered), slot 6 = 0x710097f704.

## Member notes

- 0x08..0x27 — common nn base inited by 0x7100567cb8 (unproven).
- 0x28 — base subobject vptr 0x12db168 (base ctor 0x7100b4a5e0 zeroes
  +0x30/+0x38/+0x40/+0x48b/+0x50).
- 0x58 — u32, C2 0x710097f5dc zeroes; 0x60 — pointer, zeroed.
- 0x68..0x87 — inline subobject: ctor 0x7100929ec0, dtor 0x7100929ee0
  (called from slot 0/1 with this+0x68). Layout unproven.

## Construction / init order

1. C2 0x710097f5dc: base ctor 0x7100b4a5e0 (which first runs 0x7100567cb8),
   then m58 = 0, m60 = 0, vptr 0x12ddae8 at [this], subobject ctor
   0x7100929ec0 at this+0x68.
2. Derived ctor 0x710093f0e8 (vptr 0x12dae98): calls C2, zeroes [x19+0x88],
   re-installs its own vptr. No separate C1/D1 pair out-of-line beyond the
   slot 0/1 entries above.
