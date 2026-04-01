#pragma once

namespace nn {
namespace fs {

typedef enum CardType
{
        CARD_TYPE_CTR,
        CARD_TYPE_DS_TWL,
        CARD_TYPE_UNKNOWN
} CardType; // 31

typedef struct ArchiveResource
{
        u32 sectorSize;
        u32 clusterSize;
        u32 totalClusters;
        u32 freeClusters;
} ArchiveResource; // 65

typedef struct NandInfo
{
        u8  cid[16];
        u32 eraseCountMax;
        u32 eraseCountMin;
        u32 eraseCountAverage;
} NandInfo; // 76

typedef struct
{
        bool bCardHighSpeed;
        bool bSdifMaxSpeed;
        u16  SdifClkCtrlValue;
} SdmcSpeedInfo; // 84

enum CardSpiBaudRate
{
        CARDSPI_BAUDRATE_512KHZ = 0,
        CARDSPI_BAUDRATE_1MHZ   = 1,
        CARDSPI_BAUDRATE_2MHZ   = 2,
        CARDSPI_BAUDRATE_4MHZ   = 3,
        CARDSPI_BAUDRATE_8MHZ   = 4,
        CARDSPI_BAUDRATE_16MHZ  = 5
};

enum CardSpiBusMode
{
        CARDSPI_BUSMODE_1BIT = 0,
        CARDSPI_BUSMODE_4BIT = 1
};

typedef struct SdmcLog SdmcLog; // 102

typedef struct NandLog NandLog; // 104

} // namespace fs
} // namespace nn
