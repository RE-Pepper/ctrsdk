#pragma once

#include <nn/fs/fs_ParametersForSystem.h>
#include <nn/util/util_Int64.h>
#include <nn/util/util_SizedEnum.h>

namespace nn {
namespace fs {
namespace CTR {

struct DataContentArchivePath
{
        TitleId                     titleId;
        util::SizedEnum4<MediaType> mediaType;
        ContentIdx                  contentIdx;
};
static_assert_ (sizeof (DataContentArchivePath) == 0x10);

struct UserSaveDataArchivePath
{
        util::SizedEnum4<MediaType> mediaType;
        util::Int64<bit64>          titleId; // bit64 was a guess!

        static UserSaveDataArchivePath Make (MediaType mediaType, TitleId id)
        {
                UserSaveDataArchivePath ret;
                ret.mediaType = mediaType;
                ret.titleId   = id;
                return ret;
        }
};
static_assert_ (sizeof (UserSaveDataArchivePath) == 0xC);

struct ExtSaveDataArchivePath
{
        util::SizedEnum4<MediaType> mediaType;
        util::Int64<bit64>          extSaveDataId; // TODO: s64 WAS A GUESS!!

        static ExtSaveDataArchivePath Make (MediaType mediaType, ExtSaveDataId extSaveDataId)
        {
                ExtSaveDataArchivePath ret;
                ret.mediaType     = mediaType;
                ret.extSaveDataId = extSaveDataId;
                return ret;
        }
};
static_assert_ (sizeof (ExtSaveDataArchivePath) == 0xC);

struct SystemSaveDataArchivePath
{
        util::SizedEnum4<MediaType> mediaType;
        SystemSaveDataId            systemSaveDataId;

        static SystemSaveDataArchivePath Make (MediaType mediaType, SystemSaveDataId systemSaveDataId)
        {
                SystemSaveDataArchivePath ret;
                ret.mediaType        = mediaType;
                ret.systemSaveDataId = systemSaveDataId;
                return ret;
        }
};
static_assert_ (sizeof (SystemSaveDataArchivePath) == 0x8);

} // namespace CTR
} // namespace fs
} // namespace nn
