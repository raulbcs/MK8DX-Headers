# nn::ae::AppletThreadHost

PROVISIONAL name (vtable 0x12d02c8, cell 0x1310fb0; slot 0x10 = 0x87275c, its own family). Naming: sole ctor 0x872004 builds all seven named applet threads but the host object itself has no rodata name and no MethodTree entry. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Construction / init order

1. Sole construction site 0x8bca3c calls ctor 0x7100872004(this).
2. Base 0x71007b976c; priority from [0x130d250].
3. SEVEN in-place applet threads, each via 0x7100628a54 with {cell+0x10, rodata name} on the stack: Controller 0x38 (0x318), Keyboard 0x350 (0x548), OfflineWeb 0x898 (0xf8), MiiEdit 0x990 (0x100), Error 0xa90 (0xfc), Nifm 0xba8 (0x100), NSA 0xca8 (0xf8).
4. Buffers from nn::swkbd; nn::err::ErrorResultVariant C1'd in place at 0xb94 (host site 0x872240; plt, size unverified).
5. Member-init pass 0x7100628f3c over all seven threads.

Extent >= 0xda0, tail unmapped.
