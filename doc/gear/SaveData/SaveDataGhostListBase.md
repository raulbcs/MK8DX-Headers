# gear::SaveDataGhostListBase::Data (0x188 on-disk ghost data record)

NOTE: the on-disk trial record block (CTR0) also stores the collected COIN COUNT (runtime-confirmed via the replay UI); the exact field offset inside CTR0 was not isolated statically. Any simulator/imported ghost must carry it.

TA coin rules:

- FUN_710087c9b4 zeroes coins when RaceInfo+8 ∈ {TimeAttack, Battle}.
- Start coins from table 0x7100F6F384.
- Live mCoinNum mirror at vehicle+0x184 (checker chain RaceSystem+0x1B0 → +0x218 → +0x68 → idx*8 → +0x50).

Unverified: exact offset of the coin count inside the on-disk CTR0 block (not isolated statically).
