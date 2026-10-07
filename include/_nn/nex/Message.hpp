#pragma once

#include <cstdint>

#include <_nn/nex/ProtocolRequestBrokerInterface.hpp>

namespace nn::nex
{
    class Message : public ProtocolRequestBrokerInterface
    {
    public:
        // SDK-internal; no game-side ctor evidence (nn::nex lib layout;
        // extent 0x74 from the Wii U reference).
        uint8_t mPad1C[0x74]; 

        Message();
        ~Message();
        uintptr_t GetBuffer();
    };
}
