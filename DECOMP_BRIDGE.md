# Decomp bridge

Decomp symbols (from `mk8dx-400/data/file_list.yml`) crossed by address with ctor/factory anchors in `tools/usage.db`. No renames applied — suggestions only.

**Summary: 4 rename-ready FUN_* anchors (decompiled, status Matching), covering 10.3% of the 39 matched anchors.**

## Rename-ready (symbol already decompiled)

| Decomp symbol | Class(es) | Anchor | Suggested name | Uses |
|---|---|---|---|---|
| `FUN_710061cc48` | `KartParamCacheMid2`, `KartParamCacheVtd608` | ctor @ 0x61cc48 | `KartParamCacheMid2_ctor (shared ctor)` | 24 |
| `FUN_71007b976c` | `RaceDirectorVt01e8`, `RaceDirectorVt5758`, `RaceDirectorVta260` | ctor @ 0x7b976c | `RaceDirectorVt01e8_ctor (shared ctor)` | 12 |
| `FUN_71007c27bc` | `RaceDirectorVt5758` | ctor @ 0x7c27bc | `RaceDirectorVt5758_ctor` | 12 |
| `NetworkEngine::preSceneCalc` | `NetworkSendThread` | ctor @ 0x835608 | `NetworkSendThread_ctor` | 2 |

## Matched but not yet decompiled

| Decomp symbol | Status | Class(es) | Anchor | Suggested name |
|---|---|---|---|---|
| `FUN_710066a2a4` | NotDecompiled | `KartParamCacheFilterAA`, `KartParamCacheMid`, `KartParamCacheVt2668`, `KartParamCacheVtbb800`, `KartParamCacheVtbd6f8`, `KartParamCacheVtd608`, `ParamNodeVt2198` | ctor | `KartParamCacheFilterAA_ctor (shared ctor)` |
| `FUN_7100728074` | NotDecompiled | `KartParamCacheVtd608` | ctor | `KartParamCacheVtd608_ctor` |
| `FUN_7100727a60` | NotDecompiled | `KartParamCacheVtd608` | ctor | `KartParamCacheVtd608_ctor` |
| `FUN_7100727d54` | NotDecompiled | `KartParamCacheVtd608` | ctor | `KartParamCacheVtd608_ctor` |
| `FUN_7100662f30` | NotDecompiled | `KartParamCacheChan`, `KartParamCacheChanBase`, `KartParamCacheMid`, `KartParamCacheMultiFilterBlur`, `KartParamCacheMultiFilterColorDrift`, `KartParamCacheMultiFilterFormat`, `ParamMultiChanVt2808`, `ParamMultiChanVt2c40`, `ParamMultiChanVt2da0`, `ParamMultiChanVtb318`, `ParamMultiChanVtba40`, `ParamMultiChanVtbb50`, `ParamMultiChanVtbdb8`, `ParamMultiChanVtc0f0`, `ParamMultiChanVtc200`, `ParamMultiChanVtc468`, `ParamMultiChanVtd7b0`, `ParamMultiChanVtd900`, `ParamMultiChanVtda50`, `ParamNodeVt2198`, `ParamNodeVt25f0`, `ParamNodeVt26c0`, `ParamNodeVt2df8`, `ParamNodeVt2e50`, `ParamNodeVt3f08`, `ParamNodeVt3fd8`, `ParamNodeVt4140`, `ParamNodeVt4c70`, `ParamNodeVt4eb8`, `ParamNodeVt7780`, `ParamNodeVtc848`, `ParamNodeVtc8a0`, `ParamNodeVtc8f8`, `ParamNodeVtd500`, `ParamNodeVtd558`, `ParamNodeVtd5b0` | ctor | `KartParamCacheChan_ctor (shared ctor)` |
| `FUN_710065efbc` | NotDecompiled | `KartParamCacheColorCorrection`, `KartParamCacheColorCorrection`, `KartParamCacheMid`, `KartParamCacheMid`, `KartParamCacheMultiFilterBlur`, `KartParamCacheMultiFilterBlur`, `KartParamCacheMultiFilterColorDrift`, `KartParamCacheMultiFilterColorDrift`, `KartParamCacheMultiFilterFormat`, `KartParamCacheMultiFilterFormat`, `KartParamCacheVt3508`, `KartParamCacheVt3508`, `KartParamCacheVt3598`, `KartParamCacheVt3598`, `KartParamCacheVt36b8`, `KartParamCacheVt36b8`, `KartParamCacheVt3868`, `KartParamCacheVt3868` | ctor+factory | `KartParamCacheColorCorrection_ctor (shared ctor)` |
| `FUN_710065ede8` | NotDecompiled | `KartParamCacheMid` | ctor | `KartParamCacheMid_ctor` |
| `FUN_71007c55cc` | NotDecompiled | `RaceDirectorVt5758`, `RaceDirectorVt5758` | ctor+factory | `RaceDirectorVt5758_ctor (shared ctor)` |
| `FUN_7100628a54` | NotDecompiled | `AudioTaskThread`, `BackgroundLoadThread`, `ContentsThread`, `CourseDecompThread`, `LowPrioWorkerThread`, `NetworkTaskThread`, `OeMessageDispatchThread`, `SZSThread`, `SaveDataManagerThread`, `Thread`, `TimeSyncThread`, `UIMiiThread`, `UINFPThread`, `UITheaterThread` | ctor | `AudioTaskThread_ctor (shared ctor)` |
| `FUN_71006fe734` | NotDecompiled | `KartParamCacheVtbb800` | ctor | `KartParamCacheVtbb800_ctor` |
| `FUN_710064fb3c` | NotDecompiled | `KartParamCacheColorCorrection` | ctor | `KartParamCacheColorCorrection_ctor` |
| `FUN_7100668d40` | NotDecompiled | `KartParamCacheMid2` | ctor | `KartParamCacheMid2_ctor` |
| `FUN_710064822c` | NotDecompiled | `KartParamCacheEnv`, `KartParamCacheVt2668` | ctor | `KartParamCacheEnv_ctor (shared ctor)` |
| `FUN_710065ffec` | NotDecompiled | `KartParamCacheMultiFilterBlur` | ctor | `KartParamCacheMultiFilterBlur_ctor` |
| `FUN_7100660cc4` | NotDecompiled | `KartParamCacheMultiFilterColorDrift` | ctor | `KartParamCacheMultiFilterColorDrift_ctor` |
| `FUN_710066092c` | NotDecompiled | `KartParamCacheMultiFilterFormat` | ctor | `KartParamCacheMultiFilterFormat_ctor` |
| `FUN_710064a708` | NotDecompiled | `KartParamCacheVt2668` | ctor | `KartParamCacheVt2668_ctor` |
| `FUN_71003995d4` | NotDecompiled | `RaceDirectorVt01e8` | ctor | `RaceDirectorVt01e8_ctor` |
| `FUN_71007fd3d4` | NotDecompiled | `RaceDirectorVta260` | ctor | `RaceDirectorVta260_ctor` |
| `FUN_710064eea8` | NotDecompiled | `ParamNodeVt2b90` | ctor | `ParamNodeVt2b90_ctor` |
| `FUN_7100651ae4` | NotDecompiled | `KartParamCacheFilterAA` | ctor | `KartParamCacheFilterAA_ctor` |
| `FUN_7100669954` | NotDecompiled | `KartParamCacheVt24c8` | ctor | `KartParamCacheVt24c8_ctor` |
| `FUN_7100756c54` | NotDecompiled | `LowPrioWorkerThread` | ctor | `LowPrioWorkerThread_ctor` |
| `FUN_710062fd48` | NotDecompiled | `ParamChannelFilterAA`, `ParamChannelVt20e8`, `ParamChannelVt21f0`, `ParamChannelVt2290`, `ParamChannelVt2910`, `ParamChannelVt29b0`, `ParamChannelVt2a50`, `ParamChannelVt2af0`, `ParamChannelVt32b8`, `ParamChannelVt38f8`, `ParamChannelVt39d8`, `ParamChannelVt3c38`, `ParamChannelVt3cd8`, `ParamChannelVt4018`, `ParamChannelVt40b8`, `ParamChannelVt4158`, `ParamChannelVt41f8`, `ParamChannelVt4298`, `ParamChannelVt4338`, `ParamChannelVt43d8`, `ParamChannelVt4478` | ctor | `ParamChannelFilterAA_ctor (shared ctor)` |
| `FUN_710065e178` | NotDecompiled | `ParamChannelVt3c38` | ctor | `ParamChannelVt3c38_ctor` |
| `FUN_71008911a0` | NotDecompiled | `KartModelBackgroundLoadThread` | ctor | `KartModelBackgroundLoadThread_ctor` |
| `FUN_7100668528` | NotDecompiled | `ParamChannelVt20e8`, `ParamChannelVt4018`, `ParamChannelVt40b8`, `ParamChannelVt4158`, `ParamChannelVt41f8`, `ParamChannelVt4298`, `ParamChannelVt4338`, `ParamChannelVt43d8`, `ParamChannelVt4478` | ctor | `ParamChannelVt20e8_ctor (shared ctor)` |
| `FUN_71007284f0` | NotDecompiled | `ParamChannelVt32b8` | ctor | `ParamChannelVt32b8_ctor` |
| `FUN_710060c36c` | NotDecompiled | `VibrationThread` | ctor | `VibrationThread_ctor` |
| `FUN_710071d134` | NotDecompiled | `KartParamCacheBgb` | ctor | `KartParamCacheBgb_ctor` |
| `FUN_710071db70` | NotDecompiled | `KartParamCacheContainer` | ctor | `KartParamCacheContainer_ctor` |
| `FUN_710064bdac` | NotDecompiled | `KartParamCacheEnvSet` | ctor | `KartParamCacheEnvSet_ctor` |
| `FUN_710063c87c` | NotDecompiled | `KartParamCacheVt1d08` | ctor | `KartParamCacheVt1d08_ctor` |
| `FUN_71006615fc` | NotDecompiled | `ParamChannelVt39d8` | ctor | `ParamChannelVt39d8_ctor` |
| `FUN_71006ae398` | NotDecompiled | `KartParamCacheVt7850` | ctor | `KartParamCacheVt7850_ctor` |

## Consumer-side candidates

Decompiled functions that instantiate/hold/read a class (top candidates for `<Class>...` style names):

| Decomp symbol | Class | Use kind |
|---|---|---|
| `_ZN4sead13GameFramework17createCuckooClockEPNS_8TaskBaseE` | `RaceDirectorVt01e8` | instantiates |
| `_ZN4sead13GameFramework17createCuckooClockEPNS_8TaskBaseE` | `RaceDirectorVt01e8` | instantiates |
| `_ZN4sead13GameFramework17createCuckooClockEPNS_8TaskBaseE` | `RaceDirectorVt01e8` | reads-cell |
| `_ZN4sead13GameFramework17createCuckooClockEPNS_8TaskBaseE` | `RaceDirectorVt5758` | instantiates |
| `_ZN4sead13GameFramework17createCuckooClockEPNS_8TaskBaseE` | `RaceDirectorVt5758` | instantiates |
| `_ZN4sead13GameFramework17createCuckooClockEPNS_8TaskBaseE` | `RaceDirectorVt5758` | instantiates |
| `_ZN4sead13GameFramework17createCuckooClockEPNS_8TaskBaseE` | `RaceDirectorVt5758` | instantiates |
| `_ZN4sead13GameFramework17createCuckooClockEPNS_8TaskBaseE` | `RaceDirectorVta260` | instantiates |
| `_ZN4sead13GameFramework17createCuckooClockEPNS_8TaskBaseE` | `RaceDirectorVta260` | instantiates |
| `_ZN4sead13GameFramework17createCuckooClockEPNS_8TaskBaseE` | `KartParamCacheChan` | reads-cell |
| `_ZN4sead13GameFramework17createCuckooClockEPNS_8TaskBaseE` | `KartParamCacheMid` | reads-cell |
| `_ZN4sead13GameFramework17createCuckooClockEPNS_8TaskBaseE` | `KartParamCacheMid2` | instantiates |
| `_ZN4sead13GameFramework17createCuckooClockEPNS_8TaskBaseE` | `KartParamCacheVtbb800` | reads-cell |
| `_ZN4sead13GameFramework17createCuckooClockEPNS_8TaskBaseE` | `KartParamCacheVtd608` | instantiates |
| `_ZN4sead13GameFramework17createCuckooClockEPNS_8TaskBaseE` | `KartParamCacheVtd608` | reads-cell |
| `_ZN4sead13GameFramework17createCuckooClockEPNS_8TaskBaseE` | `KartParamCacheVtd608` | reads-cell |
| `_ZN4sead13GameFramework17createCuckooClockEPNS_8TaskBaseE` | `KartParamCacheVtd608` | reads-cell |
| `_ZN4sead13GameFramework17createCuckooClockEPNS_8TaskBaseE` | `KartPhysicsBody` | instantiates |
| `_ZN4sead13GameFramework17createCuckooClockEPNS_8TaskBaseE` | `KartPhysicsBody` | reads-cell |
| `_ZN4sead13GameFramework17createCuckooClockEPNS_8TaskBaseE` | `KartPhysicsBody` | reads-cell |
| `_ZN4sead13GameFramework17createCuckooClockEPNS_8TaskBaseE` | `KartPhysicsBody` | reads-cell |
| `_ZN4sead13GameFramework17createCuckooClockEPNS_8TaskBaseE` | `TimeSyncThread` | reads-cell |
