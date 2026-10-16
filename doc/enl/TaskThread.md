# enl::TaskThread

nn::ae-style applet-thread subclass (vptr 0x128a8e0, cell 0x130b0f0, n=20; ctor 0x557c0c, alloc sites 0x556e04 / 0x90f7a4 / 0x91d...: new 0x2c0). Constructed by enl::Framework's setup (ctor arg x1 is the framework config block).

Ctor field map: 0x00 vptr; 0xf8 {u32 head=0, u32 tail=0}; ring of 2 nodes x 0x10 at 0x108 (init 0x60b918) with the 0x200-byte message pool allocated in the ctor helper 0x557db0; free-node array of 10 nodes x 0x10 at 0x120 (init 0x60b918, self-linked 0x140..0x1b8); 0x1e0 member sub-object (ctor 0x628628); 0x220 member sub-object (ctor 0x628628); 0x260 message-queue ptr (created via 0x6157b4); 0x268 u32 = 0; 0x270 u64 = config[0x24] * global ticks (0x12fc688) / 100 (period); 0x278 sub-object (ctor 0x62872c); 0x2a8 u64 = config[0x34] * ticks / 100; 0x2b0 u32 = config[0x38]; 0x2b4 u32 = config[0x18]; 0x2b8 u32 = config[0x3c].

Extent 0x2c0 (prior-survey total; cross-checked: alloc 0x2c0 @0x71002700d8 -> ctor 0x71002700fc stores 0x2c0).

## Construction / init order

1. Allocation 0x556e04 / 0x90f7a4: operator new(0x2c0).
2. Ctor 0x557c0c: ring init 0x60b918 at 0x108 (2 nodes) and free list at 0x120 (10 nodes, self-linked 0x140..0x1b8); message pool allocated by ctor helper 0x557db0; sub-object ctors 0x628628 at 0x1e0 and 0x220; message queue created via 0x6157b4 at 0x260; config-derived periods at 0x270/0x2a8 and config words 0x2b0/0x2b4/0x2b8; sub-object ctor 0x62872c at 0x278.
