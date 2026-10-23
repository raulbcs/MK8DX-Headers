#pragma once

#include <cstdint>

#include "FrameworkGameScene.hpp"
#include "FrameworkRootSceneBase.hpp"
#include <object/Kart/KartSteerAssist.hpp>

namespace gear {
class FrameworkUtil {
 public:
  static FrameworkGameScene* getCurrentGameScene();
  static FrameworkRootSceneBase* getRootSceneBase();
};
}  // namespace gear
