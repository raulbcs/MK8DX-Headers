#pragma once

#include <heap/seadHeap.h>
#include <prim/seadSafeString.h>

#include <aal/Emitter.hpp>

namespace aal {
class Arbiter {
 public:
  Emitter* allocEmitter(sead::Heap*, sead::SafeStringBase<char> const&);
  void freeEmitter(aal::Emitter*);
};
}  // namespace aal