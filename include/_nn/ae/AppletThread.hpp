#pragma once

#include <cstdint>

namespace nn::ae
{
    // AppletThread — PROVISIONAL name (SDK/glue). Base of the applet-thread
    // family (vtable slot 0x10 = 0x3dcf30; 33 live vtables, census cluster
    // c3dcf30). Shared ctor 0x7100628a54(this, name&vtable, 0, id, 0,
    // 0x7fffffff, attrFlags, 0x20) receives the vptr + rodata name through
    // a stack pair and the attr flags in w6 (0x2000/0x4000/0x1000 per
    // subclass); shared member-init 0x7100628f3c(this).
    //
    // Known subclasses (all constructed in-place inside AppletThreadHost,
    // ctor 0x7100872004): Controller 0x12d0348, Keyboard 0x12d0228,
    // OfflineWeb 0x12d03e8, MiiEdit 0x12d0488, Error 0x12d0528,
    // Nifm 0x12d05c8, NSA 0x12d0668.
    //
    // Base-class vtable: 0x12b0a58 (cell 0x130d448, n=16; built by the
    // shared ctor 0x7100628a54 itself — site 0x628aa4).
    class AppletThread
    {
    public:
    void* vptr;            // 0x00 — 0x12b0a58 for the base class
                           // (subclass extents 0xf8-0x548; shared map pending)
    };
}
