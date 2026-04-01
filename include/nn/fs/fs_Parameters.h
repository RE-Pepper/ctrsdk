#pragma once

namespace nn {
namespace fs {

struct Transaction
{
        bit32 dummy;
};

struct Attributes
{
        bool isDirectory;
        bool isHidden;
        bool isArchive;
        bool isReadOnly;
};

struct ShortName
{
        char body[10];
        char ext[4];
        bool valid;
        bit8 pad;
};

struct DirectoryEntry
{
        unsigned short entryName[262];
        ShortName      shortName;
        Attributes     attributes;
        s64            entrySize;
};

enum MediaType
{
        MEDIA_TYPE_NAND,
        MEDIA_TYPE_SDMC,
        MEDIA_TYPE_CTRCARD
};

enum PositionBase
{
        POSITION_BASE_BEGIN,
        POSITION_BASE_CURRENT,
        POSITION_BASE_END
};

namespace detail {
struct ArchiveHandleTag
{};
} // namespace detail

typedef bit64 ArchiveHandle; // 120

typedef bit64 ExtSaveDataId; // 122
typedef bit64 TitleId;       // 123

namespace CTR {
typedef struct DUMMY1
{
        bit8 data[948];
} Dummy1; // 143

typedef struct DUMMY2
{
        bit8 data[9152];
} Dummy2; // 148

} // namespace CTR

} // namespace fs
} // namespace nn
