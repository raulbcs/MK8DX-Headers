# ParamChannelVt21f0

 ParamChannelVt21f0 — address-anchored name. Channel type of the
 0x66496c cluster, built in place inside the headered param-cache
 containers. channel at parent+0x40, tail byte +0x58 (fn 0x7100646dac).
 Extent 0x20. 0x12b21f0 is NOT a vptr: it is the first vtable-entry
 SLOT of the KartParamCacheChan vtable (holds fn 0x64733c). GOT cell
 0x130d908 relocates to 0x12b21e0 = KartParamCacheChan's vptr, so this
 shape shares the base vtable (no own fields).

## Naming and additional notes

 Naming: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash (dictionary via 0x710062fd48), not statically resolvable.

## Construction / init order

- ParamChannelVt21f0 — address-anchored name. Channel type of the 0x66496c cluster, built in place inside the headered param-cache containers. channel at parent+0x40, tail byte +0x58 (fn 0x7100646dac). Extent 0x20. 0x12b21f0 is NOT a vptr: it is the first vtable-entry SLOT of the KartParamCacheChan vtable (holds fn 0x64733c). GOT cell 0x130d908 relocates to 0x12b21e0 = KartParamCacheChan's vptr, so this shape shares the base vtable (no own fields). Naming: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash (dictionary via 0x710062fd48), not statically resolvable.
