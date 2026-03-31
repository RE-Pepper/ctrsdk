#pragma once

#include <nn/Handle.h>
#include <nn/fnd/fnd_TimeSpan.h>

namespace nn {
namespace applet {
namespace CTR {

extern const fnd::TimeSpan WAIT_INFINITE;
extern const fnd::TimeSpan NO_WAIT;

enum DisplayBufferMode
{
        FORMAT_R8G8B8A8     = 0,
        FORMAT_R8G8B8       = 1,
        FORMAT_R5G6B5       = 2,
        FORMAT_R5G5B5A1     = 3,
        FORAMT_R4G4B4A4     = 4,
        FORMAT_UNIMPORTABLE = 4294967295
};

enum HomeButtonState
{
        HOME_BUTTON_NONE           = 0,
        HOME_BUTTON_SINGLE_PRESSED = 1,
        HOME_BUTTON_DOUBLE_PRESSED = 2
};

enum ShutdownState
{
        SHUTDOWN_STATE_NONE     = 0,
        SHUTDOWN_STATE_RECEIVED = 1
};

enum PowerButtonState
{
        POWER_BUTTON_STATE_NONE  = 0,
        POWER_BUTTON_STATE_CLICK = 1
};

enum OrderToCloseState
{
        ORDER_TO_CLOSE_STATE_NONE     = 0,
        ORDER_TO_CLOSE_STATE_RECEIVED = 1
};
enum AppJumpType
{
        JUMP_OTHER  = 0,
        JUMP_CALLER = 1,
        JUMP_SELF   = 2
};

enum AppletPos
{
        POS_APP      = 0,
        POS_APPLIB   = 1,
        POS_SYS      = 2,
        POS_SYSLIB   = 3,
        POS_RESIDENT = 4,
        POS_MAX      = 5,
        POS_NONE     = -1
};

enum SleepNotificationState
{
        NOTIFY_NONE           = 0,
        NOTIFY_SLEEP_QUERY    = 1,
        NOTIFY_SLEEP_ACCEPT   = 2,
        NOTIFY_SLEEP_REJECT   = 3,
        NOTIFY_SLEEP_ACCEPTED = 4,
        NOTIFY_AWAKE          = 5
};

enum WakeupState
{
        WAKEUP_SKIP                  = 0,
        WAKEUP_TO_START              = 1,
        WAKEUP_BY_EXIT               = 2,
        WAKEUP_BY_PAUSE              = 3,
        WAKEUP_BY_CANCEL             = 4,
        WAKEUP_BY_CANCELALL          = 5,
        WAKEUP_BY_POWER_BUTTON_CLICK = 6,
        WAKEUP_TO_JUMP_HOME          = 7,
        WAKEUP_TO_JUMP_APPLICATION   = 8,
        WAKEUP_TO_LAUNCH_APPLICATION = 9,
        WAKEUP_BY_SUSPEND            = 10,
        WAKEUP_STATE_MAX             = 63,
        WAKEUP_BY_TIMEOUT            = -1
};

enum QueryReply
{
        REPLY_REJECT = 0,
        REPLY_ACCEPT = 1,
        REPLY_LATER  = 2
};

enum ParentalControlsScene
{
        PARENTAL_CONTROLS_TOP     = 0,
        PARENTAL_CONTROLS_COPPACS = 1
};

enum DataManagementScene
{
        DATA_MANAGEMENT_TOP        = 0,
        DATA_MANAGEMENT_STREETPASS = 1
};

enum MsetScene
{
        MSET_INTERNET_SETTING_TOP       = 110,
        MSET_PARENTAL_CONTROLS_TOP      = 111,
        MSET_PARENTAL_CONTROLS_COPPACS  = 112,
        MSET_DATA_MANAGEMENT_TOP        = 113,
        MSET_DATA_MANAGEMENT_STREETPASS = 117,
        MSET_SCENE_INVALID_VALUE        = 4294967295
};

typedef bit32 AppletId; // 227

typedef bit32 AppletAttr; // 232

typedef DisplayBufferMode AppletDisplayBufferMode; // 234

typedef ShutdownState AppletShutdownState; // 240

typedef PowerButtonState AppletPowerButtonState; // 242

typedef OrderToCloseState AppletOrderToCloseState; // 244

typedef WakeupState AppletWakeupState; // 246

typedef QueryReply AppletQueryReply; // 248

typedef AppJumpType AppletAppJumpType; // 250

typedef ParentalControlsScene AppletParentalControlsScene; // 252

typedef DataManagementScene AppletDataManagementScene; // 254

typedef MsetScene AppletMsetScene; // 256

typedef bool (*AppletHomeButtonCallback) (uptr, AppletId, u8*, size_t); // 283

typedef void (*AppletMessageCallback) (uptr, size_t); // 287

typedef void (*AppletRequestMemoryCallback) (uptr); // 290

typedef void (*AppletReleaseMemoryCallback) (uptr); // 292

typedef void (*AppletDspSleepCallback) (uptr); // 295

typedef void (*AppletDspWakeUpCallback) (AppletQueryReply); // 297

typedef AppletQueryReply (*AppletSleepQueryCallback) (uptr); // 302

typedef void (*AppletSleepCanceledCallback) (uptr); // 306

typedef void (*AppletAwakeCallback) (); // 310

typedef void (*AppletShutdownCallback) (uptr); //315

typedef void (*AppletCloseAppletCallback) (uptr); // 319

typedef void (*AppletPowerButtonCallback) (uptr); // 324

typedef void (*AppletTransitionCallback) (uptr); // 329

typedef void (*AppletCloseCallback) (Handle);

extern const Handle HANDLE_NONE;

} // namespace CTR
} // namespace applet
} // namespace nn
