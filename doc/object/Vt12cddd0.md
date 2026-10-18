# object::Vt12cddd0

PLACEHOLDER name (identity not proven). vptr 0x12cddd0, 45 slots. GOT cell 0x1310db8 holds vptr-0x10 (cell+0x10 = installed vptr; the row address IS the vptr).

Exactly 0x1D0 bytes (`new 0x1D0` at 0x38369C in the factory at 0x383608, result stored at [x19+0x240]).

## Member notes

- [this+0x00] vptr: C1 first stores base vptr 0x12cdf48 (cell 0x1310db0+0x10, 0x851418), then overrides with 0x12cddd0 (0x851438) after the member sub-ctor.
- [this+0x58] sub-object initialized by FUN_7100853148 (0x851420).
- [this+0x1C8] u16 = 0, [this+0x1CA] u8 = 0 (0x85142C-0x851430).
- Slot 44 = FUN_7100851448, a tiny tail-caller: loads vtable slot at +0x38 with (this, 0), then tail-calls slot +0xA0 (0x851448-0x851484) — forwarding helper.

## Construction / init order

- C1 = FUN_71008513F4: base init FUN_7100852F44 (0x851408), base vptr store (0x851418), sub-ctor at +0x58 (0x851420), final vptr override (0x851434-0x851438), trailing zero stores.
- Factory 0x383608: `new 0x1D0` (0x38369C), C1 (0x3836A8); the next allocation in the same factory is the 0x680 Vt12ceb70 object (0x3836AC-0x3836BC).
