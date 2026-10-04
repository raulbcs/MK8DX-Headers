#pragma once

namespace eui
{
    // Reference-only type: the binary never shows its layout (only used
    // as an opaque pointer parameter in eui::Screen vtable slots).
    class DrawInfoEx
    {
        public:
            class RenderBufferInfo;
    };
}
