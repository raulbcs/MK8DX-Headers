# gear::EObjTriggerType

Class of touch-reactive course objects (objflow entries) that fire interaction events when the kart passes through them. Most classes push a BoostSlot tier through FUN_710017a870; the glide-open path shares the same dispatcher.

Reconstructed (no RTTI in the 400 binary): the type byte is course-file data (objflow.byaml), read from the descriptor at entry+0x8 by 0x7100396138 and dispatched through the word table 0xf24460 (type -> BoostSlot tier) -> FUN_710017a870. Proven identities and effect table come from content data, not the binary section "Course triggers" (commits 42a2241f, 98550f99).

## Provenance notes

- The type byte originates from course-file data (objflow.byaml), read from descriptor entry+0x8/+0x9 at 0x7100396198/0x71003961c4 — never an immediate in code. t0/t2/t11 identities therefore live in content data, not the binary (data/content/objflow.byaml).
- t3/4/5 are one object family with parameter {1,2,3} (selector 0x7100183648). t10 cross-links to KCL attr ESurfaceType::DASH (0xa) at 0x710018af54.
- Dispatch: FUN_710017af90 (tail-b of body calc 189534) indexes the word table and falls back to tier 1 for types > 0xb.

## Effect table (per enum value, see header)

tier / duration / level / impulse per value as annotated on each enumerator in include/gear/Race/EObjTriggerType.hpp (word table 0xf24460).
