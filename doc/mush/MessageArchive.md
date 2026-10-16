# mush::MessageArchive family

Message system archive definitions ("Mush" = Mushroom, Nintendo's message library). Placeholder names: the v400 binary carries no symbol or RTTI for this family — the classes are evidenced by the 14 "/Common/Mush/<X>.bin" rodata paths, one ctor per category, a shared base ctor, and 15 adjacent vtables at 0x71012cbda8-0x71012cbef8 (base vtable 0x71012cbeb0 sits in the middle of the group). Evidence targets v400.

One message-archive resource. The game instantiates 14 subclasses and keeps them in two parallel arrays of the owning message-system object (fields 0x20-0x88 and 0x90-0xf8); setup runs under the heap named "System::Mushroom".

Per-category subclasses: only size and ctor are evidenced per class; remaining members are category-specific data zeroed by the ctor (sizes/ctors per the comments in include/mush/Message/MessageArchive.hpp).

## Construction / init order

1. Base ctor MessageArchive() v400 0x82c8f8 (size 0x30).
2. Per-category subclass ctors (one per "/Common/Mush/<X>.bin" category), e.g. MessageArchiveAIBattle 0x829dd8 (vtable 0x71012cbda8); each zeroes its category-specific tail.
3. Instances stored into the owning message-system object's parallel arrays (fields 0x20-0x88 and 0x90-0xf8) under heap "System::Mushroom".
