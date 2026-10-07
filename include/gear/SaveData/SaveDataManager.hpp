#pragma once

#include <cstdint>

#include "SaveDataFile.hpp"
#include <filedevice/nin/seadNinSaveFileDeviceNin.h>

#include <container/seadSafeArray.h>

namespace gear
{
    // Forward declaration
    class SaveDataGhostListFile;

    // Manager
    class SaveDataManager
    {
    public:
        class SaveGhostParam
        {
        public:
            int32_t mTableIndex; // 0x00
            int32_t mCourseId; // 0x04
            bool mIsDownloaded; // 0x08
            bool mIsFastGhost; // 0x09
            bool mSkipCreate; // 0x0A
            uint8_t mPad0B; // 0x0B
            uint8_t mPad0C[4]; // 0x0C

            void getFileName(sead::BufferedSafeStringBase<char> *)const;

            SaveGhostParam() {}
        };

        class LoadGhostParam
        {
        public:
            int32_t mTableIndex; // 0x00
            int32_t mCourseId; // 0x04
            uint8_t mIsDL; // 0x08
            uint8_t mIsFastGhost; // 0x09
            uint8_t mPad0A; // 0x0A
            uint8_t mPad0B; // 0x0B

            LoadGhostParam() {}
        };

        class RemoveGhostParam
        {
        public:
            int32_t mCourseId; // 0x00
            uint8_t mIsDL; // 0x04;
            uint8_t mIsFastGhost; // 0x05
            uint8_t mPad06; // 0x06
            uint8_t mPad07; // 0x07
            RemoveGhostParam() {}
        };

        template <typename T, int32_t N>
        class ParamBuffer
        {
        public:
            virtual void virtFunc00(); // 0x00

            T* mEntries[N]; // 0x08
            uint32_t mCurrentIndex; // 0x18
            uint32_t mPad1C; // 0x1C

            inline T* peek() {
                return mEntries[mCurrentIndex];
            }
        };

        // Unproven — Switch ctor not identified (no RTTI, stripped binary);
        // extents fixed by the proven fields around each gap.
        uint8_t mPad00[0x138]; // extent fixed by mGhostSaveDataFile at 0x138
        SaveDataFile* mGhostSaveDataFile; // 0x138
        uint8_t mPad140[0x20]; // 0x140 — extent fixed by mGhostListFile at 0x160
        SaveDataGhostListFile* mGhostListFile; // 0x160
        uintptr_t mPad168; // 0x168 — unproven single word
        sead::NinSaveFileDevice* mSaveFileDevice; // 0x170;
        uint8_t mPad178[0x350]; // 0x178 — extent fixed by mRemoveGhostParamBuffer at 0x4C8
        ParamBuffer<RemoveGhostParam, 2>* mRemoveGhostParamBuffer; // 0x4C8
        uint8_t mPad4D0[0x18]; // 0x4D0 — extent fixed by mLoadGhostResult at 0x4E8
        bool mLoadGhostResult; // 0x4E8
        bool mLoadGhostDone; // 0x4E9
        bool mSaveGhostResult; // 0x4EA
        bool mSaveGhostDone; // 0x4EB

        bool loadGhost(gear::SaveDataManager::LoadGhostParam const&);

        void waitSync();
    };

    // SaveData classes
    class SaveDataGhostListFile : public SaveDataFile
    {
    public:
        void update(gear::SaveDataManager::SaveGhostParam const*);
    };

    SaveDataManager* GetSaveDataManager();
}