# InetJoinMeshJob (nn::pia::inet::InetJoinMeshJob)

- vptr 0x12da678 = first slot row; offset-to-top 0 at 0x12da668, typeinfo
  0x12da6d0 at 0x12da670 ("N2nn3pia4inet15InetJoinMeshJobE"). GOT cell
  0x1312a50 holds addend 0x12da668 = vptr-0x10.
- Size 0xd8, proven by the factory at 0x931850: `operator new(0xd8)`
  (0x568aa0 with the global allocator at 0x563b70) then C1 0x937b28
  (0x931878).

## Identity

pia inet join-mesh job. Derives from nn::pia::session::JoinMeshJob (base C1
0x97f76c, base vptr 0x12ddb58): C1 0x937b28 just runs the base C1 and then
overrides the vptr (0x937b40-0x937b48) — it adds overrides, not fields, so
sizeof == base sizeof (0xd8).

## Member notes

- No data fields beyond the JoinMeshJob base layout; D1 is a pure tail-branch
  to the base D1.

## Construction / init order

- C1 = 0x937b28 (base C1 0x97f76c, then vptr 0x12da678 at [this]).
- D1 = slot 0, 0x937b58 (tail `b` to base D1 0x97f944). D0 = slot 1,
  0x937b5c (base D1 0x97f944, then operator delete 0x60b470).
- Slots (11): 0=0x937b58 (D1, base), 1=0x937b5c (D0), 2=0xb4a654,
  3=0xb4a67c, 4=0x933314, 5=0x9823b0 (shared with JoinMeshJob), 6=0x937b80,
  7=0x937c34 (`ret`), 8=0x937c38
  (InetJoinMeshJob::StartMonitoringServerAddressResolution, named in
  functions.csv), 9=0x937c5c, 10=0x937cc0. Slots 2-7/9-10 unrecovered.
- Factory 0x931850 (new 0xd8 -> C1 0x937b28).
