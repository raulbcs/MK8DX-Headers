# JoinMeshJob (nn::pia::session::JoinMeshJob)

- vptr 0x12ddb58 = first slot row; offset-to-top 0 at 0x12ddb48, typeinfo
  0x12ddbb0 at 0x12ddb50 ("N2nn3pia7session11JoinMeshJobE"). GOT cell
  0x13136f8 holds addend 0x12ddb48 = vptr-0x10.
- Size 0xd8, proven by the factory at 0x9c3af0: `operator new(0xd8)`
  (0x568aa0 with allocator 0x563b70) then C1 0x97f76c (0x9c3b18).

## Identity

pia session join-mesh job; polymorphic base of
nn::pia::inet::InetJoinMeshJob (vt 0x12da678, same size 0xd8 — derived C1
0x937b28 only swaps the vptr). Job-framework base C1 0xb4a5e0 runs first
(0x97f77c) and owns the +0x00..+0x57 region (step result at +0x30, step name
at +0x40; cf. src/_nn/pia/session/JoinMeshJob__CompleteProcess.cpp).

## Member notes

- +0x58 zeroed; +0x60 pointer to a 0x20-byte subobject (ctor 0x929ec0,
  0x97f7b4; released by 0x929f78 in the cleanup path 0x97f714-0x97f72c).
- +0x68 u32; +0x6e u16 entry count sourced from the u16 at cell 0x1312748 +
  0xa8 (0x97f7ec-0x97f7f8).
- +0x70 array of count x 0x78-byte entries (elem ctor 0x9b1fe8, loop
  0x97f820-0x97f830); +0x78 u32[count] zero-filled (0x97f848-0x97f894).
- +0x80/+0x81/+0x82 zeroed, +0x84 = 3 (0x97f79c), +0x98 zeroed, +0xa8/+0xb0
  stp xzr; +0xb8 member subobject (ctor 0x929ec0).

## Construction / init order

- C1 = 0x97f76c: job-base C1 0xb4a5e0, vptr 0x12ddb58 at [this]
  (0x97f788-0x97f7b0), then +0x58/+0x60/+0x6e-count arrays/flags in ascending
  order (0x97f790-0x97f8a0).
- D1 = slot 0, 0x97f944 (body not fully traced; the cleanup helper at
  0x97f704 frees +0x60 when its state==1 and clears +0x68, and is the
  likely shared tail). D0 = slot 1, 0x97fa3c.
- Slots (11): 0=0x97f944 (D1), 1=0x97fa3c (D0), 2=0xb4a654, 3=0xb4a67c,
  4=0x933314, 5=0x9823b0, 6=0x97fb6c, 7=0x98213c, 8=0x9823b4, 9=0x97fc94,
  10=0x9823b8. Slots 2-10 unrecovered.
- Factory 0x9c3af0 (new 0xd8 -> C1 0x97f76c). Derived InetJoinMeshJob
  factory 0x931850 (new 0xd8 -> C1 0x937b28).
