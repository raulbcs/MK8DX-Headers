# nn::pia::inet::NexMatchClearSystemPasswordJob

RTTI-confirmed via typeinfo name `N2nn3pia4inet30NexMatchClearSystemPasswordJobE` (0xf7efd0). Typeinfo-row vtable 0x12daca0: GOT cell 0x1312bd8 holds vptr-0x10, installed vptr 0x12daca8; word at 0x12daca0 points to the embedded typeinfo object at 0x12dacf0 (base typeinfo 0x12dd6f0 = nn::pia::session::ClearMatchmakeSystemPasswordJob, itself a nn::pia::common::StepSequenceJob; sibling NexMatchBrowseMatchmakeJob typeinfo sits at 0x12dac80). Offset-to-top 0. 8 slots; slots 2-4 shared job overrides (0xb4a654/0xb4a67c/0x933314 `ret`).

## Member notes

- Slot5 0x93c8d0 zeroes [this+0x88] and [this+0xa0] (byte); also stores [x+0x80] (qword) on the job context it receives.
- Size: lower bound 0xa8 from the slot5 store at +0xa0 (byte). Exact size unverified.

## Construction / init order

- Ctor 0x93c5a4: GOT cell 0x1312bd8 -> +0x10 -> `[this]` = vptr, then `[this+0x88] = 0` (0x93c5a4..0x93c5bc). No `bl` callers and no relocs to the ctor were found - construction site unverified.
