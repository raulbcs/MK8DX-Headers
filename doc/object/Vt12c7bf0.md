# object::Vt12c7bf0

PLACEHOLDER name. gear::Actor-derived double ring buffer: two
independent {count, capacity=3000, data} descriptors (helper 0x60B918)
with inline 3000 x 8 B entry arrays.

- Identity: allocated by FUN_7100398750 (0x398750, per-mode factory):
  new 0xBBD8 (0x398894), C1 FUN_71007D2FA4 (0x3988AC); self-ref
  [obj+0x18]; [obj+0x28] = manager+0x178; [obj+0x30] = [manager+0x1A8].
- GOT convention: cell 0x130ffd0 holds 0x12c7be0 = vt-0x10.
- Size proof: `mov w0, #0xbbd8` (0x398894) equals the computed tail
  0x5E18 + 3000*8 = 0xBBD8 exactly.
- Family: same factory as Vt12c5d70 / Vt12c7b20 / Vt12c7d08; same
  14-slot Actor-derived row shape.

## Member notes

- Row 0x12c7bf0 (14 slots): 0x7D3030 (D1, unrecovered), 0x7D30FC
  (136 B, D0), 0x7B978C (gear::Actor dtor — family pattern), 0x7D3158
  (unrecovered), 0x7A26C (4 B empty prepare override), 0x7D317C/
  0x7D3180 (unrecovered), stubs 0x1C6C/0x1C70/0x1C74/0x1C7C/0x1CBC,
  0x7B97A8 prepareOuter, 0x7B97B4 enterOuter.
- Entries are 8 B each; element type unknown (unverified).
- Counts at +0x38/+0x5E08 start at 0; capacities 3000 (0xBB8).

## Construction / init order

1. new 0xBBD8 (0x398894-0x3988AC).
2. gear::Actor base 0x7B976C (0x7d2fb4).
3. Primary vptr -> [this] (0x7d2fb8-0x7d2fc4).
4. Desc +0x38 {0, 3000, this+0x48} (0x7d2fcc-0x7d2fe0); zeros at
   +0x5E10/+0x5E08; desc +0x5E08 {0, 3000, this+0x5E18} (tail-call
   0x7d3008-0x7d300c).
