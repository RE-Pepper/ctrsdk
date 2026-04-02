#pragma once

#include <nn/fs/fs_Parameters.h>
#include <nn/util/util_SizedEnum.h>

namespace nn {
namespace fs {

struct WriteOption
{
        bool flush;
        bool updateTimeStampOld;
        bool updateTimeStamp;
        bit8 reserved3;

        WriteOption (bool flush, bool updateTimeStamp)
            : flush (flush), updateTimeStampOld (false), updateTimeStamp (updateTimeStamp)
        {}
};

typedef bit32 SystemSaveDataId; // 70

typedef bit32 ContentIdx; // 74

typedef struct TitleDataSpecifier
{
        TitleId                     id;
        util::SizedEnum1<MediaType> media;
        // two unnamed ints?
        int unk0;
        int unk1;

        static TitleDataSpecifier Make (MediaType type, TitleId id)
        {
                TitleDataSpecifier ret;
                ret.id    = id;
                ret.media = type;
                return ret;
        }
} ProgramLaunchInfo; // 98

enum SystemMediaType
{
        SYSTEM_MEDIA_TYPE_CTR_NAND,
        SYSTEM_MEDIA_TYPE_TWL_NAND,
        SYSTEM_MEDIA_TYPE_SDMC,
        SYSTEM_MEDIA_TYPE_TWL_PHOTO
};

} // namespace fs
} // namespace nn
