#include <nn/err/CTR/err_Api.h>
#include <nn/fs/CTR/MPCore/fs_UserFileSystem.h>
#include <nn/fs/detail/fs_FileSystemBase.h>
#include <nn/fs/fs_Api.h>
#include <nn/srv/srv_Api.h>

RP_SHUTUP

namespace nn {
namespace fs {

namespace {
var(nn::fs, s_FileServerSession, Handle);

var(nn::fs, s_FileSystemBaseImpl, int /* ? */);
var(nn::fs, s_FileSystemBase, detail::FileSystemBase);
} // namespace

} // namespace fs
} // namespace nn
