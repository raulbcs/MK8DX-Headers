# object::NexDataStoreCheckConsistencyEventListener

nn::nex::DataStoreCheckConsistencyEventListener (RTTI typeinfo record
0x12f8420, mangled name at 0xf89d20
"N2nn3nex45DataStoreCheckConsistencyEventListener").

- Member notes: vtable record 0x12f83d8 = [typeinfo 0x12f8420][5 slots
  0xb3fce8, 0xb3fcec, 0xb3fcf0, 0xb3fd30, 0xb3fd40]; vptr = 0x12f83e8.
  All five slot bodies are unrecovered FUN_*. Secondary vptr 0x12f7c88
  at +0x08 (base nex listener, cell 0x1315cd0 holds 0x12f7c78).
  mOwner/mEntry tie the listener to the allocating object's request
  array.
- Size 0x38, exact: operator new 0x38 at 0xb2d55c (FUN_7100b2d374),
  all fields written by the inline construction at 0xb2d58c-0xb2d5c4
  (+0x20 byte, +0x24 word, +0x28 qword, +0x30 word, +0x34/+0x36
  halfwords). Stored into owner+0x4e8.

## Construction / init order

1. FUN_7100b2d374: new 0x38 (0xb2d55c).
2. [x8+0] = {vptr 0x12f83e8, entry}; [x8+0x10] = {owner+0xc0,
   secondary vptr 0x12f7c88} (0xb2d5b4-0xb2d5c4).
3. Scalar fields +0x20..+0x36; handle stored to owner+0x4e8 (0xb2d5c8).
