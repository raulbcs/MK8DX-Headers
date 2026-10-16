# gear::ByamlIter

Unproven — pointer-sized fields whose setters live in the unlocated ByamlIter ctors (this class has no RTTI and the binary is stripped). Byaml-pointer-shaped, but semantics not proven.

## Member layout

- 0x00 — mPad00 — unproven, pointer-shaped, setter ctor not located
- 0x08 — mPad08 — unproven, pointer-shaped, setter ctor not located
