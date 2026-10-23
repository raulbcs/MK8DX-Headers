#pragma once

#include <cstdint>

namespace nn::pia::session {
// nn::pia::session::LeaveSessionJob — RTTI-named (typeinfo 0x12ddf40, name
// "N2nn3pia7session15LeaveSessionJobE"); base of several derived pia session
// jobs. 17 slots; GOT cell 0x13137f0 holds vptr-0x10 (vptr 0x12ddeb8).
// extent 0x98 (lower bound) - details: doc/_nn/pia/session/LeaveSessionJob.md
class LeaveSessionJob {
 public:
  void* mVtable;          // 0x00 - vptr 0x12ddeb8 (cell 0x13137f0 + 0x10)
  uint8_t mPad08[0x28];   // 0x08 - job-base fields (cf. JoinMeshJob)

  struct Result {
    void* a;
    void* b;
  };
  Result m30;             // 0x30 - {ptr, null} step result
  const char* m40;        // 0x40 - step name (MethodTree string)
  uint8_t mPad48[0x18];   // 0x48 — unproven padding
  void* m60;              // 0x60 - 0x20-byte subobject (ctor 0x929ec0,
                          //   0x98508c); freed by 0x929ee0 in dtor path
  uint8_t mPad68[0x18];   // 0x68 - unproven
  void* m80;              // 0x80 - C1 stores 0 (0x985090)
  uint8_t mPad88[0x8];    // 0x88 - unproven
  uint64_t m90;           // 0x90 - start tick of the current step
                          //   (was: void* m90, C1 stores 0, 0x985094)

  virtual void slot30();  // 0x30 - state transition, invoked from SendMonitoringData

  // 64-bit return
  uint64_t SendMonitoringData() asm("nn::pia::session::LeaveSessionJob::SendMonitoringData");
  uint64_t CompleteProcess() asm("LeaveSessionJob::CompleteProcess");
};
}  // namespace nn::pia::session
