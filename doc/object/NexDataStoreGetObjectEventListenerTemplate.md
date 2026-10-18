# object::NexDataStoreGetObjectEventListenerTemplate

nn::nex::DataStoreGetObjectEventListenerTemplate<unsigned int> (RTTI
typeinfo record 0x12f84b0, mangled name at 0xf89da0
"N2nn3nex39DataStoreGetObjectEventListenerTemplateIjEE").

- Member notes: vtable record 0x12f8468 = [typeinfo 0x12f84b0][5 slots
  0xb3fd50, 0xb3fd54, 0xb3fd58, 0xb3fd9c, 0xb3fdac]; vptr = 0x12f8478.
  Slots 0-2 are tiny thunks inside FUN_7100b3fd40 (+0x10/+0x14/+0x18);
  all five bodies unrecovered. Secondary vptr 0x12f7d48 at +0x08 (base
  nex listener, cell 0x1315d38 holds 0x12f7d58). mOwner/mEntry tie the
  listener to the allocating object's request array.
- Size 0x48, exact: operator new 0x48 at 0xb2f450 (FUN_7100b2f270),
  all fields written by the inline construction at 0xb2f47c-0xb2f4b0
  (+0x20 byte, +0x28/+0x30 qwords, +0x38 word, +0x3c halfword, +0x40
  word). Stored into owner+0x4e8.

## Construction / init order

1. FUN_7100b2f270: new 0x48 (0xb2f450).
2. [x8+0] = {vptr 0x12f8478, entry}; [x8+0x10] = {owner+0xc0,
   secondary vptr 0x12f7d48} (0xb2f4a0-0xb2f4b0).
3. Scalar fields +0x20..+0x40; handle stored to owner+0x4e8 (0xb2f4b4).
