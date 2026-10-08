#pragma once

// Minimal placeholder for the xlink2 trigger type. The Switch binary strips
// RTTI for xlink2 and no consumer in this repo instantiates a vtable that
// depends on the enumerator values, so the value set is a guess; only the
// type name and its size (int) are load-bearing here.
namespace xlink2 {
enum TriggerType {
  Invalid = -1,
};
}  // namespace xlink2
