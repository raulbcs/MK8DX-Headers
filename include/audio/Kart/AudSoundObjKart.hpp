#pragma once

#include <audio/Object/AudSoundObjBase.hpp>
#include <cstdint>

namespace audio {
class AudSoundObjKart : public AudSoundObjBase {
 public:
  enum ETrgKartSE : int {};

  void requestTrgKartSE(audio::AudSoundObjKart::ETrgKartSE, int, int);
};
}  // namespace audio
