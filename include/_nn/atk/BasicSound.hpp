#pragma once

// Vtable of nn::atk::detail::BasicSound (RTTI-confirmed: typeinfo mangled
// name N2nn3atk6detail10BasicSoundE, ti object 0x12ae080), vptr 0x12ae020,
// n=5.
//
// NOT declared as a class here on purpose: vendor/nnheaders already declares
// nn::atk::detail::BasicSound (include/nn/atk/detail/BasicSound.h) and a
// second declaration would clash. This header only pins the binary vtable
// layout so the vtable census finds the vptr address citable.
//
// Slots: +0x00 0x5e2298, +0x08 0x5e229c (dtor pair), +0x10 0x5e22b8,
// +0x18 0x5e1260, +0x20 0x5e13cc — the base-class table; concrete sound
// runtime classes (Sequence/Wave/Stream, see vendor headers) override it.
//
// Consumers: 10 materialization sites in the atk sound-driver region
// 0x5e483c..0x5e7xxx (FUN_71005e483c and the BasicSound method family
// behind it — Pause/Mute/Start helpers operate on these objects).
namespace nn::atk::detail {
struct BasicSoundVtablePlaceholder;
}
