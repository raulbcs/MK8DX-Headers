#pragma once

#include <cstdint>

#include <basis/seadTypes.h>
#include <stream/seadStream.h>

/*
* Layout reference (32-bit era; offsets re-derived for the 64-bit binary):
* https://github.com/EpicUsername12/mk8-cafeloader-ctcode/blob/2dd1c7d0ef0c547d7df51aaf5e32b3d9a1f764f1/include/mk8/enl/Stream.h
*/

namespace enl
{
    class RamWriteStream : public sead::WriteStream {};
    class RamReadStream : public sead::ReadStream {};
} // namespace enl