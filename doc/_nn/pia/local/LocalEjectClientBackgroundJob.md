# object::LocalEjectClientBackgroundJob (nn::pia::local)

## Identity

RTTI-confirmed: typeinfo struct 0x12e2260 = {0x10, "N2nn3pia5local29LocalEjectClientBackgroundJobE", 0x12f8d30}; base is the pia common StepSequenceJob (ti 0x12f8d30). vptr 0x12e2228 (ti-slot row 0x12e2220); GOT cell 0x1314170 holds vptr-0x10.

## Member notes

- Slots (vptr 0x12e2228): D0 0x9d4894 (drain only, tail 0xb4a62c), D1 0x9d48e0 (drain + operator delete 0x60b470), base-shared 0xb4a654 / 0xb4a67c / 0x933314, override 0x9d4a68 (absent from functions.csv).
- [this+0x58] — inner job pointer, zeroed by C2; cancel helper 0x9d4804 reads its u32 state (==1 -> sends cmd 0x6c05 via 0x929f3c) and NULLs it; caller 0x9cd260 pokes flag byte [ptr+0x48] and calls 0xb4a6e8 before cancelling.
- [this+0x60..0x70] — embedded member subobject: vptr 0x12d9580 (StationAddress family, cell 0x1312438+0x10) installed at +0x60; C2 constructs it via 0x92a1e0(this+0x60), D-tors destroy via 0x92a014(this+0x68) and zero +0x70. Both D-tors re-install the two vptrs before the member teardown (0x9d48a4/0x9d48f0).
- [this+0x70] — pointer stored from C2 arg x1.

## Construction / init order

- C2 = 0x9d4850: base C1 0xb4a5e0 -> zero [this+0x58] -> primary vptr -> member ctor 0x92a1e0 at +0x60 -> [this+0x70] = arg.
- Sole allocation site: 0x9cef08 operator new(0x78) + C2 0x9d4850, result stored at [manager+0x58] (0x9ceec0 region factory). Size 0x78 EXACT.
