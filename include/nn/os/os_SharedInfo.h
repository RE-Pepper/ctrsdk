#pragma once

#include <nn/os/os_Tick.h>
#include <nn/os/os_Types.h>
#include <nn/util/util_FlagsEnum.h>

#include "nn/types.h"

namespace nn {
namespace os {

struct ReadOnlySharedInfo
{
        enum Flags
        {
                FLAGS_SAVE_MODE = 1,
                FLAGS_MAX_BITS  = 2147483648
        };

        bit8 versionReserve;
        u8   versionMicro;
        u8   versionMinor;
        u8   versionMajor;

        FlagsEnum4<Flags> flags;

        ProgramID firstMainBootProgram;
        bit32     coreVersion;
        bit8      deviceEnv;
        bit8      bootEnv;
        bit8      previousMode;
        int       unk; // Unnamed INT

        u32 revision;
        int unk1; // Unnamed INT

        bit32 kParamAck[4];
        bit32 kParamCurrent[4];
        bit32 kParamValues[8];

        bit8  firstVersionReserve;
        u8    firstVersionMicro;
        u8    firstVersionMinor;
        u8    firstVersionMajor;
        bit32 firstCoreVersion;
        bit32 firstRevision;
};

struct RtcSwcInfo
{
        s64  rtcBaseMilliSeconds;
        Tick rtcBaseTicks;
        s64  rtcTicksPerSecond;
        s64  rtcDiffMilliSeconds;
};

struct WritableSharedInfo
{
        s32       rtcValidNumber;
        u8        targetHardware;
        u8 mcuTargetInfo;
        u8 mcuInfoRegisters_10;
        bit8      reserved_0x006[25];
        RtcSwcInfo rtcSwcInfo[2];
        bit8 wirelessInfo[16];
        bit8      reserved_0x070[16];
        f32       svr2Volume;
        bool      displayModeLockFlag;
        u8        batteryState;
        bit8      reserved_0x087[26];
        ProgramID firstSystemMenu;
        ProgramID currentSystemMenu;
        bit8      reserved_0x0b0[16];
        bool      isHeadphoneInserted;
        bit8      reserved_0x0c1[31];
};

} // namespace os
} // namespace nn
