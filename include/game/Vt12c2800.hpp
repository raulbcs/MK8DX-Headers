#pragma once

#include <cstdint>

// Vt12c2800 — 8-byte polymorphic functor (stateless rate/curve evaluator),
// size 0x08 EXACT: materialized directly by factories 0x77b5ac / 0x77b740
// / 0x77c5xx via operator new(8, 8); kind selector value 2 picks this row.
// extent 0x08 - details: doc/game/Vt12c2800.md
namespace game {
class Vt12c2800 {
 public:
  void* mVtable;  // 0x00 - row 0x12c2800 (cell 0x130f4f0 holds vptr-0x10);
                  //   slot 3 (+0x18) is the f32 evaluator invoked by the
                  //   owning object with three float params
};
}  // namespace game
