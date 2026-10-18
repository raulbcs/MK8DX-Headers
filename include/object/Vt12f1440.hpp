#pragma once

#include <cstdint>
#include "object/Vt12f1570.hpp"

// Vt12f1440 (size 0xA8) — Vt12f1570 derivative; PROVISIONAL name (no name
// string). Overrides slots 0-3; allocated as 0xA8-stride arrays by
// FUN_7100746f80 / FUN_7100a6e854.
// extent 0xA8 - details: doc/object/Vt12f1440.md

struct Vt12f1440 : Vt12f1570 {};
