# ParamChannelVt3998

ParamChannelVt3998 — address-anchored name (vptr 0x12b3998, GOT cell
0x130db38 holds 0x12b3988 = vt-0x10). LAZY-resolver channel type of the
0x66496c cluster (sibling of ParamChannelVt38f8/0x12b38f8 and
ParamChannelVt39d8/0x12b39d8 whose cell is the adjacent 0x130db40).
Extent >= 0x170 — cluster shape; the tail beyond 0x170 is unmapped
(unverified).

## Identity

- No static vptr store init inside a per-class C1 was found; the vptr is
  materialized as cell+0x10 at runtime.
- Slot row (vptr 0x12b3998): slot0 D1 0x71006617b8 / slot1 D0 0x71006617bc
  (both unrecovered, inside the merged region 0x71006615fc
  vt3868ClampResolutionSlot12), slots 2-5 0x7100661820/0x710066182c/
  0x7100661838/0x7100661840 (unrecovered), slot8 0x7100661c4c
  (unrecovered), slot9 D2 0x7100661d30 (paramChannelVt39d8DtorSlot1 —
  shared with the Vt39d8 sibling), then the proven cluster tail:
  slot10 Equals 0x710066496c, slot11 CopyFrom 0x71006649ec,
  slot12 0x7100664b18 (unrecovered), slot13 Serialize 0x71006630dc,
  slot14 Parse 0x7100663c94.

## Construction / init order

- Site FUN_710004495c (0x710004499c-0x71000449b8): loads GOT cell
  0x130db38, stores cell+0x10 (0x12b3998) at [container+0x38] and the
  primary cell 0x130db30+0x10 (0x12b37d8) at [container+0x00]; the
  container is zero-filled through +0xb8 with a {ptr,count=10} pair at
  +0x80 and sub-allocations at +0xb0 (extent of the container >= 0xb8,
  unverified beyond).
- Slot code lives in the shared merged region 0x71006615fc, as with the
  whole lazy-cluster family.

## Member notes

- Layout below 0x170 mirrors the proven Vt38f8 shape (own region 0x20..0x107,
  count 0x108, elems 0x110, resolver blobs 0x11c/0x160) but the per-field
  writes for this specific type are unverified — only the vptr install site
  and the shared slot tail are proven for 0x12b3998.
