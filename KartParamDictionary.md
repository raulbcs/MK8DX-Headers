# KartParamDictionary.md — KartParamCache parameter tree

One-shot compilation of the ctor string-pair evidence for the `object::KartParamCache*` /
`object::ParamNode*` / `object::ParamChannel*` family.

- Sources: docblocks of `include/object/Kart/*.hpp` plus the EN/JP + `Min=...,Max=...` string
  literals they cite in the binary (`~/projects/mk8dx-400/data/main.elf`, LOAD2
  off 0xb55ed8 → va 0xb56000; string addresses below are file offsets in the rodata
  window 0xef8f00–0xf1f300, verified with `strings`/`dd`).
- Child registration mechanism: channel-pair ctor 0x7100662f30 (KartParamCacheChanBase) +
  0x7100662f70 (field writer); param identity for nameless nodes = runtime hash 0x710062fd48.
- "—" = not recovered from the binary (string exists without JP counterpart / without bounds).
- Offsets are field offsets only where the header mapped them (`header:line` given);
  most caches are byte-blob extents, so most rows have no offset.

Named root caches: 24 headers with ctor string evidence. Unnamed (address-anchored,
runtime-hash identity): 68 headers — listed in the last section.

---

## 1. aglenv — Env / EnvSet (lights)

Root: `KartParamCacheEnv` (env base, ctor 0x710064822c, extent 0x38); containers
`KartParamCacheEnvSet` (tag `aglenvset` @ 0xef8fee) and EnvObj node. Strings `aglenv`
@ 0xef8f16, `EnvSet`/`setting`/`env_obj_ref_array` @ 0xef8f9a–0xef8fba.

Light-type names (config block @ 0xef9078–0xef9115): `AmbientLight`, `HemisphereLight`,
`DirectionalLight`, `PointLight`, `SpotLight`.

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| Damp | float | Damp | (ダンプ) | 0 | 4 (`Min=0,Max=4` @ 0xef906c) | — | `ParamNodeDirectionalLight.hpp:7` |
| Direction | vec3 | Direction | (方向) | — | — | — | `ParamNodeDirectionalLight.hpp:7` |
| Intensity | float | Intensity | (強度) | 0 | 8 (@ 0xef9171) | — | `ParamNodeDirectionalLight.hpp:7` |
| SkyColor | color | SkyColor | (空色) | 0 | 8 | — | `ParamNodeDirectionalLight.hpp:7` |
| GroundColor | color | GroundColor | (地面色) | 0 | 8 (`Min=0 ,Max=8` @ 0xef922c) | — | `ParamNodeDirectionalLight.hpp:7` |
| DiffuseColor | color | DiffuseColor | (拡散色) | — | — | — | strings 0xef91be |
| SpecularColor | color | SpecularColor | (鏡面色) | — | — | — | strings 0xef91e7 |
| BacksideColor | color | BacksideColor | (裏面色) | — | — | — | strings 0xef920e |
| ViewCoordinate | bool/int | ViewCoordinate | (視座標系) | — | — | — | strings 0xef9239 |
| Radius | float | Radius | (半径) | — | — | — | strings 0xef9268 |
| DampParam | float | DampParam | (減衰ﾊﾟﾗﾒｰﾀ) | — | — | — | strings 0xef9276 |
| Length | float | Length | (長さ) | — | — | — | strings 0xef9280 |
| Angle | float | Angle | (角度) | — | — | — | strings 0xef928e |
| DistDamp | float | DistDamp | (距離減衰) | — | — | — | strings 0xef92a1 |
| AngleDamp | float | AngleDamp | (角度減衰) | — | — | — | strings 0xef92b7 |

## 2. aglccr — ColorCorrection

Root: `KartParamCacheColorCorrection` (vptr 0x12b30a8, ctor 0x710064fb3c, extent 0x1a30);
MI subobject `KartParamCacheColorCorrectionSub` (vptr 0x12b30b8). Tag `aglccr` @ 0xef92ce.
Channel-pair members from 0x200 (names 0xef8f59/0xef8f60, cell 0x130d908 = KartParamCacheChan vptr slot).

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| hue | float | hue | (色相) | -180 | 180 (`Min=-180, Max=180` @ 0xef92e0) | — | `KartParamCacheColorCorrection.hpp:7` |
| saturation | float | saturation | 彩度 (0xef92fd) | 0 | 2 (`Min=0, Max=2` @ 0xef9304) | — | `KartParamCacheColorCorrection.hpp:7` |
| brightness | float | brightness | (明度) | — | — | — | `KartParamCacheColorCorrection.hpp:7` |
| gamma | float | gamma | (ガンマ) | 0.25 | 4 (`Min=0.25, Max=4` @ 0xef9339) | — | `KartParamCacheColorCorrection.hpp:7` |
| order_toycam_hsb | — | order_toycam_hsb | — | — | — | — | strings 0xef9349 |
| toycam_enable | bool | toycam_enable | — | — | — | — | `KartParamCacheColorCorrection.hpp:7` |
| toycam_offset1 | vec2 | toycam_offset1 | — | 0 | 1 (`Min=0, Max=1` @ 0xef93e3) | — | strings 0xef93b8 |
| toycam_offset2 | vec2 | toycam_offset2 | — | 0 | 1 | — | strings 0xef93f0 |
| toycam_level1 | float | toycam_level1 | — | — | — | — | strings 0xef941b |
| toycam_level2 | float | toycam_level2 | — | — | — | — | strings 0xef943c |
| toycam_saturation1 | float | toycam_saturation1 | 彩度 (0xef9470) | — | — | — | strings 0xef945d |
| toycam_saturation2 | float | toycam_saturation2 | 彩度 (0xef948d) | — | — | — | strings 0xef947a |
| toycam_brightness | float | toycam_brightness | — | — | — | — | strings 0xef9497 |
| toycam_contrast | float | toycam_contrast | — | — | — | — | strings 0xef94a9 |
| toycam_mul_color | color | toycam_mul_color | — | — | — | — | strings 0xef94cc |
| level | float | level | — | — | — | — | strings 0xef94ed |

Display name `color_correction` @ 0xef950e, class `agl::pfx::ColorCorrection` @ 0xef951f.

## 3. aglfila — FilterAA

Root: `KartParamCacheFilterAA` (vptr 0x12b3130, ctor 0x7100651ae4, extent 0x5e8).
Channel: `ParamChannelFilterAA` (vptr 0x12b3218). Tag `aglfila` @ 0xef9539.

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| antialias_type | int | antialias_type | — | — | — | — | `KartParamCacheFilterAA.hpp:7` |
| fxaa_detect_edge_qa | float | fxaa_detect_edge_qa | — | — | — | — | `KartParamCacheFilterAA.hpp:7` |
| fxaa_fetcht_qa | float | fxaa_fetcht_qa | — | — | — | — | strings 0xef9583 |
| subpix_param | float | subpix_param | — | 0.0 | 0.5, Mode=MinMaxLock (@ 0xef95fb) | — | `KartParamCacheFilterAA.hpp:7` |
| max_span | float | max_span | (最大ｽﾊﾟﾝ) | 0.0 | 5.0 (@ 0xef9642) | — | `KartParamCacheFilterAA.hpp:7` |
| span_multiply | float | span_multiply | — | 0.1 | 5.0 (@ 0xef967b) | — | strings 0xef9657 |
| span_minimum | float | span_minimum | — | 0.0 | 0.1 (@ 0xef96cc) | — | strings 0xef9690 |
| fxaa_reprojection | bool | fxaa_reprojection | — | — | — | — | strings 0xef96e1 |
| fxaa_reprojection_move_limit | float | fxaa_reprojection_move_limit | (最大追跡距離) | 1 | 16 (@ 0xef9769) | — | strings 0xef970f |
| depth_mask_func | int | depth_mask_func | — | — | — | — | strings 0xef977b |
| depth_mask_reference | float | depth_mask_reference | — | 0.0 | 1.0 (@ 0xef97d5) | — | strings 0xef97a7 |

Display name `FilterAA` @ 0xef97f4.

## 4. aglmf — MultiFilter family

Root container `KartParamCacheMid` (+ `MultiFilterReduce`/`MultiFilterExpand`/
`MultiFilterBlur`/`MultiFilterColorCorrection`/`MultiFilterTrimming`/
`MultiFilterColorDrift`/format). Tag `aglmf` @ 0xef993e, name `mf_root_param` @ 0xef99aa.
Sub-tags: `expand` 0xef9ad0, `blur` 0xef9ad7, `change_format` 0xef9adc, `color_drift`
0xef9aea, `trimming` 0xef9af6, `active` 0xef9aff, `save_index` 0xef9b06, `param_array` 0xef9b11.

### 4a. MultiFilterReduce / MultiFilterExpand (`KartParamCacheMid`-derived, w1=0/1 → Vt3508/Vt3598)

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| offset_adjust | float | offset_adjust | (位置調整) | -10 | 10 (`Min=-10, Max=10` @ 0xef9c10) | — | strings 0xef9bb7 |
| reduce_scale | float | reduce_scale | (縮小率) | — | — | — | strings 0xef9bde |

`MultiFilterReduce` @ 0xef9bfe; `MultiFilterExpand` @ 0xef9c33.

### 4b. MultiFilterBlur (`KartParamCacheMultiFilterBlur`, vptr 0x12b3628, ctor 0x710065ffec, w1=2)

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| blur_type | int | blur_type | — | — | — | — | `KartParamCacheMultiFilterBlur.hpp:7` |
| blur_num | int | blur_num | — | 0 | 10 (`Min=-0, Max=10` @ 0xef9cbd) | — | `KartParamCacheMultiFilterBlur.hpp:7` |
| gaussian_kernel | float | gaussian_kernel | (ｶｰﾈﾙ) | — | — | — | `KartParamCacheMultiFilterBlur.hpp:7` |

### 4c. MultiFilterFormat (`KartParamCacheMultiFilterFormat`, vptr 0x12b3748, ctor 0x710066092c, w1=4)

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| format | int | format | — | — | — | — | `KartParamCacheMultiFilterFormat.hpp:7` |
| comp_sel_r | int | comp_sel_r | — | — | — | — | `KartParamCacheMultiFilterFormat.hpp:7` |
| comp_sel_g | int | comp_sel_g | — | — | — | — | strings 0xef9d0e |
| comp_sel_b | int | comp_sel_b | — | — | — | — | strings 0xef9d1b |
| comp_sel_a | int | comp_sel_a | — | — | — | — | strings 0xef9d26 |

### 4d. MultiFilterColorDrift (`KartParamCacheMultiFilterColorDrift`, vptr 0x12b37d8, ctor 0x7100660cc4, w1=5)

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| drift_r | float | drift_r | — | — | — | — | `KartParamCacheMultiFilterColorDrift.hpp:7` |
| drift_g | float | drift_g | — | — | — | — | strings 0xef9d43 |
| drift_b | float | drift_b | — | — | — | — | strings 0xef9d53 |

### 4e. MultiFilterTrimming

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| trim_center | vec2 | trim_center | — | -1.0 | 1.0 (`Min=-1.0, Max=1.0` @ 0xef9dbe) | — | strings 0xef9d79 |
| trim_scale | float | trim_scale | — | 0.0 | 1.0 (`Min=0.0, Max=1.0` @ 0xef9dd0) | — | strings 0xef9d92 |

## 5. agllmap — LightMap

Root: `KartParamCacheLightMap` (vptr 0x12b48f8, ctor 0x678808). Tag `agllmap` @ 0xefa518.

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| lightmap_array | array | lightmap_array | — | — | — | — | strings 0xefa520 |
| lut_param | group | lut_param | — | — | — | — | strings 0xefa52f |
| lightmap_lut | curve | lightmap_lut | — | — | — | — | strings 0xefa539 |
| name%d | string | name%d | — | — | — | — | strings 0xefa546 |
| intensity%d | float | intensity%d | — | — | — | — | strings 0xefa54d |
| curve types | — | Lambert / Half-Lambert / Hemisphere | — | — | — | — | strings 0xefa559–0xefa56e |
| UserData%d | string | UserData%d | — | — | — | — | strings 0xefa579 |
| lightmap_sphere_normal | bool | lightmap_sphere_normal | — | — | — | — | strings 0xefa58d |
| lightmap_cube_normal | bool | lightmap_cube_normal | — | — | — | — | strings 0xefa5a4 |
| SpecularCurve | curve | SpecularCurve | — | — | — | — | strings 0xefa5b9 |

Related ProjLight block @ 0xefa778: `shadow_map_type` (JP `Shadow Map Type`),
`size_w` (Min=32,Max=2048 @ 0xefa7ad), `size_h`, `reduce_type`, `enable_hiz`,
`force_array`, `use_16_unorm`, `alloc_without_ctx`, `alloc_from_mem1`,
`expand_to_mem2`, `expand_all_slice`, `scissor`, `create_half`,
`half_size_cascade_num` (Min=-1,Max=4 @ 0xefa949), `create_quarter`,
`quater_size_cascade_num`, `reduce_mem1`, `scissor_margin`, `shadow_map_depth`,
`shadow_map_expand_mem2`, `shadow_map_reduce_depth`.

## 6. gsysdclao — DecalAo

Root: `KartParamCacheDecalAo` (vptr 0x12f2be0, ctor 0xa9a2e0, name `DecalAoMgr` @ 0xf1a857).
Tag `gsysdclao` @ 0xefe4aa.

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| DrawOffsetY | float | DrawOffsetY | (Y軸ｵﾌｾｯﾄ) | — | — | — | strings 0xefe4b4 |
| BlurLevel | int | BlurLevel | — | — | — | — | strings 0xefe4ce |
| UpDistance | float | UpDistance | — | -20 | 20 (@ 0xefe609) | — | strings 0xefe4e8 |
| DownDistance | float | DownDistance | — | -20 | 20 | — | strings 0xefe50f |
| DistanceMax | float | DistanceMax | — | 0 | 30 (@ 0xefe63d) | — | strings 0xefe538 |
| RenderOffsetPos | vec3 | RenderOffsetPos | (座標ｵﾌｾｯﾄ) | -30 | 30 (@ 0xefe64e) | — | strings 0xefe55d |
| ScaleX | float | ScaleX | — | 0 | 2 (@ 0xefe661) | — | strings 0xefe580 |
| ScaleZ | float | ScaleZ | — | 0 | 2 | — | strings 0xefe595 |
| Alpha | float | Alpha | — | 0 | 1 (@ 0xefe62d) | — | strings 0xefe5aa |
| BaseScale | float | BaseScale | — | — | — | — | strings 0xefe5bd |

## 7. aglsdw — Shadow

Root: `KartParamCacheShadow` (vptr 0x12f3e90, ctor 0xad90e8). Tag `aglsdw` @ 0xf1d98d.

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| cascade_num | int | cascade_num | (ｷｬｽｹｰﾄﾞ数) | 1 | 8 (`Min=1, Max=8` @ 0xf1d9c7) | — | `KartParamCacheShadow.hpp:7` |
| mip_level_num | int | mip_level_num | — | 1 | 8 | — | `KartParamCacheShadow.hpp:7` |
| depth_clamp | bool | depth_clamp | (深度ｸﾗﾝﾌﾟ) | — | — | — | `KartParamCacheShadow.hpp:7` |
| bounding_calc_type | int | bounding_calc_type | — | — | — | — | strings 0xf1d9ec |
| optimize_offset_near | float | optimize_offset_near | — | — | — | — | strings 0xf1da12 |
| optimize_offset_far | float | optimize_offset_far | — | — | — | — | strings 0xf1da3c |
| stable_texel_width | int | stable_texel_width | — | 1 | 32 (`Min=1, Max=32` @ 0xf1da8a) | — | `KartParamCacheShadow.hpp:7` |
| cascade_near | float | cascade_near | — | — | — | — | strings 0xf1da98 |
| same_point_epsilon | float | same_point_epsilon | — | — | — | — | strings 0xf1daa5 |
| near_far_margin_array | array | near_far_margin_array | — | — | — | — | strings 0xf1dacb |
| matrix_calc_type | int | matrix_calc_type | — | — | — | — | strings 0xf1db4d |

## 8. aglprojsdw — ProjShadow

Root: `KartParamCacheProjShadow` (vptr 0x12f3f60, ctor 0xade480). Tag `aglprojsdw` @ 0xf1db6f.

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| bias_scale | float | bias_scale | (ｽｹｰﾙ) | -2 | 2 (`Min=-2, Max=2` @ 0xf1dcf6) | — | `KartParamCacheProjShadow.hpp:7` |
| anim_trans_vel | float | anim_trans_vel | — | -1 | 1, MinMaxLock (@ 0xf1dd04) | — | strings 0xf1db9e |
| anim_swing_cyc_x | float | anim_swing_cyc_x | — | 0 | 1000 (@ 0xf1dd23) | — | `KartParamCacheProjShadow.hpp:7` |
| anim_swing_cyc_y | float | anim_swing_cyc_y | — | 0 | 1000 | — | strings 0xf1dc06 |
| anim_swing_amp | float | anim_swing_amp | — | 0 | 1000 | — | strings 0xf1dc3a |
| bias_trans | vec2 | bias_trans | — | — | — | — | strings 0xf1dc68 |
| anim_rot_speed | float | anim_rot_speed | (回転速度) | — | — | — | strings 0xf1dc8c |
| bias_rotate | float | bias_rotate | — | — | — | — | strings 0xf1dcb7 |
| repeat | int | repeat | — | — | — | — | strings 0xf1dcdd |

## 9. aglshpp — ShadowPP (post-process shadow)

Root: `KartParamCacheShadowPP` (vptr 0x12f4050, ctor 0xae2f64). Tag `aglshpp` @ 0xf0277d.
Block @ 0xf1dd7c–0xf1e42b.

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| is_outputLinearSampler | bool | is_outputLinearSampler | — | — | — | — | `KartParamCacheShadowPP.hpp:7` |
| screenSpaceBlurType | int | screenSpaceBlurType | — | — | — | — | `KartParamCacheShadowPP.hpp:7` |
| screenSpaceBlurWidth | int | screenSpaceBlurWidth | — | 0 | 12 (@ 0xf1e53f) | — | strings 0xf1ddce |
| mScreenSpaceBlurRepNum | int | mScreenSpaceBlurRepNum | — | 0 | 5 (@ 0xf1e573) | — | strings 0xf1de02 |
| pcfWidth | int | pcfWidth | (PCF幅) | 1 | 20 (@ 0xf1e583) | — | `KartParamCacheShadowPP.hpp:7` |
| noiseWidth | float | noiseWidth | — | 0 | 50.0 (@ 0xf1e5bb) | — | strings 0xf1de32 |
| is_edgeCutoff | bool | is_edgeCutoff | — | — | — | — | strings 0xf1de53 |
| edgeCutoffThreshold | float | edgeCutoffThreshold | — | 0 | 5.0 (@ 0xf1e5a9) | — | strings 0xf1de7b |
| edgeCutoffRange | float | edgeCutoffRange | — | 0 | 1000.0 | — | strings 0xf1dea6 |
| is_useStaticDepthShadow | bool | is_useStaticDepthShadow | — | — | — | — | strings 0xf1ded3 |
| is_useDecalAo | bool | is_useDecalAo | — | — | — | — | strings 0xf1df10 |
| is_UseDecalTrailSigned | bool | is_UseDecalTrailSigned | — | — | — | — | strings 0xf1df36 |
| is_useFarFade | bool | is_useFarFade | — | — | — | — | strings 0xf1df7c |
| dynamicShadowFarFadeStart | float | dynamicShadowFarFadeStart | — | 0 | 10.0 | — | strings 0xf1dfa9 |
| dynamicShadowFarFadeEnd | float | dynamicShadowFarFadeEnd | — | 0 | 10.0 | — | strings 0xf1dff7 |
| staticShadowFarFadeStart | float | staticShadowFarFadeStart | — | 0 | 10.0 | — | strings 0xf1e043 |
| staticShadowFarFadeEnd | float | staticShadowFarFadeEnd | — | 0 | 10.0 | — | strings 0xf1e090 |
| is_useDepth2Normal | bool | is_useDepth2Normal | — | — | — | — | strings 0xf1e0db |
| is_useDepth2NormalBlur | bool | is_useDepth2NormalBlur | — | — | — | — | strings 0xf1e10d |
| normal2ShadowRatio | float | normal2ShadowRatio | — | 0 | 1.0 (@ 0xf1e561) | — | strings 0xf1e14c |
| normal2ShadowMul | float | normal2ShadowMul | — | — | — | — | strings 0xf1e18a |
| faceNormalBias | float | faceNormalBias | — | — | — | — | strings 0xf1e1c9 |
| is_useMipLevelBlur | bool | is_useMipLevelBlur | — | — | — | — | strings 0xf1e20c |
| is_useMipLevelBlurReduce | bool | is_useMipLevelBlurReduce | — | — | — | — | strings 0xf1e24a |
| mipBlurWidth | int | mipBlurWidth | — | — | — | — | strings 0xf1e294 |
| mipBlurRepNum | int | mipBlurRepNum | — | — | — | — | strings 0xf1e2d5 |
| is_usePreCombSsao | bool | is_usePreCombSsao | — | — | — | — | strings 0xf1e308 |
| is_useSsaoDirectDraw | bool | is_useSsaoDirectDraw | — | — | — | — | strings 0xf1e346 |
| is_useFarDepthTest | bool | is_useFarDepthTest | — | — | — | — | strings 0xf1e387 |
| is_farDepthTestDist | bool | is_farDepthTestDist | — | — | — | — | strings 0xf1e3bd |
| is_overSampleing | bool | is_overSampleing | — | — | — | — | strings 0xf1e3f4 |
| is_ReduceBlurWidth | bool | is_ReduceBlurWidth | — | — | — | — | strings 0xf1e43e |
| is_PcfShaderType | bool | is_PcfShaderType | — | — | — | — | strings 0xf1e47f |
| is_PcfSampleNum | bool | is_PcfSampleNum | — | — | — | — | strings 0xf1e4ad |

## 10. aglssao — Ssao

Root: `KartParamCacheSsao` (vptr 0x12f40c8, ctor 0xae7d58). Tag `aglssao` @ 0xf1e5eb.

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| radius | float | radius | (半径) | — | — | — | `KartParamCacheSsao.hpp:7` |
| ao_far | float | ao_far | — | — | — | — | `KartParamCacheSsao.hpp:7` |
| dist_attn | float | dist_attn | (距離減衰) | — | — | — | `KartParamCacheSsao.hpp:7` |
| enable_dist_attn | bool | enable_dist_attn | — | — | — | — | strings 0xf1e652 |
| enable_reprojection | bool | enable_reprojection | (過去情報利用) | — | — | — | `KartParamCacheSsao.hpp:7` |
| mix_rate | float | mix_rate | (調整) | — | — | — | `KartParamCacheSsao.hpp:7` |
| enable_rotate | bool | enable_rotate | — | — | — | — | strings 0xf1e6f0 |
| blur_quality_hi | int | blur_quality_hi | (高品質) | — | — | — | strings 0xf1e717 |
| mip_blur_quality_hi | int | mip_blur_quality_hi | — | — | — | — | strings 0xf1e73a |
| mip_blur_num | int | mip_blur_num | — | — | — | — | strings 0xf1e777 |
| sample_pair_num | int | sample_pair_num | — | 1 | — (`Min=1` @ 0xf1e7df) | — | strings 0xf1e7b6 |

## 11. agldecd — Decal + PseudoOcclusion node

Root: `KartParamCacheDecal` (vptr 0x12f42a8, ctor 0xaed234, name `DecalDrawer` @ 0xf1e87a).
Tag `agldecd` @ 0xf1e872; buffer `decal_drawer_buffer` @ 0xf1e886.
Node `ParamNodePseudoOcclusion` (vptr 0x12f4400, ctor 0xaeeec8) uses this block.

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| Position (World) | vec3 | World position | (ﾜｰﾙﾄﾞ座標) | — | — | — | `ParamNodePseudoOcclusion.hpp:7`, strings 0xf1e8a6 |
| Radius | float | Radius | (半径) | — | — | — | `ParamNodePseudoOcclusion.hpp:7` |
| CoreRadius | float | CoreRadius | (中心半径) | — | — | — | `ParamNodePseudoOcclusion.hpp:7`, strings 0xf1e8bc |
| VerticesBias | float | VerticesBias | — | — | — | — | `ParamNodePseudoOcclusion.hpp:7`, strings 0xf1e8d7 |
| DepthOffset | float | DepthOffset | (深度ｵﾌｾｯﾄ) | — | — | — | `ParamNodePseudoOcclusion.hpp:7`, strings 0xf1e8f4 |
| ScrEdgeSize | float | ScrEdgeSize | — | — | — | — | strings 0xf1e916 |
| PseudoOccl | bool | PseudoOccl | (擬似陰影) | — | — | — | `ParamNodePseudoOcclusion.hpp:7`, strings 0xf1e93e |
| IsFixPosX | bool | IsFixPosX | (X軸固定) | — | — | — | strings 0xf1e965 |
| IsFixPosY | bool | IsFixPosY | — | — | — | — | strings 0xf1e995 |
| IsFixPosZ | bool | IsFixPosZ | — | — | — | — | strings 0xf1e99f |

## 12. aglvolm — VolumeMask

Root: `KartParamCacheVolumeMask` (vptr 0x12f2d18, ctor 0xa9ca94). Tag `aglvolm` @ 0xf1a8e9.

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| shadowmap_reduce_level | int | shadowmap_reduce_level | — | 0 | 8, MinMaxLock (@ 0xf1a954) | — | `KartParamCacheVolumeMask.hpp:7` |
| depth_convolve_max | int | depth_convolve_max | — | — | — | — | strings 0xf1a978 |
| shadow_convolve_max | int | shadow_convolve_max | — | — | — | — | strings 0xf1a9ba |
| autoAdjustNear | bool | autoAdjustNear | — | — | — | — | strings 0xf1aa09 |
| layer_reduce_level | int | layer_reduce_level | — | — | — | — | strings 0xf1aa42 |
| layer_number | int | layer_number | — | 0 | 256 (`Min = 0, Max =  256` @ 0xf1aaaf) | — | strings 0xf1aa8c |
| layer_dist_nonlinear | int | layer_dist_nonlinear | — | 0 | 4 (`Min = 0, Max = 4` @ 0xf1ab00) | — | strings 0xf1aac3 |
| shadowmap_amp_low | float | shadowmap_amp_low | — | -8 | 8 (`Min = -8, Max = 8` @ 0xf1ab42) | — | strings 0xf1ab11 |
| shadowmap_amp_high | float | shadowmap_amp_high | — | -8 | 8 | — | strings 0xf1ab54 |
| shadowmap_pcf_type | int | shadowmap_pcf_type | — | — | — | — | strings 0xf1ab86 |
| range_near | float | range_near | — | 1 | 10000 (`Min = 1, Max = 10000` @ 0xf1abfb) | — | strings 0xf1abc6 |
| range_far | float | range_far | — | 1 | 10000 | — | strings 0xf1abe1 |
| render_mask_color | bool | render_mask_color | — | — | — | — | strings 0xf1ac38 |

## 13. aglclwd — Cloud (CloudTex / Cloud / CloudDraw)

Roots: `KartParamCacheCloudTex` (vptr 0x12f2ab0), `KartParamCacheCloud`
(vptr 0x12f2f40), `KartParamCacheCloudDraw` (vptr 0x12f2b28). Tag `aglclwd` @ 0xf02870.

### 13a. CloudTex (`mBaseTextureNo` block @ 0xf19f58–0xf19ff9)

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| mIsEnable | bool | mIsEnable | — | — | — | — | `KartParamCacheCloudTex.hpp:7` |
| mBaseTextureNo | int | mBaseTextureNo | — | — | — | — | `KartParamCacheCloudTex.hpp:7` |
| mNoiseTextureNo | int | mNoiseTextureNo | — | — | — | — | `KartParamCacheCloudTex.hpp:7` |
| mbCloudTexBlend | bool | mbCloudTexBlend | — | — | — | — | `KartParamCacheCloudTex.hpp:7` |
| mCloudTexBlendRate | float | mCloudTexBlendRate | — | — | — | — | `KartParamCacheCloudTex.hpp:7` |
| mBaseTextureNo_Blend | int | mBaseTextureNo_Blend | — | — | — | — | strings 0xf19fa4 |
| mNoiseTextureNo_Blend | int | mNoiseTextureNo_Blend | — | — | — | — | strings 0xf19fb9 |
| mScatterHeight | float | mScatterHeight | — | — | — | — | strings 0xf19fcf |
| mScatterAmb | float | mScatterAmb | — | — | — | — | strings 0xf19fde |
| mSunOccChkSize | int | mSunOccChkSize | — | — | — | — | strings 0xf19fea |

### 13b. Cloud noise block (`mLightSideNoiseParam` … @ 0xf1a000–0xf1a539)

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| tex_random_seed | int | tex_random_seed | — | 0 | 10000 (`Min =0, Max =10000` @ 0xf1bb84) | — | `KartParamCacheCloud.hpp:7` |
| tex_base_freq | float | tex_base_freq | (基本波数) | 0.0 | 36.0 (@ 0xf1bbb5) | — | `KartParamCacheCloud.hpp:7` |
| tex_base_freq_scale | float | tex_base_freq_scale | — | 0.0 | 1.0 (@ 0xf1bbf9) | — | strings 0xf1bbc9 |
| tex_acm | float | tex_acm | (累乗) | 0 | 10 (`Min =0, Max =10` @ 0xf1bc21) | — | strings 0xf1bc0c |
| tex_freq | float | tex_freq | — | 0 | 4.0 (@ 0xf1bc53) | — | strings 0xf1bc31 |
| tex_amp | float | tex_amp | — | 0 | 1.0 (@ 0xf1bc82) | — | strings 0xf1bc64 |
| tex_is_abs | bool | tex_is_abs | (絶対値) | — | — | — | strings 0xf1bc93 |
| tex_is_loop | bool | tex_is_loop | — | — | — | — | strings 0xf1bcbd |
| tex_loop_width | float | tex_loop_width | — | — | — | — | strings 0xf1bce8 |
| mLightSideNoiseParam | group | mLightSideNoiseParam | — | — | — | — | strings 0xf1a00d |
| mNoiseSpeed1X/1Y/2X/2Y | float | mNoiseSpeed* | — | — | — | — | strings 0xf1a07c–0xf1a0a6 |
| mNoiseScale1/2, mNoiseDensity1/2 | float | mNoise* | — | — | — | — | strings 0xf1a0b4–0xf1a0dd |
| mEmbossWidth / mEmbossDensity | float | mEmboss* | — | — | — | — | strings 0xf1a0ec–0xf1a0f9 |
| mUseProcedualTexture | bool | mUseProcedualTexture | — | — | — | — | strings 0xf1a507 |
| mUseScatter | bool | mUseScatter | — | — | — | — | strings 0xf1a51c |

### 13c. CloudDraw (`mIsDrawReduceBuffer` block @ 0xf1a542–0xf1a6f4)

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| mIsDrawReduceBuffer | bool | mIsDrawReduceBuffer | (縮小ﾊﾞｯﾌｧ) | — | — | — | `KartParamCacheCloudDraw.hpp:7` |
| mIsDisableFarClip | bool | mIsDisableFarClip | — | — | — | — | strings 0xf1a572 |
| mIsDisableDepthTest | bool | mIsDisableDepthTest | — | — | — | — | strings 0xf1a59a |
| mIsSyncSunPosition | bool | mIsSyncSunPosition | (太陽位置同期) | — | — | — | `KartParamCacheCloudDraw.hpp:7` |
| mDrawOrder | int | mDrawOrder | — | — | — | — | `KartParamCacheCloudDraw.hpp:7` |
| mCloudColorScale | color/vec4 | mCloudColorScale | — | — | — | — | `KartParamCacheCloudDraw.hpp:7` |
| mFogColor | color | mFogColor | — | — | — | — | strings 0xf1a62d |
| mFogNear | float | mFogNear | — | — | — | — | strings 0xf1a64a |
| mFogFar | float | mFogFar | — | — | — | — | strings 0xf1a661 |
| mAttenuationForSky | float | mAttenuationForSky | (空減衰) | — | — | — | strings 0xf1a676 |
| mSunOccBufSize | int | mSunOccBufSize | — | — | — | — | strings 0xf1a69f |
| CloudParam0/1/2 | float | CloudParam0..2 | — | — | — | — | strings 0xf1a6d0–0xf1a6e8 |

## 14. aglsky — Sky

Root: `KartParamCacheSky` (vptr 0x12f2fb8, ctor 0xaadfec). Tag `aglsky` @ 0xf02a37.

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| sun_indensity | float | sun_indensity | (太陽光強度) | 0.0 | 16000.0 (`Min =0.0, Max =16000.0` @ 0xf1be7c) | — | `KartParamCacheSky.hpp:7` |
| rayleigh (table_br / table_bm) | float | table_br / table_bm | (散乱係数) | 0.0 | 0.02 (@ 0xf1bfc0) | — | `KartParamCacheSky.hpp:7` |
| exposure | float | exposure | — | 0.0 | 4.0 (@ 0xf1bf09) | — | strings 0xf1bef3 |
| gnd_intensity | float | gnd_intensity | (地面強度) | — | — | — | strings 0xf1bf1c |
| scatter_near | float | scatter_near | — | 0.0 | 100.0 (@ 0xf1bf5b) | — | strings 0xf1bf3a |
| scatter_far | float | scatter_far | — | — | — | — | strings 0xf1bf70 |
| gnd_scale_ratio | float | gnd_scale_ratio | — | — | — | — | strings 0xf1bfff |
| sunlight_color | color | sunlight_color | — | — | — | — | strings 0xf1c035 |
| tex_table | texture | tex_table | — | — | — | — | strings 0xf1c02b |

## 15. aglcube — CubeMap

Root: `KartParamCacheCubeMap` (vptr 0x12f31e8, ctor 0xab868c). Tag `aglcube` @ 0xf02900,
buffer names `envmap`/`snap`/`snapenvmap` @ 0xf02911–0xf029b4.

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| cubemap_mgr | group | cubemap_mgr | — | — | — | — | `KartParamCacheCubeMap.hpp:7`, strings 0xf1c3e5 |
| cubemap_unit_%d | group | cubemap_unit_%d | — | — | — | — | strings 0xf1c3f1 |
| position | vec3 | position | — | — | — | — | strings 0xf1c0cf |
| near | float | near | — | — | — | — | strings 0xf1c0d8 |
| illuminant_dist | float | illuminant_dist | — | — | — | — | strings 0xf1c0e1 |
| gaussian_repetition_num | int | gaussian_repetition_num | — | 0 | 20 (`Min = 0, Max = 20` @ 0xf1c122) | — | strings 0xf1c0f1 |
| rendering_repetition_num | int | rendering_repetition_num | — | — | — | — | strings 0xf1c134 |
| refer_entity / refer_tex | bool | refer_entity / refer_tex | — | — | — | — | strings 0xf1c397–0xf1c3a4 |
| distance | float | distance | — | — | — | — | strings 0xf1c3ae |
| blend_type | int | blend_type | — | — | — | — | strings 0xf1c3b7 |
| hdr_coeff | float | hdr_coeff | — | — | — | — | strings 0xf1c37b |

## 16. agllref — Lref (light reflection / screen-space reflection)

Root: `KartParamCacheLref` (vptr 0x12f2ea8, ctor 0xaa3c6c). Tag `agllref` @ 0xf0283b.
Params `user_param` @ 0xf1b9ad, `sys_param` @ 0xf1b9b8; buffer names
`lr::reflection` … `lr::linear_depth_reduce` @ 0xf1b9c2–0xf1ba4c.
Full block @ 0xf1ad3d–0xf1b99a (planar reflection + raymarch + filters):

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| user_param | group | user_param | — | — | — | — | `KartParamCacheLref.hpp:7`, strings 0xf1b9ad |
| sys_param | group | sys_param | — | — | — | — | `KartParamCacheLref.hpp:7`, strings 0xf1b9b8 |
| enable_planar_reflection | bool | enable_planar_reflection | — | — | — | — | strings 0xf1ad3d |
| plane_y_height | float | plane_y_height | — | — | — | — | strings 0xf1ad6c |
| enable_refl_color | bool | enable_refl_color | — | — | — | — | strings 0xf1ad96 |
| use_RGBA8_refrection_buffer | bool | use_RGBA8_refrection_buffer | — | — | — | — | strings 0xf1add0 |
| use_PreColorBufferReduce / Blur | bool | — | — | — | — | — | strings 0xf1ae1f–0xf1ae59 |
| reflection_intensity | float | reflection_intensity | — | — | — | — | strings 0xf1ae8b |
| reflection_render_scale | float | reflection_render_scale | — | — | — | — | strings 0xf1aece |
| raymarch_linear | bool | raymarch_linear | — | — | — | — | strings 0xf1af11 |
| raymarch_iter | int | raymarch_iter | — | 1 | 8 (`Min = 1.0, Max = 8.0` @ 0xf1bace) | — | strings 0xf1af3a |
| enable_mask_pass | bool | enable_mask_pass | — | — | — | — | strings 0xf1af64 |
| enable_reflect_cache | bool | enable_reflect_cache | — | — | — | — | strings 0xf1afb5 |
| enable_hi_z | bool | enable_hi_z | — | — | — | — | strings 0xf1b01f |
| enable_roughness | bool | enable_roughness | — | — | — | — | strings 0xf1b039 |
| roughness_thre | float | roughness_thre | — | 0.0 | 4.0 (@ 0xf1bb06) | — | strings 0xf1b075 |
| enable_reverse_reproj | bool | enable_reverse_reproj | — | — | — | — | strings 0xf1b0af |
| enable_reflection_uv | bool | enable_reflection_uv | — | — | — | — | strings 0xf1b0f6 |
| enable_reflection_weight | bool | enable_reflection_weight | — | — | — | — | strings 0xf1b19a |
| occ_scale | float | occ_scale | — | — | — | — | strings 0xf1b22f |
| reproj_param | vec4 | reproj_param | — | — | — | — | strings 0xf1b25e |
| reduce_filter | int | reduce_filter | — | 1 | 3 (`Min = 1, Max = 3` @ 0xf1baf5) | — | strings 0xf1b26b |
| enable_gausian_blur | bool | enable_gausian_blur | — | — | — | — | strings 0xf1b279 |
| gaussian_type / blur_kernel_type2 | int | — | — | — | — | — | strings 0xf1b28d–0xf1b29b |
| filter_param0..3 | float | filter_param0..3 | — | — | — | — | strings 0xf1b2c5–0xf1b30e |
| filter_num | int | filter_num | — | — | — | — | strings 0xf1b3d3 |
| enable_pull_linear / push_linear / reverse_filter | bool | — | — | — | — | — | strings 0xf1b403–0xf1b483 |
| force_depth2normal | bool | force_depth2normal | — | — | — | — | strings 0xf1b4c7 |
| normal_buffer_scale | float | normal_buffer_scale | — | — | — | — | strings 0xf1b517 |
| enable_depth_min_max | bool | enable_depth_min_max | — | — | — | — | strings 0xf1b5a4 |
| depth_min_max_mip_num | int | depth_min_max_mip_num | — | — | — | — | strings 0xf1b5e4 |
| depth_min_max_thre | float | depth_min_max_thre | — | — | — | — | strings 0xf1b631 |
| reflection_mip_num | int | reflection_mip_num | — | — | — | — | strings 0xf1b67b |
| normal_texture_mode | int | normal_texture_mode | — | — | — | — | strings 0xf1b6c5 |
| depth_hit_thre | float | depth_hit_thre | — | 0.1 | 1.0 (`Min = 0.1, Max = 1.0` @ 0xf1ba75) | — | strings 0xf1b704 |
| depth_hit_end_thre | float | depth_hit_end_thre | — | 0.0 | 0.01 (@ 0xf1ba8a) | — | strings 0xf1b738 |
| depth_hit_begin_dst | float | depth_hit_begin_dst | — | 0.0 | 10.0 (@ 0xf1baa0) | — | strings 0xf1b779 |
| ray_march_scale | float | ray_march_scale | — | 1.0 | 1000.0 (@ 0xf1bab6) | — | strings 0xf1b7ac |
| max_view_distance | float | max_view_distance | — | — | — | — | strings 0xf1b7e4 |
| view_distance_pow | float | view_distance_pow | — | — | — | — | strings 0xf1b80f |
| enable_ray_jitter | bool | enable_ray_jitter | — | — | — | — | strings 0xf1b833 |
| ray_march_loop_type | int | ray_march_loop_type | — | — | — | — | strings 0xf1b86a |
| enable_temp_filter | bool | enable_temp_filter | — | — | — | — | strings 0xf1b8a3 |
| weight_scale / pre_blend_weight | float | — | — | 0.0 | 1.0 (@ 0xf1ba8a range) | — | strings 0xf1b8d3–0xf1b8f6 |
| fresnel_thre | float | fresnel_thre | — | — | — | — | strings 0xf1b941 |
| mask_normal_weight_thre | float | mask_normal_weight_thre | — | — | — | — | strings 0xf1b964 |

## 17. gsysbgb — Bgb (background blur + edge)

Root: `KartParamCacheBgb` (vptr 0x12bd030, ctor 0x710071d134, extent 0x338).
Tag `gsysbgb` @ 0xf0576c. Block @ 0xf05774–0xf05e36.

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| scale | float | scale | — | — | — | — | `KartParamCacheBgb.hpp:7`, strings 0xf05774 |
| blur_offset | float | blur_offset | (位置調整) | -0.5 | 0.5 (`Min=-0.5, Max=0.5` @ 0xf05e8d) | — | `KartParamCacheBgb.hpp:7`, strings 0xf057d7 |
| expand_blur_offset | float | expand_blur_offset | — | -0.1 | 0.1 (@ 0xf05e7b) | — | `KartParamCacheBgb.hpp:7`, strings 0xf05796 |
| blur_iter_num | int | blur_iter_num | — | 0 | 10 (`Min=0,Max=10` @ 0xf0589e) | — | strings 0xf0580b |
| enable_expand_blur | bool | enable_expand_blur | (拡大) | 0 | 1 (`Min=0,Max=1` @ 0xf05892) | — | `KartParamCacheBgb.hpp:7`, strings 0xf05819 |
| background_buffer | — | background_buffer | (BackGroundBuffer) | — | — | — | `KartParamCacheBgb.hpp:7`, strings 0xf05842 |
| bg_buffer_color / bg_buffer_depth / bg_blur_temp | buffer | — | — | — | — | — | strings 0xf05865–0xf05885 |
| edge_effect_type | int | edge_effect_type | (種類) | — | — | — | strings 0xf058ab |
| edge_detect_type | int | edge_detect_type | — | — | — | — | strings 0xf058de |
| edge_rel_thre | float | edge_rel_thre | — | 0.0 | 5.0 (@ 0xf05e6a) | — | strings 0xf05908 |
| edge_fine_thre | float | edge_fine_thre | — | 0.0 | 5.0 | — | strings 0xf0593e |
| edge_down_scale_num | int | edge_down_scale_num | — | — | — | — | strings 0xf05972 |
| enable_edge_blur | bool | enable_edge_blur | — | — | — | — | strings 0xf059ab |
| enable_mono_color | bool | enable_mono_color | — | — | — | — | strings 0xf059f6 |
| enble_color_mask | bool | enble_color_mask | — | — | — | — | strings 0xf05a2d |
| albedo_mult_color | color | albedo_mult_color | — | 0.0 | 1.0 (`Min=0.0f, Max=1.0f` @ 0xf05eb5) | — | strings 0xf05a60 |
| color_scale | vec4 | color_scale | — | 0.0 | 10.0 (@ 0xf05ec8) | — | strings 0xf05a94 |
| edge_scale / edge_color | float/color | — | — | — | — | — | strings 0xf05ab9–0xf05ae6 |
| blur_edge_scale / blur_edge_color / blur_edge_level | float/color/int | — | — | — | — | — | strings 0xf05b10–0xf05b77 |
| plane_normal_world | vec3 | plane_normal_world | — | -0.16 | 0.16 (@ 0xf05e9f) | — | strings 0xf05baf |
| plane_world_dist | float | plane_world_dist | — | — | — | — | strings 0xf05be0 |
| edge_of_mask_scale | float | edge_of_mask_scale | — | — | — | — | strings 0xf05c1c |
| edge_reduce_buf_scale | float | edge_reduce_buf_scale | — | — | — | — | strings 0xf05c5a |
| final_blend | int | final_blend | — | — | — | — | strings 0xf05cb2 |
| blend_const_color | color | blend_const_color | — | — | — | — | strings 0xf05cbe |
| enable_indirect | bool | enable_indirect | — | — | — | — | strings 0xf05cef |
| indirect_tex_trans / _scale / _rotate | vec2/float | — | — | -0.16 | 0.16 | — | strings 0xf05cff–0xf05d84 |
| indirect_scale | float | indirect_scale | — | — | — | — | strings 0xf05d8b |
| enable_edge_rgb | bool | enable_edge_rgb | — | — | — | — | strings 0xf05da7 |
| PASS_TYPE | int | PASS_TYPE | — | — | — | — | strings 0xf05dde |

## 18. aglNmdw — NormalDrawer

Root: `KartParamCacheNormalDrawer` (vptr 0x12f2ca0, ctor 0xa9baf4, name `NormalDrawer` @ 0xf1a89d).
Tag `aglNmdw` @ 0xf1a89d.

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| is_enable | bool | is_enable | — | — | — | — | `KartParamCacheNormalDrawer.hpp:7`, strings 0xf1a8a5 |
| resolutionMode | int | resolutionMode | (解像度) | — | — | — | strings 0xf1a8af |
| Normal_drawer_buffer | buffer | Normal_drawer_buffer | — | — | — | — | strings 0xf1a8d4 |

## 19. aglofx — Ofx (lens flare)

Root: `KartParamCacheOfx` (vptr 0x12f4bb8, ctor 0xaf56f8). Tag `aglofx` @ 0xf1f13b;
binary container `baglofx` @ 0xf1f2c3.

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| TextureList / TextureInfo%d | group/array | — | — | — | — | — | `KartParamCacheOfx.hpp:7`, strings 0xf1f142–0xf1f14e |
| OfxLensFlare::Preset | group | — | — | — | — | — | strings 0xf1e9dd |
| Preset fields: TextureIdx%d, Texture2Idx%d, Position%d, Rotate%d, Intensity%d, IsSizeZoom%d, Size%d, Color%d, BlendMode%d, IsEnableDraw%d, IsEnableRotate%d, IsEnableRotateInv%d, IsEnableOccludedScaling%d, IsEnableOccludedDec%d, IsEnableOccludedAlpha%d, IsEnableRotatePos%d, RotatePosRate%d, IsEnableEdgeScaling%d, EdgeScaleRate%d, CenterPosScalingRate%d, CenterPosScalingPow%d, CenterPosAlphaRate%d, CenterPosAlphaPow%d, IsEnableOctagon%d, IsEnableAngleOcclusion%d, AngleCenter%d, AngleWidth%d, AnglePower%d, CenterPos%d, BaseAxis%d, SizeBaseScale, CoreOcclusionType, ScrEdgeType, ScrEdgePow, ScrEdgeFlash | mixed (int/float/bool/vec/color) | per-flare-element block @ 0xf1ea2b–0xf1efb5 | JP labels alongside each | 0 | 1 typical (`Min=0, Max=1`-class bounds @ 0xf1d3c5) | — | strings 0xf1e9dd–0xf1efb5 |
| RefTexName%d / IsQuarter%d | string/bool | — | — | — | — | — | strings 0xf1f2cb–0xf1f2f1 |

## 20. ParamNode* standalone nodes

### 20a. ParamNodeEnvObjName (vptr 0x12b1fc0, ctor 0x646dac)

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| name | string | name | (オブジェクト名) | — | — | — | `ParamNodeEnvObjName.hpp:7` (0xef8f59) |
| enable | bool | enable | (表示) | — | — | — | `ParamNodeEnvObjName.hpp:7` (0xef8f86) |
| EnvSet / setting / env_obj_ref_array | group | — | — | — | — | — | strings 0xef8f9a–0xef8fba |

### 20b. ParamNodeDirectionalLight (vptr 0x12b2c98, ctor 0x64d22c)

See section 1 (aglenv lights table) — SkyColor/GroundColor/Intensity/Direction
@ 0xef9183–0xef92cd, `ParamNodeDirectionalLight.hpp:7`.

### 20c. ParamNodeModelBinding (vptr 0x12be3d0, ctor 0x732d0c)

| param | type | EN | JP | min | max | offset | evidence |
|---|---|---|---|---|---|---|---|
| ModelName | string | ModelName | (モデル名) | — | — | — | `ParamNodeModelBinding.hpp:7` (0xf06f37/0xf06e0f) |
| BonePrefix | string | BonePrefix | (ボーン接頭辞) | — | — | — | `ParamNodeModelBinding.hpp:7` (0xf06f26/0xf06e26) |
| MaterialPrefix | string | MaterialPrefix | — | — | — | — | strings 0xf06e50 |

### 20d. ParamNodePseudoOcclusion (vptr 0x12f4400, ctor 0xaeeec8)

See section 11 (agldecd block) — Position/Radius/CoreRadius/VerticesBias/DepthOffset/
PseudoOccl @ 0xf1e8a6–0xf1e955, `ParamNodePseudoOcclusion.hpp:7`.

---

## 21. Unnamed nodes (runtime-hash identity)

These classes have NO name strings in the binary: identity is the runtime param-id
hash computed by 0x710062fd48 (stored at KartParamCache+0x28 by 0x7100663050).
The dictionary cannot cover their params until runtime/byname dumps exist.

### KartParamCache* caches (13)

| class (address-anchored) | vptr | GOT cell | header |
|---|---|---|---|
| KartParamCacheVt1d08 | 0x12b1d08 | 0x130d858 | KartParamCacheVt1d08.hpp |
| KartParamCacheVt24c8 | 0x12b1c30 | 0x130d960 | KartParamCacheVt24c8.hpp |
| KartParamCacheVt2668 | 0x12b2668 | 0x130d980 | KartParamCacheVt2668.hpp |
| KartParamCacheVt33b0 | 0x12f33b0 | 0x13152c8 | KartParamCacheVt33b0.hpp |
| KartParamCacheVt3508 | 0x12b3508 | 0x130daf8 | KartParamCacheVt3508.hpp |
| KartParamCacheVt3598 | 0x12b3598 | 0x130db00 | KartParamCacheVt3598.hpp |
| KartParamCacheVt36b8 | (see header) | 0x130db08 | KartParamCacheVt36b8.hpp |
| KartParamCacheVt3868 | 0x12b3868 | 0x130db10 | KartParamCacheVt3868.hpp |
| KartParamCacheVt3df8 | 0x12f3df8 | 0x13153c8 | KartParamCacheVt3df8.hpp |
| KartParamCacheVt7850 | 0x12b7850 | 0x130e240 | KartParamCacheVt7850.hpp |
| KartParamCacheVtbb800 | 0x12bb800 | 0x130e538 | KartParamCacheVtbb800.hpp |
| KartParamCacheVtbd6f8 | 0x12bd6f8 | 0x130e8a8 | KartParamCacheVtbd6f8.hpp |
| KartParamCacheVtd608 | 0x12bd608 | 0x130e8a8 | KartParamCacheVtd608.hpp |

### ParamNode* nodes (32)

ParamNodeVt2198, Vt25f0, Vt26c0, Vt2b90, Vt2df8, Vt2e50, Vt2ea8, Vt2fb0, Vt32a8,
Vt35a8, Vt3898, Vt3f08, Vt3fd8, Vt4140, Vt4510, Vt4688, Vt47a0, Vt4c70, Vt4eb8,
Vt7780, Vtaf38, Vtc848, Vtc8a0, Vtc8f8, Vtd500, Vtd558, Vtd5b0, Vtdba0, Vtde48
(each `include/object/Kart/ParamNode<suffix>.hpp`; vptr = suffix, cell per docblock).

### ParamChannel* channels (23)

ParamChannelVt20e8, Vt21f0, Vt2290, Vt2910, Vt29b0, Vt2a50, Vt2af0, Vt32b8, Vt38f8,
Vt39d8, Vt3c38, Vt3cd8, Vt4018, Vt40b8, Vt4158, Vt41f8, Vt4298, Vt4338, Vt43d8, Vt4478
(each `include/object/Kart/ParamChannel<suffix>.hpp`; all follow the shared
KartParamCacheChanBase 0x7100662f30 + writer 0x7100662f70 pair mechanism).

Tag strings present in the binary with NO mapped cache header (for future enrichment):
`aglflr` (0xf1d188, lens flare), `aglglr` (0xf1d432, glare), `agldof` (0xf026f8),
`aglatex` (0xf02813), `gsysefx` (0xf0289b), `baglenv`/`baglenvset`/`baglblm`/`baglccr`
etc. (binary-container mirrors of the agl* tags, 0xf02655–0xf02a7c).
