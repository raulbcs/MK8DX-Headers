# nn::pia::inet::NexMatchGenerateSystemPasswordJob

RTTI-confirmed via typeinfo name `N2nn3pia4inet33NexMatchGenerateSystemPasswordJobE` (0xf7f260). Typeinfo-row vtable 0x12daea0: GOT cell 0x1312d38 holds vptr-0x10, installed vptr 0x12daea8; word at 0x12daea0 points to the embedded typeinfo object at 0x12daef0 (base typeinfo 0x12ddb30 = nn::pia::session::GenerateMatchmakeSystemPasswordJob, itself a nn::pia::common::StepSequenceJob; sibling NexMatchDestroySessionJob typeinfo sits at 0x12dae80). Offset-to-top 0. 8 slots; slots 2-4 shared job overrides (0xb4a654/0xb4a67c/0x933314 `ret`).

## Member notes

- Slot5 0x93f42c zeroes [this+0x130] and [this+0x150] (qwords), plus [this+0x148] (word) and [this+0x14c] (byte) - deepest `this` offsets in the class; the +0x130/+0x150 pair suggests two embedded request/result buffers.
- Size: lower bound 0x158 from the slot5 store at +0x150 (qword). Exact size unverified.

## Construction / init order

- Ctor 0x93f100: GOT cell 0x1312d38 -> +0x10 -> `[this]` = vptr, then `[this+0x88] = 0` (0x93f100..0x93f118). No `bl` callers and no relocs to the ctor were found - construction site unverified.
