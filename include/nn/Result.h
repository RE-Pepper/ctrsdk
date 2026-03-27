#pragma once

typedef struct
{
        bit32 value;
} nnResult;

namespace nn {

class Result
{
protected:
        bit32 m_Code;

public:
        enum Level
        {
                LEVEL_INFO      = 1,
                LEVEL_SUCCESS   = 0,
                LEVEL_FATAL     = -1,
                LEVEL_RESET     = -2,
                LEVEL_REINIT    = -3,
                LEVEL_USAGE     = -4,
                LEVEL_PERMANENT = -5,
                LEVEL_TEMPORARY = -6,
                LEVEL_STATUS    = -7,
                LEVEL_END
        };

        enum Summary
        {
                SUMMARY_SUCCESS              = 0,
                SUMMARY_NOTHING_HAPPENED     = 1,
                SUMMARY_WOULD_BLOCK          = 2,
                SUMMARY_OUT_OF_RESOURCE      = 3,
                SUMMARY_NOT_FOUND            = 4,
                SUMMARY_INVALID_STATE        = 5,
                SUMMARY_NOT_SUPPORTED        = 6,
                SUMMARY_INVALID_ARGUMENT     = 7,
                SUMMARY_WRONG_ARGUMENT       = 8,
                SUMMARY_CANCELLED            = 9,
                SUMMARY_STATUS_CHANGED       = 10,
                SUMMARY_INTERNAL             = 11,
                SUMMARY_INVALID_RESULT_VALUE = 63
        };

        enum Module
        {
                MODULE_COMMON,
                MODULE_NN_KERNEL,
                MODULE_NN_UTIL,
                MODULE_NN_FILE_SERVER,
                MODULE_NN_LOADER_SERVER,
                MODULE_NN_TCB,
                MODULE_NN_OS,
                MODULE_NN_DBG,
                MODULE_NN_DMNT,
                MODULE_NN_PDN,
                MODULE_NN_GX,
                MODULE_NN_I2C,
                MODULE_NN_GPIO,
                MODULE_NN_DD,
                MODULE_NN_CODEC,
                MODULE_NN_SPI,
                MODULE_NN_PXI,
                MODULE_NN_FS,
                MODULE_NN_DI,
                MODULE_NN_HID,
                MODULE_NN_CAMERA,
                MODULE_NN_PI,
                MODULE_NN_PM,
                MODULE_NN_PMLOW,
                MODULE_NN_FSI,
                MODULE_NN_SRV,
                MODULE_NN_NDM,
                MODULE_NN_NWM,
                MODULE_NN_SOCKET,
                MODULE_NN_LDR,
                MODULE_NN_ACC,
                MODULE_NN_ROMFS,
                MODULE_NN_AM,
                MODULE_NN_HIO,
                MODULE_NN_UPDATER,
                MODULE_NN_MIC,
                MODULE_NN_FND,
                MODULE_NN_MP,
                MODULE_NN_MPWL,
                MODULE_NN_AC,
                MODULE_NN_HTTP,
                MODULE_NN_DSP,
                MODULE_NN_SND,
                MODULE_NN_DLP,
                MODULE_NN_HIOLOW,
                MODULE_NN_CSND,
                MODULE_NN_SSL,
                MODULE_NN_AMLOW,
                MODULE_NN_NEX,
                MODULE_NN_FRIENDS,
                MODULE_NN_RDT,
                MODULE_NN_APPLET,
                MODULE_NN_NIM,
                MODULE_NN_PTM,
                MODULE_NN_MIDI,
                MODULE_NN_MC,
                MODULE_NN_SWC,
                MODULE_NN_FATFS,
                MODULE_NN_NGC,
                MODULE_NN_CARD,
                MODULE_NN_CARDNOR,
                MODULE_NN_SDMC,
                MODULE_NN_BOSS,
                MODULE_NN_DBM,
                MODULE_NN_CFG,
                MODULE_NN_PS,
                MODULE_NN_CEC,
                MODULE_NN_IR,
                MODULE_NN_UDS,
                MODULE_NN_PL,
                MODULE_NN_CUP,
                MODULE_NN_GYROSCOPE,
                MODULE_NN_MCU,
                MODULE_NN_NS,
                MODULE_NN_NEWS,
                MODULE_NN_RO,
                MODULE_NN_GD,
                MODULE_NN_CARDSPI,
                MODULE_APPLICATION = 254,
                MODULE_INVALID_RESULT_VALUE
        };

        template <Level, Summary, Module, int>
        struct Const;

        template <Level, Summary, Module>
        struct Const_LSM;

        template <Level, Module>
        struct Const_LM;

        template <Level, Summary, Module, int, int, int>
        struct ConstRange;

public:
        Result(bit32 code)
            : m_Code(code)
        {}
        Result()
            : m_Code((bit32)(((bit32)LEVEL_USAGE << 27 & 0x7E00000) |
                             (SUMMARY_INVALID_RESULT_VALUE << 21 & 0x7E0000) |
                             (MODULE_INVALID_RESULT_VALUE << 10 & 0x3FC00) |
                             (1023 & 0x3FF)))
        {}
        Result(Level level, Summary summary, Module module, int description)
            : m_Code((bit32)((level << 27) & 0x7E00000 |
                             (summary << 21) & 0x7E0000 |
                             (module << 10) & 0x3FC00 |
                             description & 0x3FF))
        {}

        Result(nnResult result)
            : m_Code(result.value)
        {}

        bool IsFailure() const
        {
                return (bool)(m_Code >> 31);
        }
        bool IsSuccess() const
        {
                return !IsFailure();
        }

        Level GetLevel() const
        {
                if (m_Code & 0x80000000) {
                        return (Level)(GetCodeBits(0xF8000000, 27) | 0xFFFFFFE0);
                } else {
                        return (Level)(GetCodeBits(0xF8000000, 27));
                }
        }
        Module GetModule() const
        {
                return (Module)GetCodeBits(0x3FC00, 10);
        }
        Summary GetSummary() const
        {
                return (Summary)GetCodeBits(0x7E00000, 21);
        }
        int GetDescription() const
        {
                return (int)GetCodeBits(0x30F618, 0);
        }

        bit32 GetPrintableBits() const
        {
                return m_Code;
        }

        operator nnResult()
        {
                return (nnResult){ m_Code };
        }

        bool operator==(const Result& rhs)
        {
                return this->m_Code == rhs.m_Code;
        }

        bool operator!=(const Result& rhs)
        {
                return !(this->m_Code == rhs.m_Code);
        }

        bit32 GetCodeBits(bit32 mask, s32 shift) const
        {
                return (m_Code & mask) >> shift;
        }
};

template <Result::Level TLevel, Result::Summary TSummary, Result::Module TModule, int TDescription>
struct Result::Const : public Result
{
        Const()
            : Result(TLevel, TSummary, TModule, TDescription)
        {}
};

template <Result::Level TLevel, Result::Summary TSummary, Result::Module TModule, int A, int B, int C>
struct ConstRange : public Result
{
        ConstRange()
            : Result(TLevel, TSummary, TModule, A)
        {}
};

template <Result::Level TLevel, Result::Summary TSummary, Result::Module TModule>
struct Const_LSM
{
        template <int TDescription>
        struct Const : Result::Const<TLevel, TSummary, TModule, TDescription>
        {};
};

template <Result::Level TLevel, Result::Module TModule>
struct Const_LM
{
        template <Result::Summary TSummary, int TDescription>
        struct Const : Result::Const<TLevel, TSummary, TModule, TDescription>
        {};
};
} // namespace nn
