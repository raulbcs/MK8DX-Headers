# object::Vt12cda08

PLACEHOLDER name (identity not proven). vptr 0x12cda08, 32 slots.
GOT cell 0x1310ce0 holds vt-0x10 (addend 0x12cd9f8); installed vptr = cell+0x10. All 32 slots are
absent from config/functions.csv (unrecovered). Game-side wrapper around `nn::prepo`
(the ctor calls `nn::prepo::Initialize` via PLT).

## Member notes

- [this+0x08] u32 count — written by the ctor's setup loop (0x84C158).
- [this+0x10] zeroed (0x84C054-0x84C058); [this+0x18] array ptr — allocated and grown in the ctor loop (stores at 0x84C08C and 0x84C12C); [this+0x20] second array ptr (0x84C0FC).
- size 0x28 lower bound — max direct field store is +0x20; the object also owns dynamically allocated arrays, exact size unverified; header cites 0x30 as the lower bound.

## Construction / init order

- C1 FUN_710084c024 (0x84C024): stores vptr 0x12cda08 at [this] (0x84C034-0x84C048), zeroes +0x08..+0x20, calls `nn::prepo::Initialize` (0x84C05C), then w22 = arg-1 and a conditional setup loop fills +0x18/+0x20 arrays and the +0x08 count.
- Slot +0x00 = 0x38FEDC — plain `ret`.
- Slot +0x08 = 0x84C1D4 — deleting dtor: tail `b operator delete` (trivial cleanup).
- Slots +0x10..+0xF0 = `ret` stubs (0x84C1D8-0x84C248); slot +0xF8 = 0x84C188 (real function, unverified).
- The all-stub slot table indicates a pure interface / no-op-override holder.
