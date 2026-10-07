#pragma once

#include <cstdint>

// Baptism audit: the family itself is real (rodata thread names
// ControllerAppletThread/KeyboardAppletThread/... prove nn::ae), but the binary never names the base. SDK-glue name kept.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace nn::ae
{
 // AppletThread — PROVISIONAL name (SDK/glue). Base of the applet-thread
 // family (vtable slot 0x10 = 0x3dcf30; 33 live vtables in the cluster). Shared ctor 0x7100628a54(this, name&vtable, 0, id, 0,
 // 0x7fffffff, attrFlags, stackSize) receives the vptr + rodata name through
 // a stack pair and the attr flags in w6 (0x2000/0x4000/0x1000/0x10000 per
 // subclass); shared member-init 0x7100628f3c(this).
 //
 // Known subclasses (all constructed in-place inside AppletThreadHost,
 // ctor 0x7100872004): Controller 0x12d0348, Keyboard 0x12d0228,
 // OfflineWeb 0x12d03e8, MiiEdit 0x12d0488, Error 0x12d0528,
 // Nifm 0x12d05c8, NSA 0x12d0668.
 //
 // Base-class vtable: 0x12b0a58 (cell 0x130d448, n=16; built by the
 // shared ctor 0x7100628a54 itself — site 0x628aa4).
 //
 // Extent 0xf8: every mapped subclass starts its first own field at
 // 0xf8 and the shared strb flag lands at 0xf4. The 0x08..0xf4
 // interior is only touched by the shared member-init 0x628f3c —
 // internal SDK state (thread, event, message queue), unmapped.
 class AppletThread
 {
 public:
 void* vptr; // 0x00 — 0x12b0a58 for the base class
 uint8_t mOwn08[0xec]; // 0x08 — SDK-internal (thread/event/queue), map pending
 uint8_t mFlagF4; // 0xf4 — shared ctor strb zero
 uint8_t padF5[3]; // 0xf5 — unproven padding
 // (0xf8 total)
 };
}
