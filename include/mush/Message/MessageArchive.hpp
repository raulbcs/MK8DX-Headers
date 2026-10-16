#pragma once

#include <cstdint>

// mush::MessageArchive family — placeholder names (no symbol/RTTI in v400);
// evidenced by 14 "/Common/Mush/<X>.bin" rodata paths and vtables
// 0x71012cbda8-0x71012cbef8.

namespace mush {
// MessageArchive — base resource; base ctor v400 0x82c8f8 (size 0x30);
// 14 subclasses in two parallel arrays (owner fields 0x20-0x88/0x90-0xf8).
class MessageArchive {
 public:
  virtual ~MessageArchive();

  std::uint32_t mCategoryFourCC;  // 0x8 - e.g. 'AIBL', 'CTRL', 'ITEM', 'PERF'
  std::uint32_t mCategoryParam;   // 0xc
  void* mVtable2;                 // 0x10 - second vtable (mixin), shared by all 14
  uint8_t pad_18[0x18];           //0x18 — unproven gap
  const char* mArchivePath;       // 0x18 - "/Common/Mush/<X>.bin" (8 more bytes follow, null)

  MessageArchive();  // v400: 0x82c8f8 (base ctor, size 0x30)
};

// Per-category subclasses. Only size and ctor are evidenced per class;
// remaining members are category-specific data zeroed by the ctor.

class MessageArchiveAIBattle : public MessageArchive  // size 0x1a8
{
 public:
  MessageArchiveAIBattle();  // v400: 0x829dd8, vtable 0x71012cbda8
};

class MessageArchiveAIRace : public MessageArchive  // size 0x178
{
 public:
  MessageArchiveAIRace();  // v400: 0x82a0d4, vtable 0x71012cbdc0
};

class MessageArchiveAudio : public MessageArchive  // size 0x328
{
 public:
  MessageArchiveAudio();  // v400: 0x82a3a0, vtable 0x71012cbdd8
};

class MessageArchiveController : public MessageArchive  // size 0x60
{
 public:
  MessageArchiveController();  // v400: 0x82afb0, vtable 0x71012cbdf0
};

class MessageArchiveCourse : public MessageArchive  // size 0x88
{
 public:
  MessageArchiveCourse();  // v400: 0x82b108, vtable 0x71012cbe08
};

class MessageArchiveDLC : public MessageArchive  // size 0x70
{
 public:
  MessageArchiveDLC();  // v400: 0x82b23c, vtable 0x71012cbe20
};

class MessageArchiveHighlight : public MessageArchive  // size 0xd0
{
 public:
  MessageArchiveHighlight();  // v400: 0x82b3b0, vtable 0x71012cbe38
};

class MessageArchiveItem : public MessageArchive  // size 0x418
{
 public:
  MessageArchiveItem();  // v400: 0x82b4f8, vtable 0x71012cbe50
};

class MessageArchiveMiiVoice : public MessageArchive  // size 0x70
{
 public:
  MessageArchiveMiiVoice();  // v400: 0x82c2dc, vtable 0x71012cbe68
};

class MessageArchiveObj : public MessageArchive  // size 0x150
{
 public:
  MessageArchiveObj();  // v400: 0x82c4d0, vtable 0x71012cbe80
};

class MessageArchiveOpenFlag : public MessageArchive  // size 0x78
{
 public:
  MessageArchiveOpenFlag();  // v400: 0x82c770, vtable 0x71012cbe98
};

class MessageArchiveParts : public MessageArchive  // size 0x6b0
{
 public:
  MessageArchiveParts();  // v400: 0x82ca60, vtable 0x71012cbec8
};

class MessageArchivePerformance : public MessageArchive  // size 0x298
{
 public:
  MessageArchivePerformance();  // v400: 0x82d278, vtable 0x71012cbee0
};

class MessageArchiveUI : public MessageArchive  // size 0x48
{
 public:
  MessageArchiveUI();  // v400: 0x82d7b8, vtable 0x71012cbef8
};
}  // namespace mush
