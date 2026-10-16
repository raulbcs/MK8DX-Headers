# gear::UILoader

Total size 0xA0. Unproven — Switch ctor is in the binary but not yet located (no RTTI, stripped binary); extent fixed by mTextureMap at 0x30.

## Member layout

- 0x00 — 0x30 — unproven (extent fixed by mTextureMap at 0x30)
- 0x30 — mTextureMap (sead::StrTreeMap<64, void*>)
- 0x50 — mTextureCount
- 0x54 — mMaxTextures
