#pragma once

/*
 * Race recorder scene director. Vtable of the class = 0x7101261ad8
 * (19 slots + makeGhostData; the same director object whose per-frame
 * tick 0x71003ab8d0 sits at vtable slot 0x80 and drives the 14
 * recorder::Mgr playback state machines at +0x40..0xa0).
 *
 * makeGhostData (slot 0x98) = FUN_71003aca18 (248B): the save/encode
 * entry point. Body: gate [mgr.[+0x40].[[+0x78]+0x94]] -> 7b7a74
 * (pre-step) -> 7a8f7c -> 7aabf0 (set tick [director+0x1d4]) -> take
 * the record file from singleton [0x3ddf50]+0x9b0 -> 3bc344 -> for
 * each Mgr: 7a8bbc (seek) with [[director+0x2c0]] ->
 * FUN_71003acb10(this, mgr, 0, [director+0x2c0], count) -> cleanup
 * 88c908 / 7a957c. Returns 1.
 *
 * Encode worker = FUN_71003acb10 (1068B): walks the binder channels
 * ([mgr+0x28] count / [+0x30] list, obj+0x214-1 == mgrId dedupe) and
 * emits, per 64-tick key block, the ghost-file format: per channel
 * [marker 01/00][width payload] records (fresh via 7acc98, which
 * materializes the frame by calling the channel's own decoder through
 * bridge vtbl+0xd0 = 0x7acd68 -> decode64 FUN_71007aa86c; hold =
 * vtbl+0x108 = 0x7acd90 zeroing), u64 masks written by FUN_71007a9cc0
 * and the 16x s16 key/offset table written by FUN_71007a9c5c, plus an
 * aligned keyframe tail (7a9c18 / 7ac730 / 7a9c5c). Ops seen:
 * 7aacbc 7a9fc8 7a957c 7a8f40 7a9608 7a9474 7aa0f4 7aa424 7acc98
 * 7a9914 7a9bc8 7a9c18 7ac730 7a9c5c 7a9a68 7a90f8 7a9f5c 7a9f78.
 * Block ring at [director+0x1d8]/[+0x1dc].
 *
 *
 */

namespace object {
class RecorderDirector {
 public:
  virtual void mVirtFunc00();  // 0x00
  virtual void mVirtFunc08();  // 0x08
  virtual void mVirtFunc10();  // 0x10
  virtual void mVirtFunc18();  // 0x18
  virtual void mVirtFunc20();  // 0x20
  virtual void mVirtFunc28();  // 0x28
  virtual void mVirtFunc30();  // 0x30
  virtual void mVirtFunc38();  // 0x38
  virtual void mVirtFunc40();  // 0x40
  virtual void mVirtFunc48();  // 0x48
  virtual void mVirtFunc50();  // 0x50
  virtual void mVirtFunc58();  // 0x58
  virtual void mVirtFunc60();  // 0x60
  virtual void mVirtFunc68();  // 0x68
  virtual void mVirtFunc70();  // 0x70
  virtual void mVirtFunc78();  // 0x78
  virtual void mVirtFunc80();  // 0x80
  virtual void mVirtFunc88();  // 0x88
  virtual void mVirtFunc90();  // 0x90

  virtual bool makeGhostData();  // 0x98
};
}  // namespace object
