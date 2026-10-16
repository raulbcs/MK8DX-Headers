# KartSteerAssist

Note: per-field notes for this class are authoritative in
`include/object/Kart/KartSteerAssist.hpp`. This file records the facts that
lived in the duplicate header `include/kart/SteeringX.hpp` (deleted — same
object; see identity below).

## Identity and duplicate

- Class: `KartSteerAssist` — steering/start-dash object. `include/kart/SteeringX.hpp`
  described the SAME object (same offsets +0x43/+0xB8/+0xC0/+0xC8/+0x28, same
  lazy-cache chain 0x7100150a90); it is now deleted and repointed here.
- `SteeringX` stated size 0x106 (unpadded tail-pads to 0x108); the factory in
  the KartVehicle ctor allocates 0x120 (`operator new(0x120)`, v400
  0x710017025c) — see the header for the proven 0x120 extent. The 0x106
  figure is retained verbatim from the duplicate header: unverified against
  the 0x120 factory extent.
- PROVISIONAL name in the duplicate header: no MethodTree string (method-tree
  registrations at 0x6327a8 hold none).

## Fields recorded by the duplicate header (SteeringX naming)

All store-site addresses below were verified in the v400 ELF.

| Offset | Field (SteeringX name) | Evidence |
|---|---|---|
| 0x00 | vptr | `*0x12fd538 + 0x10` (0x1502d0) |
| 0x08 | subobject_70 | new(0x70) via 0x7c55cc (0x150404..0x150418) |
| 0x10 | subobject_e4_a | new(0xE4) memset 0 (0x1503b0..0x1503d0) |
| 0x18 | subobject_e4_b | new(0xE4) memset 0 (0x1503d4..0x1503ec) |
| 0x20 | subobject_24 | new(0x24), zeroed (0x1503e8..0x150400) |
| 0x28 | mode | assist level; writer 0x7100150a40 (0 → off, else re-init + auto level) |
| 0x2C | mode_value (s32) | ctor -1 (0x1502d8); re-init writes 0x710015090c() (0x150508..0x150510) |
| 0x30 | flag_30 (u64) | ctor 0 (0x1502e0); re-init sets 1 (0x15051c) |
| 0x38 | i38 (s32) | ctor -1 (0x1502e4) |
| 0x3C | process_flag (u8) | gate of the 2008 post-call; ctor zeroed as u64 with 0x3D..0x43 (0x1502ec) |
| 0x3D | pad_3d[6] | ctor-zeroed with process_flag (same u64 store) |
| 0x43 | parity (u8) | bit&1 via 0x7100150a80 (constant 1 from wrappers 0x1925fc..0x192644) |
| 0x44 | boost_output (f32) | ctor byte-zero at +0x44 (0x1502e8); upper bytes carry no ctor store |
| 0x48 | i48 (s32) | ctor -1 (0x1502f0; re-init -1, 0x15043c..0x150440) |
| 0x4C | boost_output_1 (f32) | ctor 0 (0x1502f0) |
| 0x50 | u50 (u32/f32) | ctor 0 (0x1502f4); steering target written by calc 0x7100150a8c |
| 0x54 | b54 (u8) | ctor 1 (0x15030c) |
| 0x55 | pad_55[3] | no ctor store; no accessor evidence — unproven, never accessed in range 0x55-0x57 |
| 0x58 | pad_58 (u32) | ctor-zeroed u64 with +0x5C (0x150308) |
| 0x5C | countdown (u32) | mode-3 epilogue after GO; ctor 0 (same store) |
| 0x60 | zero_60[0x10] | ctor 0 (0x1502fc) |
| 0x70 | u70 (u32) | ctor 0 (0x1502f8) |
| 0x74/0x78/0x7C | globals_74[3] | u32 global [0x12fd540] (0x150310..0x150320) |
| 0x80 | cursor_80 (u64) | ctor stores this+0x94 (0x150338) |
| 0x88 | cap_88 (u32) | ctor 8 (0x150334/0x150340) |
| 0x8C | zero_8c (u64) | ctor 0 (0x15033c) |
| 0x94..0xB3 | sentinel_94[4] | ctor -1 block (0x150324..0x150330) |
| 0xB4 | pad_b4[4] | no ctor store; no accessor evidence — unproven, never accessed in range 0xB4-0xB7 |
| 0xB8 | cache_lazyinit (u64) | ctor 0 (0x150344); lazy `*(*(RS+0x190+idx*8)+0x238)+0xB8` (0x150b08..0x150b14, 0x7100150a90) |
| 0xC0 | kart_vehicle_ptr | KartVehicle* ctor arg x1 (0x150348) |
| 0xC8 | kart_vehicle_move | KartVehicleMove* ctor arg x2 (0x150350) |
| 0xD0 | decay_per_frame (u64) | ctor ptr from [0x12fb148] (0x150364); x0.8 per frame in the f74c main path |
| 0xD8 | u_d8 (u32) | [that ptr + 8] (0x15035c) |
| 0xDC | pad_dc[0xc] | no ctor store; no accessor evidence — unproven, never accessed in range 0xDC-0xE7 |
| 0xE8 | charge (f32) | start dash, target 1.5; ctor 0 (0x15036c) |
| 0xEC | counter (u32) | ctor 0 (0x15036c) |
| 0xF0 | f_f0 (f32) | ctor -1.0f (0x150370); -1.0f/frame in the calc |
| 0xF4 | zero_f4[8] | ctor 0 (0x150374) |
| 0xFC | fc (u32) | re-init 0xFFFFFFFF (0x15043c/0x150470) |
| 0x100 | x100 (u32) | 0 (upper half of the same u64 store) |
| 0x104 | zero_104 (u8) | ctor 0 (strh 0x104..0x105, 0x150378) |
| 0x105 | sign_latch (u8) | ctor 0 (same store) |

## Construction / init order

1. Factory: `operator new(0x120)` in the KartVehicle ctor (0x710017025c),
   only when KartVehicle+0xD0 mIsMaster != 0 (else nullptr at
   KartVehicle+0xA0).
2. Ctor 0x71001502a8: vptr (0x1502b8..0x1502d0), then the field stores in the
   table above (sub-object allocations 0x1503b0..0x150400, -1/0 scalars
   0x1502d8..0x150310, cursor/capacity 0x150324..0x150344, tail fields
   0x150348..0x150398).
3. Tail-called re-init 0x710015042c (call site 0x1503ac): overwrites +0x2C
   with 0x710015090c() (0x150508..0x150510), +0x30 = 1 (0x150518..0x15051c),
   +0x48 = -1 and +0xFC = 0xFFFFFFFF (0x15043c..0x150470).
