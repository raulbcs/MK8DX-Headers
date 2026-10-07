#pragma once
#include <cstdint>

namespace gear
{
    // rodata name table 0xee4e78 (order = table order; "None" is LAST in
    // the table — its numeric value is unverified)
    class ESessionError
    {
        public:
            enum ESessionError_ : int32_t
            {
                JoinFailed,              //0x00
                StandAlone,              //0x01
                ServerDisconnected,      //0x02
                SessionKeepFailed,       //0x03
                MasterDisconnected,      //0x04
                ReceiveOldDrivedata,     //0x05
                ItemEventFull,           //0x06
                BattleEventFull,         //0x07
                RecvOlodItemEvent,       //0x08
                CourseVoteSyncFailed,    //0x09
                Offense,                 //0x0A
                MatchConditionNotFound,  //0x0B
                ResourceLoaderError,     //0x0C
                TeamConfigError,         //0x0D
                DecidePlayerError,       //0x0E
                DecideTeamError,         //0x0F
                DecideMenuError,         //0x10
                ForceGoalUnFinished,     //0x11
                FinishEventNotReceive,   //0x12
                ItemEventLogicError,     //0x13
                ItemEventPushFailed,     //0x14
                SessionTimeout,          //0x15
                SyncFailed,              //0x16
                Timeout,                 //0x17
                PseudoError,             //0x18
                OtherFinalizeError,      //0x19
                DecideItemSwitchError,   //0x1A
                ItemSwitchConfigError,   //0x1B
                GatheringCodeError,      //0x1C
                None                     //0x1D
            };

            ESessionError_ mValue;

            const char* text_(int);

            ESessionError() : mValue(ESessionError_::None) {}
            ESessionError(ESessionError_ item) : mValue(item) {}
            ESessionError(int32_t item) : mValue(static_cast<ESessionError_>(item)) {}

            bool operator==(const ESessionError& other) const {
                return mValue == other.mValue;
            }
            bool operator!=(const ESessionError& other) const {
                return mValue != other.mValue;
            }
            bool operator<(const ESessionError& other) const {
                return mValue < other.mValue;
            }

            ~ESessionError() {}
    };
}
