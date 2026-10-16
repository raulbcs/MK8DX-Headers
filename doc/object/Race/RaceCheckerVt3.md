# object::RaceCheckerVt3

Checker-family member: vtable .data 0x12d0e78 (GOT cell 0x1311120), ctor 0x7100882db0, D1 0x882e48, D0 0x882e88. Single allocation site in the checker graph init (new[](0x70, nothrow) at 0x87e030; back-ptr 0x28/0x30 wired by the creator like the other family members).

Custom RTTI: dynamic typeinfo 0x882ad4 (`ldr x8,[x0,#0xb8]; ldr w0,[x8,#0xc]; ret`) — NOT a stub; the per-object id lives in a channel-family field, so ids are shared across the group of 5 vtables (0x1261178/0x12612d8/0x1261438/0x1261598 secondary bases).

The ctor allocates a 0x38 recorder channel sub-object and stores it at +0x68; both dtors delete it and tail-jump to the Actor dtor. Channel layout (built inline at 0x882dd8-0x882e38):

```
+0x00 vptr        (GOT cell 0x1311228 — recorder channel subclass)
+0x08 fn ptr      (GOT cell 0x12fae28)
+0x10 name        "" (rodata 0xed6af8, empty string)
+0x18 vptr 2      (GOT cell 0x1311130 — secondary base)
+0x20 owner       this
+0x28 0x78
+0x30 1
```

## Construction / init order

1. Allocation 0x87e030: operator new[](0x70, nothrow); creator wires back-ptrs at +0x28/+0x30.
2. Ctor 0x7100882db0: zeroed fields 0x38/0x40/0x48 and 0x50..0x67; builds the 0x38 recorder channel inline (0x882dd8-0x882e38, layout above) and stores it at +0x68.
3. D1 0x882e48 / D0 0x882e88: delete the +0x68 channel, tail-jump to the Actor dtor.
