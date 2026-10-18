#pragma once

#include "object/Vt12b69c8.hpp"

// Vt12bad28 - PLACEHOLDER name; derived flavour of Vt12b69c8 (same 0x318
// layout, no own fields): overrides D1/D0 and slot13 with a
// context-dispatching tail-call; built only by factory 0x6f786c.
// extent 0x318 (inherited from base Vt12b69c8) - details:
// doc/object/Vt12bad28.md

namespace object {
class Vt12bad28 : public Vt12b69c8 {};
}  // namespace object
