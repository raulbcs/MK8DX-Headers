# Vt12ca6f0 (object::Vt12ca6f0)

PLACEHOLDER name. Float-default parameter node used as an embedded member in
~28 caller ctors (bl 0x803d24 at 0x1b01a8, 0x1b6464, 0x1b7664, ... 0x378e10).

- Identity: no RTTI; vptr 0x12ca6f0 installed from GOT cell 0x13104d0
  (RELATIVE addend 0x12ca6e0 = vt-0x10; init does `ldr cell; add #0x10; str
  [x0]`).
- Size: init 0x803d24 writes [x0]=vptr, [x0+8]=arg x1, zeroes 0x40..0x4f
  (`stp xzr,xzr,[x0,#0x40]`) and 0x4e..0x55 (`stur xzr,[x0,#0x4e]`) —
  size >= 0x56. No operator-new site found; upper bound unverified.

## Construction / init order

In-place init only (0x803d24): vptr store, param pointer to +0x8, then the
0x40..0x55 clear. Fields 0x10..0x3f are filled by each caller ctor after the
call (unverified per-caller layout).

## Slots

- slot 0: 0x804000 (0xfc bytes) — largest method; reads int fields 0x10..0x2c
  and float/vector fields 0x18..0x30 of its x1 object, computes fmul/fadd
  chains and calls [ctx+0x10] vtable slot +0x18 (transform-style update).
- slot 1: 0x1c5904 — guarded static accessor (`__cxa_guard_acquire`, returns
  singleton built from cell 0x12fe548/0x12fe550).
- slots 2-7: float default getters returning constants — 0.5 (0x803cdc),
  0.25 (0x803ce4), ~0.1775 (0x803cec <- 0xed5ee4), 0.4 (0x803cf8 <-
  0xed58e8), ~0.35 (0x803d04 <- 0xed5a8c), 1.2 (0x803d10 <- 0xed5974).
- slot 8: 0x803d1c — returns 1.
- slots 9, 10: null.
- slot 11: 0x8045c0; slot 12: 0x8046c0 (0x172); slot 13, 14: null;
  slot 15: 0x80476c (0x1ec); slot 16: 0x8077a8 (0x180); slot 17, 18: null;
  slot 19: 0x804958 (0x1d0); slot 20: 0x804b28 (0x172); tail slots null.

All slot functions are unrecovered FUN_*; methods take (ctx, this) — x0 is an
external context object with fields +0x8/+0x10/+0x30, not the node itself.
