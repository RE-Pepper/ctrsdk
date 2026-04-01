#pragma once

#include <nn/fs/fs_ParametersForSystem.h>
#include <nn/util/util_Int64.h>
#include <nn/util/util_SizedEnum.h>

RP_SHUTUP

namespace nn {
namespace fs {
namespace CTR {

struct ExeFsSectionNames
{};

struct ContentPath : public ExeFsSectionNames
{
        enum Tag
        {
                TAG_ROMFS,
                TAG_EXEFS,
                TAG_SYSTEM_MENU_DATA,
                TAG_PROGRAM_INFO
        };

        util::Int64<s64>      id; // TODO: s64 IS A PLACEHOLDER!!
        util::SizedEnum4<Tag> tag;

        static ContentPath MakeRomfsPath () {}
        static ContentPath MakeExefsPath () {}
        static ContentPath MakeSystemMenuDataPath () {}
        static ContentPath MakeProgramInfoPath () {}
};

struct ProgramDataPath : public ExeFsSectionNames
{
        enum Tag
        {
                TAG_ROMFS,
                TAG_EXEFS,
                TAG_SYSTEM_MENU_DATA,
                TAG_SAVE_DATA,
                TAG_CONTENT
        };

        util::Int64<s64>      id; // TODO: s64 IS A PLACEHOLDER!!
        util::SizedEnum4<Tag> tag;

        static ProgramDataPath MakeRomFsPath () {}
        static ProgramDataPath MakeExeFsPath () {}
        static ProgramDataPath MakeSaveMenuDataPath () {}
        static ProgramDataPath MakeSaveDataPath () {}
        static ProgramDataPath MakeContentDataPath () {}
};

struct TitleDataPath : public ExeFsSectionNames
{
        enum Tag
        {
                TAG_CONTENT_FILE,
                TAG_SAVE_DATA_FILE,
                TAG_LEGACY_CONTENT_FILE,
                TAG_LEGACY_SUBBANNER_FILE
        };

        util::SizedEnum4<Tag> tag;
        ContentIdx            contentIdx;

        static TitleDataPath MakeContentDataPath (ContentIdx idx) {}
        static TitleDataPath MakeSaveDataPath (ContentIdx idx) {}
        static TitleDataPath MakeLegacyContentPath (ContentIdx idx) {}
        static TitleDataPath MakeLegacySubbannerPath (ContentIdx idx) {}
};

} // namespace CTR
} // namespace fs
} // namespace nn
