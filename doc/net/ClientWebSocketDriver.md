# object::ClientWebSocketDriver

RTTI-CONFIRMED: nn::nex::ClientWebSocketDriver. Typeinfo record 0x12e2640
(name 0xf83990, base 0x12e2620 = nn::nex::WebSocketDriver); the typeinfo
pointer sits at vptr-8 = 0x12e25a0, so tools/vt_ctors.tsv's "0x12e25a0" is
the typeinfo slot, not the fn row. Installed vptr = 0x12e25a8
(cell 0x13141d8 holds 0x12e2598 = row-0x10; sites add +0x10).

## Identity

- Init sites (all store vptr then Socket base vptr, then branch to base init
  0x5790b4): 0x9d68e8 (slot 0) and 0x9dfbe4 (slot 8, full C1 with frame that
  also tails 0x573f48). The vtable's own first two slots are these
  initializer thunks — a D0/D2 pair was not found (unverified whether the
  driver uses base dtors only).
- Singleton init 0x9e26d4: global struct at 0x13613f8 (via GOT cell
  0x1314280) receives the vptr at +0x00, Socket vptr 0x128c698 at +0x10,
  zero byte +0x18, self ptr +0x28 -> +0x18, 0x10 at +0x30.

## Member notes

- [this+0x10] — nn::nex::Socket secondary vptr 0x128c698 (GOT cell 0x130b4a8
  -> row 0x128c688). Socket typeinfo 0x12e26a0 (name 0xf83a40).
- Inner class nn::nex::ClientWebSocketDriver::ClientWebSocket (typeinfo
  0x12e2660, name 0xf839e0): 0x28-byte object built by 0x9dfc44 — Socket
  vptr at +0, byte +8, self-ptr +0x18 -> +8, 0x10 at +0x20.
- Slots: slot 2 0x9d5d74 (288 B), slot 4 0x9d5e94 (472 B); all other targets
  (0x9d68e8, 0x9dfbe4, 0x9d5e7c, 0x9dfba8, 0x9dfbb0, 0x9dfc28, 0x9dfc34,
  0x9dfc3c, 0x9dfc44, 0x9dfc70-0x9dfc7c) unrecovered in functions.csv.
- Extent: deepest proven store is +0x30 (=0x10); no operator-new site found
  for the driver itself (constructed into the 0x13613f8 singleton and via
  vtable-dispatched initializers). size 0x40 is a lower bound, unverified.

## Construction / init order

- Initializer thunks 0x9d68e8 / 0x9dfbe4: primary vptr -> [this], Socket
  vptr -> [this+0x10], base init 0x5790b4.
- Singleton: lazy guard at 0x1361400 (byte flag via 0x9e26dc), fields as
  listed above (0x9e26c8-0x9e2710).
