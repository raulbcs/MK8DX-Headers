#pragma once

#include <cstdint>

namespace nn::pia::session {
// Polymorphic base of the session components. Only the slots referenced by
// this unit have known semantics; the others keep the slot indexes.
class SessionObject {
 public:
  virtual ~SessionObject();  //0x00/0x08
  virtual void slot10();     //0x10
  virtual void slot18();     //0x18
  virtual void slot20();     //0x20
  virtual void slot28();     //0x28 — notification invoked from job steps
};

// Session state object (pointed to by SessionCtx::field00) — partial layout.
class SessionState {
 public:
  char pad00[8];           // 0x00
  SessionObject* field08;  //0x08 — inner object that receives slot28
  char pad10[0x60];        // 0x10
  void* field70;           //0x70
  char pad78[0x5c];        // 0x78
  unsigned int mD4;        //0xd4 — must be 4 for the LeaveSessionJob transition
};

// Session context singleton at [0x71013123e0] — partial layout.
// field00 is re-read in the branches (the original reloads [ctx] after calls).
class SessionCtx {
 public:
  SessionState* field00;  //0x00 — passed to the state getter (FUN_710099985c)
};

// nn::pia::session::DestroySessionJob — state machine steps.
// Slots 0x10-0x38 of its own vtable are unknown; slot40 is invoked from the
// steps (state transition).
class DestroySessionJob : public SessionObject {
 public:
  virtual void slot30();  //0x30
  virtual void slot38();  //0x38
  virtual void slot40();  //0x40 — invoked from the steps

  // 64-bit return (the original writes 5 via mov w0,#5 — writing W zeroes
  // the upper half)
  uint64_t SendMonitoringData() asm("nn::pia::session::DestroySessionJob::SendMonitoringData");
  uint64_t CompleteProcess() asm("DestroySessionJob::CompleteProcess");
  uint64_t SendMonitoringData2() asm("nn::pia::session::DestroySessionJob::SendMonitoringData#2");
  uint64_t SendMonitoringData3() asm("nn::pia::session::DestroySessionJob::SendMonitoringData#3");

  // observed layout (the base only has the vtable pointer)
  struct Result {
    void* a;
    void* b;
  };
  char pad08[0x28];  // 0x08
  Result m30;        // {ptr, null} — step result
  const char* m40;   // step name (MethodTree string)
  char pad48[0x18];  // 0x48
  unsigned int m60;
  unsigned int m64;
  unsigned int m68;
  char pad6c[0x14];   // 0x6c
  unsigned long m80;  //0x80 — start tick of the current step
  unsigned int m84;
  bool m88;
};
}  // namespace nn::pia::session
