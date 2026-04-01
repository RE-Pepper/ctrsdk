#pragma once

#include <nn/cfg/CTR/cfg_UserInfo.h>
#include <nn/codec/CTR/codec_Types.h>

namespace nn {
namespace cfg {
namespace CTR {
namespace detail {

struct BackLightCfgData
{
        bit8 ablEnable;
        u8   luminanceLevel;
};
static_assert_ (sizeof (BackLightCfgData) == 2);
struct BacklightPwmTableCfgData
{
        f32  coef[3][3];
        u8   numLevels;
        bit8 control;
        u16  luminanceLevel[7];
        u16  brightnessBase;
        u16  brightnessMinimum;
};
static_assert_ (sizeof (BacklightPwmTableCfgData) == 56);

struct AblDetailCfgData
{
        bit32 ditherPattern;
        u16   xStart;
        u16   yStart;
        u16   xWidth;
        u16   yWidth;
        u16   gthRatio;
        bit8  ditherMode;
        u8    rsMin;
        u8    rsMax;
        u8    gthMin;
        u8    maxMin;
        u8    maxEx;
        u8    inertia;
        u8    rsLut[9];
        bit8  reserved[2];
};
static_assert_ (sizeof (AblDetailCfgData) == 32);

struct UlcdLibAssumptionCfgData
{
        f32 pupillaryDist;
        f32 distEyeAndDisp;
        f32 wideSideLen;
        f32 narrowSideLen;
        f32 maxParallaxBack;
        f32 maxParallaxFront;
        f32 maxDepthRangeBack;
        f32 maxDepthRangeFront;
};
static_assert_ (sizeof (UlcdLibAssumptionCfgData) == 32);

struct UlcdDelayCfgData
{
        s8 to2D;
        s8 to3D;
};
static_assert_ (sizeof (UlcdDelayCfgData) == 2);

struct CameraQualityCalData
{
        s16 aeBaseTarget;
        s16 kRL;
        s16 kGL;
        s16 kBL;
        s16 ccmPosition;
        u16 awbCcmL9Right;
        u16 awbCcmL9Left;
        u16 awbCcmL10Right;
        u16 awbCcmL10Left;
        u16 awbX0Right;
        u16 awbX0Left;
};
static_assert_ (sizeof (CameraQualityCalData) == 22);
struct CameraPositionCalData
{
        struct Flags
        {
                bool isValidRotationXY;
                bool reservedFlag[3];
        } flags;

        f32 scale;
        f32 rotationZ;
        f32 translationX;
        f32 translationY;
        f32 rotationX;
        f32 rotationY;
        f32 angleOfViewRight;
        f32 angleOfViewLeft;
        f32 distanceToChart;
        f32 distanceCameras;
        s16 imageWidth;
        s16 imageHeight;
        u8  reserved[16];
};
static_assert_ (sizeof (CameraPositionCalData) == 64);
struct CameraCfgData
{
        struct CameraPositionCalData position;
        u32                          reserved[16];
        struct CameraQualityCalData  quality;
} NN_PACK;
static_assert_ (sizeof (CameraCfgData) == 150);

struct AnalogStickCfgData
{
        f32 scale_x;
        f32 scale_y;
        s16 center_x;
        s16 center_y;
        s16 max_x;
        s16 min_x;
        s16 max_y;
        s16 min_y;
        s16 type;
        s16 reserve[3];
};
static_assert_ (sizeof (AnalogStickCfgData) == 28);
struct AnalogInterfaceParam
{
        u8 interval;
        u8 stabilization;
        u8 precharge;
        u8 sense;
        u8 debounce;
        u8 xpPullUpRegister;
        u8 ymDriver;
        u8 reserve;
};
static_assert_ (sizeof (AnalogInterfaceParam) == 8);

struct CodecCfgData
{
        u8 driverGainHP;
        u8 driverGainSP;
        u8 analogVolumeHP;
        u8 analogVolumeSP;
        s8 shutterVolume1;
        s8 shutterVolume2;
        u8 micBias;
        u8 quickCharge;
        u8 micGainCalibrateParam;
        u8 pad[3];

        codec::CTR::IirFilterParamEQ filterHp32;
        codec::CTR::IirFilterParamEQ filterHp47;
        codec::CTR::IirFilterParamEQ filterSp32;
        codec::CTR::IirFilterParamEQ filterSp47;
        codec::CTR::IirFilterParam   filterMic32;
        codec::CTR::IirFilterParam   filterMic47;
        codec::CTR::IirFilterParam   filterFree;

        AnalogInterfaceParam AnalogInterfaceParam;
};
static_assert_ (sizeof (CodecCfgData) == 308);

struct SurroundCfgData
{
        s16 specialFilter[256];
        s32 iirFilter[5];
};
static_assert_ (sizeof (SurroundCfgData) == 532);

struct UserNameCfgData
{
        UserName userName;
        u32      ngWordCheckVersion;
};

typedef struct Birthday BirthdayCfgData; // 307

struct LanguageCfgData
{
        u8 languageCode;
};
static_assert_ (sizeof (LanguageCfgData) == 1);

struct SimpleAddressIdCfgData
{
        u32 id;
};
static_assert_ (sizeof (SimpleAddressIdCfgData) == 4);
struct SimpleAddressPositionCfgData
{
        u16 latitude;
        u16 longitude;
};
static_assert_ (sizeof (SimpleAddressPositionCfgData) == 4);

typedef struct ParentalControlInfo ParentalControlInfoCfgData; // 337

union EulaVersion {
        u16 version;
        struct
        {
                u8 minorVersion;
                u8 majorVersion;
        } detailed;
};
static_assert_ (sizeof (EulaVersion) == 2);

struct EulaInfoCfgData
{
        EulaVersion agreeVersion;
        EulaVersion latestVersion;
};
static_assert_(sizeof(EulaInfoCfgData) == 4);

struct BossSettingCfgData
{
        u8 isAllowedPushApp : 1;
        u8 isAllowedUploadPersonalData : 1;
        u8 rsv : 6;
};
static_assert_ (sizeof (BossSettingCfgData) == 1);

struct SoundSettingCfgData
{
        u8 soundOutputMode;
};
static_assert_ (sizeof (SoundSettingCfgData) == 1);

typedef struct EchoCancelParam EchoCancelCfgData; // 385

struct LocalFriendCodeBaseCfgData
{
        bit64 localFriendCodeSeed : 34;
        bit64 rsv : 14;
        bit64 counter : 16;
};
static_assert_ (sizeof (LocalFriendCodeBaseCfgData) == 8);

struct SystemInfoCfgData
{
        bit64 debugMonitorProgramId;
        bit32 kernelParam;
        bit32 devParam;
};
static_assert_(sizeof(SystemInfoCfgData) == 16);

struct PseudoRomIdCfgData
{
        bit64 pseudoRomId;
};
static_assert_ (sizeof (PseudoRomIdCfgData) == 8);

struct HomeButtonSettingCfgData
{
        bool isDisabled;
};
static_assert_ (sizeof (HomeButtonSettingCfgData) == 1);

struct TwlParentalControlInfoCfgData
{
        struct
        {
                u32 isSetParentalControl : 1;
                u32 pictoChat : 1;
                u32 dsDownload : 1;
                u32 browser : 1;
                u32 wiiPoint : 1;
                u32 photoExchange : 1;
                u32 ugc : 1;
                u32 rsv : 25;
        } flags;

        u8      rsv1[3];
        u8      ogn;
        u8      ratingAge;
        u8      secretQuestionID;
        u8      secretAnswerLength;
        u8      rsv[2];
        char    password[5];
        wchar_t secretAnswer[65];
};
static_assert_(sizeof(TwlParentalControlInfoCfgData) == 148);
struct TwlEulaInfoCfgData
{
        bool isAgreeEula;
        u8   agreeEulaVersion;
};
static_assert_(sizeof(TwlEulaInfoCfgData) == 2);
struct TwlCountryCodeCfgData
{
        u8 country;
};
static_assert_ (sizeof (TwlCountryCodeCfgData) == 1);
struct TwlMovableUniqueIdCfgData
{
        u8 movableUniqueId[16];
};
static_assert_ (sizeof (TwlMovableUniqueIdCfgData) == 16);

struct FirstLaunchInfoCfgData
{
        u16 mmen;
        u8  internet;
        u8  rsv;
};
static_assert_(sizeof(FirstLaunchInfoCfgData) == 4);

struct MenuInfoCfgData
{
        bit64 programId;
};
static_assert_(sizeof(MenuInfoCfgData) == 8);

struct SlideVolume
{
        s16 min;
        s16 max;
};
static_assert_ (sizeof (SlideVolume) == 4);

struct McuSlideVolumeRangeCfgData
{
        SlideVolume svr2;
        SlideVolume sound;
};
static_assert_ (sizeof (McuSlideVolumeRangeCfgData) == 8);
struct DebugParamCfgData
{
        struct Param1
        {
                u8 general : 1;
                u8 rsv : 7;
        };
        static_assert_ (sizeof (Param1) == 1);

        bool dlpDebug;
        union {
                u8     flags1;
                Param1 param1;
        };

        u8 fsLatencyEmulationParam;
        u8 rsv;
};
static_assert_ (sizeof (DebugParamCfgData) == 4);

} // namespace detail
} // namespace CTR
} // namespace cfg
} // namespace nn

