#pragma once

#include <cstdint>

// Ghost stream trans/rot codec + record-layout builder. All addresses are
// original VMAs verified against the disassembly.

namespace recorder {

// Record-layout object built by FUN_7100045f78; extent 0x378 (operator
// new(0x378) at sole ctor caller 0x710002bd4, before bl FUN_7100045f78).
struct GhostRecordLayout {
  uint8_t widthShift_00;      //0x00 — u8 0x100 >> ((sub-1)*8); 1 when sub-1 >= 4
  uint8_t flag_01;            //0x01 — sub==9 && 2 <= [entry+0x180] < 5
  uint8_t tailFlag_02;        //0x02 — set by the tail (type<=1, sub 0/7/8)
  uint8_t pad_03[0x1];        //0x03 — to the first u32 pair
  uint32_t bytesTickA_04;     //0x04 — bytes/tick sub-stream A
  uint32_t bytesTickB_08;     //0x08 — bytes/tick sub-stream B
  uint8_t pad_0c[0x94];       //0x0C — to the vptr slot at +0xA0
  uint8_t vptr_00a0[0x8];     //0xA0 — record-class vptr cell (GOT 0x12fbb90..b8)
  uint8_t pad_a8[0x8];        //0xA8 — to the +0xB0 sub-object
  uint8_t pad_b0[0x10];       //0xB0 — sub-object (init FUN_710062ee28; 0x10 B)
  uint8_t slotListA_c0[92];   //0xC0 — slot list A (ctor = 0xff fill)
  uint8_t pad_11c[92];        //0x11C — slot list B (ctor = 0xff fill)
  uint8_t pad_178[92];        //0x178 — slot list C (ctor = 0xff fill)
  int32_t recOffset_1d4;      //0x1D4 — record-array offset / count of list +0xC0
  uint32_t count11c_1d8;      //0x1D8 — count of slots in list +0x11C
  uint32_t count178_1dc;      //0x1DC — count of slots in list +0x178
  uint8_t subObj_1e0[0x10];   //0x1E0 — sub-object (init FUN_710062ee28)
  uint8_t tail_1f0[0x60];     //0x1F0 — tail: f32 -98.0 pairs (type<=1, sub 0/7/8)
  uint8_t idList_250[0x120];  //0x250 — u32 -1 at every +0xc stride (25 stores:
                              //      0x250,0x25c..0x370); inner 8/12 B unproven
  uint32_t idTail_370;        //0x370 — u32 -1 (final store, ends 0x374)
  uint8_t pad_374[0x4];       //0x374 — to allocation end 0x378 (new at 0x2bd4)
};

// Trans-channel write descriptor passed as x2 to FUN_71007b5370.
struct TransWriteDesc {
  uint8_t pad_00[0x4];    //0x00 — head pad to the index word
  uint32_t lastIndex_04;  //0x04 — last sample index (minus 1 if flag_10)
  void* writer_08;        //0x08 — frame writer object (max kf count [w+0xb0])
  uint8_t flag_10;        //0x10 — nonzero: lastIndex is decremented
  uint8_t pad_11[0x7];    //0x11 — to the workspace pointer at +0x18
  void* workspace_18;     //0x18 — workspace W (*W = *(W+8) before call;
                          //        RDP mask = *W; +0x10 = consumed kf count)
};

// Frame-record layout from ghostFrameRecordBuild_7100a7b414 (mode != 0);
// consumed by apply() FUN_71006ada8c.
struct GhostFrameRecord {
  uint32_t flags_00;     //0x00 — in[+0x24] & 0x0f870000
  uint8_t pad_04[0xc];   //0x04 — to the 12 B snapshot at +0x10
  float snapshot_10[2];  //0x10 — {in[+0x28].f0, in[+0x28].f1} verbatim
  uint32_t snapshot_18;  //0x18 — in[+0x30].u32 verbatim
  uint32_t pad_1c;       //0x1C — pad to the matrix at +0x20
  float m_20[16];        //0x20 — Euler XYZ matrix (q11/q20/q0 rows);
                         //      out+0x50 = input group B verbatim
};

// GhostStreamSession — FUN_71008754c0 state machine (reached via
// FUN_7100874cb0/74d68 from loader tick FUN_71004a8978).
struct GhostStreamSession {
  uint8_t pad00[0x38];
  void* region_38;        // 0x038 — region base
  uint32_t busy_40;       // 0x040 — busy flag
  uint32_t state_44;      // 0x044 — 0 open-pending / 1 discard / 2 close
  uint32_t size_48;       // 0x048 — size
  uint8_t forceClose_50;  // 0x050 — force-close
  uint8_t pad51[0x1af];
  void* stream_200;      // 0x200 — stream ptr
  uint8_t openFlag_208;  // 0x208 — flag forwarded after open
  uint8_t pad209[0x27];
  int32_t cursor_230;  // 0x230 — cursor (init -1)
};

// Side unit index (read/playback path): doc/recorder/GhostCodec.md
}  // namespace recorder
