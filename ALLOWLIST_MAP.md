# Allowlist kill map — objetivo: ZERO

Atualizado 2026-10-15. 268 headers na allowlist. Estado: `python3
tools/check_extents.py` verde (0 violations); `--mine ctor|alloc|sweep`
minera provas no ELF (endereços = VMA; bit L filtrado; `orr`-alias coberto).

Métodos de prova, do mais forte pro mais fraco:
1. **ALLOC+CTOR** — `mov w0,#size; bl _Znwm` → ctor com stores ≥ fields_end.
2. **CTOR-STORES** — stores do ctor chegam exatamente em fields_end.
3. **PARENT-ANCHOR** — alloc feito no ctor do pai, guardo em offset
   documentado do pai (padrão do censo do KartVehicle).
4. **STRIDE/POOL** — elemento de array com stride fixo + ctor do elemento.
5. **FACTORY/PROSA VERIFICADA** — claim prévio conferido no ELF.

## Grupo A — object/Kart (78) ← atacar primeiro

| Sub-grupo | Qtde | Método provável |
|---|---:|---|
| ParamNodeVt* fe=0x50 restantes (2198, 2b90, 3fd8, 4140, 4c70, c848, c8a0, c8f8, d5b0) | 9 | Mesmo método (sibling vptr a +0x50 via célula GOT); verificador: scan bidirecional adrp+ldr→add#0x10→stores, boundary==fe. Falham: sites são getters (sem irmão) ou bounds só 0x30-interno; Vt4c70/c848/c8f8 sem site com irmão |
| KartParamCache* grandes (Cloud 0x7f60, CloudDraw 0x7f90, CloudTex 0xaf9, ColorCorrectionSub 0x1a2c, CubeMap 0x454, Decal 0x48c, DecalAo 0x19a8, LightMap 0x8f4, Lref 0xf19, NormalDrawer 0x48c, Ofx 0x2840, ProjShadow 0x541, Shadow 0x17c4, ShadowPP 0x905, Sky 0xdb0, Ssao 0x3cf4, VolumeMask 0x548, Vt3df8 0x5c4, Vtd608 0x318) | 19 | PROSA: dtors citam "pooled array stride X" — verificar stride == fe e converter |
| ParamMultiChanVt* ("EXTENT APPROXIMATE", constructed in place) | 12 | IN-PLACE: ctor escreve último canal em fe; provar stores do factory |
| ParamContainerVtb0b8/Vtb1e8 (fe=0x2f0) | 2 | FACTORY alloc 0x2f0 |
| ParamNodeEnvObjName (0x10a), ModelBinding (0x38), PseudoOcclusion (0x2e8) | 3 | PseudoOcclusion: ctor 0x3ad5d8 stores 0x2e8 EXATO (alloc 0x348 no ctor do KartChassis @+0x508) — confirmar identidade via vtable |
| Vt3dcf30* (4; fe=0x8/f4) + ParamChannelVt38f8 (0x170) | 5 | DTOR/reset paths citam writes |
| Threads (Audio/BackgroundLoad/Contents/ModelBg/LowPrio/UIMovie/Vibration) | 7 | CTOR-STORES (fe=0x8 — vtable+1 flag; ctors pequenos) |
| KartDirector (0x794), KartChassisEffect (0x20), KartMatrixInfo (fe=0), KartInfoProxy (0x50), KartFloorEffect (0x12c+) | 5 | Director: embutido (achar owner); ChassisEffect: owner KartChassis?; FloorEffect: achar o new real (NÃO é 0x130@0x1702fc — esse é ChassisAnim) |
| Race (RaceKartInfo 0x1c, RaceKartResult 0x8, RecordFileKart 0x34) + GndColCheckRayInfo (0x2c) | 4 | ARRAY (12 karts?) ou in-place; accessor-driven |

## Grupo B — gear/Race (22) + gear/Item (11) + gear/UI (16) + ui/* (26)

Mistura de gameplay/UI. Métodos: CTOR-STORES via `--mine sweep` (vários já
têm ctor citado); PARENT-ANCHOR via managers. Prioridade: Race > Item > UI.

## Grupo C — infra (nn/nex 13, enl 7, aal 8, sead 1, xlink2 4, gsys 4,
repl 3, naked 1) — ~40

Frames/containers de SDK. Muitos podem cair com CTOR-STORES simples
(fe pequenos). Fazer por último; risco baixo, tédio alto.

## Progresso

- 2026-10-14: 349 → 288 (linter rewrite + proves Drift/React/GhostRecord).
- 2026-10-15 (noite): 266 → **259** — +7 ParamNodeVt* (2df8, 2e50, 3f08, 4eb8,
  7780, d500, d558) pela partição in-place (vptr irmão a +0x50; verificador
  bidirecional células GOT→add#0x10→stores, boundary==fe). Aviso: stores a
  +0x30 são o channel-pair INTERNO (mChan30), não vizinho.
- Mapa: ALLOWLIST_MAP.md (este arquivo). Verificador de partição 0x50:
  janela ±(40,60) instrs do site, stur/str signed; 2 sites confirmaram,
  resto precisa de reg-offset tracking (add xN, base, reg).
- Erro aprendido: alloc 0x130@0x1702fc é KartChassisAnim, NÃO KartFloorEffect
  (revertido); sempre ancorar no campo do pai antes de citar.

## Regras

- Só sai da allowlist com prova 1–5 acima; "APPROXIMATE" não conta.
- Citação canônica DENTRO do bloco da struct: `// extent 0xNN (…)`; prosa mínima.
- `check_extents.py` verde obrigatório a cada lote.
