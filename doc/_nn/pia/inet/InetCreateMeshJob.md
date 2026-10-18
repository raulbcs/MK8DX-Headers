# InetCreateMeshJob (nn::pia::inet::InetCreateMeshJob)

- RTTI-named: word at 0x12da4d0 is the typeinfo pointer -> embedded pair at
  0x12da530 = {0x10, name "N2nn3pia4inet17InetCreateMeshJobE"}.
- GOT cell 0x1312a18 holds 0x12da4c8 = vptr-0x10; installed vptr = 0x12da4d8,
  10 function slots at vptr+0x00..+0x48.
- Size 0x60 proven: alloc wrapper FUN_7100931814 does new(0x60) (orr w0,
  #0x60 at 0x931828, alloc 0x568aa0) then C1 FUN_71009373ac (0x93183c).

## Identity

pia inet mesh-creation job description. Single allocation site; the object is
returned to the caller (0x931848) — job factory pattern.

## Member notes

- +0x30/+0x38/+0x40 written by slot 7 (SetupLocalPlayerInfo, FUN_7100937404,
  named in functions.csv): +0x30 = [cell 0x1312a20], +0x38 = 0, +0x40 =
  0xf0e048 (0x937444-0x93744c); also pokes globals at 0x130b134/0x130b36c
  region (unverified).
- +0x08..+0x2f base region managed by base C1 0x97e0e4 (unrecovered).

## Construction / init order

- C1 = FUN_71009373ac (0x9373ac): base C1 0x97e0e4, then vptr cell
  0x1312a18 (+0x10) stored at [this] (0x9373c8-0x9373cc).

## Slots (10, at vptr 0x12da4d8..+0x48)

- 0 = 0x9373dc: tail-b 0x97e118 (base override thunk; D1 path).
- 1 = 0x9373e0: calls base 0x97e118 then operator delete (D0, deleting dtor).
- 2 = 0xb4a654 (40B, unrecovered); 3 = 0xb4a67c (108B, unrecovered).
- 4 = 0x933314; 5 = 0x97e8f0; 6 = SetupLocalPlayerInfo FUN_7100937404.
- 7 = 0x9374bc; 8 = 0x9374c0; 9 = 0x937504. Bodies unrecovered.
