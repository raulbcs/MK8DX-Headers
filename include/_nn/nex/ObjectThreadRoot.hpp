#pragma once

#include <cstdint>

namespace nn::nex
{
    // Base-subobject vtable of nn::nex::ObjectThread<nn::WebSocketClient,
    // void> (adjacent typeinfo name string 0xf853f0:
    // N2nn3nex12ObjectThreadINS0_15WebSocketClientEPvEE; the vptr-0x8 slot
    // points at the nn::nex::ObjectThreadRoot typeinfo 0x128c550, so this is
    // the ObjectThreadRoot primary-base table). vptr 0x12e5928 (n=3).
    //
    // Sole consumption site 0xa25944 in FUN_7100a25930: materializes the
    // vptr, reads all three slots, then allocates a 0x1118-byte instance
    // (mov w0, #0x1118) and installs the table — the WebSocketClient
    // ObjectThread instantiation.
    //
    // Slots: 0xa26afc / 0xa26b20 / 0xa26b44 (ObjectThreadRoot virtuals:
    // dtor pair + one override; exact mapping pending).
    class ObjectThreadRoot
    {
    public:
        void* vtable;          // 0x00 — 0x12e5928 for the WebSocketClient instantiation
        // ObjectThread<WebSocketClient> is 0x1118 bytes; interior unmapped.
    };
}
