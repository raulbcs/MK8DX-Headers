#pragma once

#include <cstdint>

#include <_nn/nex/CallContext.hpp>

namespace nn::nex
{
    class Credentials;

    class ProtocolCallContext : public CallContext
    {
    public:
        uint8_t mPad30[0x88];         //0x30 — unproven padding
        Credentials* mCredentials;    //0xB8

        ProtocolCallContext(Credentials* creds);
        ~ProtocolCallContext();
    };
}
