#pragma once

#include <prim/seadSafeString.h>

#include <cstdint>
#include <gsys/Animation/MaterialAnmType.hpp>

namespace gsys {
class ModelAnimation {
 public:
  int32_t searchSkeletalKey(sead::SafeStringBase<char> const&) const;
  int32_t searchMaterialAnmKey(gsys::MaterialAnmType,
                               sead::SafeStringBase<char> const&) const;
};
}  // namespace gsys
