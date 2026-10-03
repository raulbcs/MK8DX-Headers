#pragma once

#include "DestroySessionJob.hpp" // SessionObject

#include <cstdint>

namespace nn::pia::session
{
    // nn::pia::session::LeaveSessionJob — state machine steps (same job
    // framework as DestroySessionJob).
    class LeaveSessionJob : public SessionObject
    {
        public:
            virtual void slot30(); //0x30 — state transition, invoked from SendMonitoringData

            struct Result
            {
                void* a;
                void* b;
            };
            char pad08[0x28]; // 0x08
            Result m30;       // {ptr, null} — step result
            const char* m40;  // step name (MethodTree string)
            char pad48[0x48]; // 0x48
            unsigned long m90; //0x90 — start tick of the current step

            // 64-bit return
            uint64_t SendMonitoringData() asm("nn::pia::session::LeaveSessionJob::SendMonitoringData");
            uint64_t CompleteProcess() asm("LeaveSessionJob::CompleteProcess");
    };
}
