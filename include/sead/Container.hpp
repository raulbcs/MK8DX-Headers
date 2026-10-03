#pragma once

#include <cstdint>

// Container / CElem — generic sead containers.
// Container: ContainerArrayGetter (0x710000393c).
// CElem: ContainerAddNamedElem (0x71000a14ac).
// FrepObj: FrepRegister (0x7100828f70) — 0x28B sead registration object.
struct Container
{
    uint8_t pad_00[0x38]; // 0x00
    int count; //0x38
    int _q; //0x3c
    void** array; //0x40
};

struct CElem
{
    uint8_t pad_00[0x20]; // 0x00
    void* slot; //0x20
};

struct FrepObj
{
    char* a; //0x00
    unsigned int p2; //0x08
    unsigned int p3; //0x0c
    char* b; //0x10
    uint64_t x18; //0x18
    uint64_t x20; //0x20
};
