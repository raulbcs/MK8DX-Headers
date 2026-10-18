# object::Vt12bff30

PLACEHOLDER name (identity not proven). vptr 0x12bff30, 16 slots, no RTTI. GOT cell 0x130ed20 = vptr-0x10; C1 stores cell+0x10 into [this] (0x7440ec-0x744100).

## Member notes

- Size 0x48 PROVEN: operator new(0x48, 8) at 0x735e1c-0x735e2c before C1 call 0x7440b8 (second caller 0x8c729c).
- C1 0x7440b8(this, x1, x2): +0x08 = x1, +0x10 = x2, then three embedded sentinel nodes: {+0x18,+0x20} = {this+0x18, this+0x18}, {+0x28,+0x30} = {this+0x28, this+0x28}, {+0x38,+0x40} = {this+0x38, this+0x38} (0x7440e0-0x744100) — three empty intrusive lists.
- Slot1 0x744114 (D1) re-installs the vptr (0x744138-0x744140), destroys each list element ([node+0x28] payload via operator delete 0x5a0978, 0x74414c-0x744168), then member dtors 0xa6e540/0xa6e978, tail 0xa6e84c; slot2 0x7441bc is the D0 clone (same body minus the final delete).

## Construction / init order

- C1 = 0x7440b8; heap path new(0x48) at 0x735e1c with x1 = [x20+0x20]+0xb10 cell, x2 = [cell 0x130eb38]. Recovered slots: slot1 0x744114, slot2 0x7441bc, slot5 0x7448b4, slot6 0x7444ec, slot10 0x744604, slot11 0x744638, slot13 0x744924; slot0 0x744e64 and remaining (0x7447a8, 0x74482c, 0x744ef4-0x744f20, 0x744724, 0xa6e868, 0x744afc) unrecovered.
