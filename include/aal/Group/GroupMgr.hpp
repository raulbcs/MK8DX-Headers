#pragma once

#include <prim/seadSafeString.h>

#include <cstdint>

#include "Group.hpp"

namespace aal {
class GroupMgr {
 public:
  aal::Group* findSoundGroup(sead::SafeString const&) const;
};
}  // namespace aal