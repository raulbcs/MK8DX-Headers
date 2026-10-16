#pragma once

#include <container/seadPtrArray.h>
#include <prim/seadSafeString.h>

#include <aal/Asset/AssetInfo.hpp>
#include <cstdint>

#include "AudioResource.hpp"

namespace aal {
// This class is what a barslist represents
class AudioResourceList {
 public:
  virtual bool readAssetInfo(aal::AssetInfo*,
                             sead::SafeStringBase<char> const&);
  virtual ~AudioResourceList();

  uint8_t mPad08[0x08];                   // 0x08
  uint8_t const* mRawData;                // 0x10
  uint8_t mPad18[0x08];                   // 0x18
  sead::PtrArray<AudioResource> mAssets;  // 0x20
};
}  // namespace aal
