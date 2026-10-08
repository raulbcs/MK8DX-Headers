#pragma once

namespace xlink2 {
// UserInstanceSLink — empty sentinel type (size 1): no fields, no
// vtable, no consumer dereferences it in the binary; only the type
// name is load-bearing (link-list node tag). Same evidence standard
// as TriggerType: name proven, layout trivially empty.
class UserInstanceSLink {};
}  // namespace xlink2
