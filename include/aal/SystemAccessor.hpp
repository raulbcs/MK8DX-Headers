#pragma once

#include <aal/Arbiter.hpp>
#include <aal/Group/GroupMgr.hpp>
#include <cstdint>

namespace aal {
class SystemAccessor {
 public:
  static Arbiter* getArbiter();
  static GroupMgr* getGroupMgr();
};
}  // namespace aal
