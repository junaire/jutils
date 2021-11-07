#include <absl/strings/str_split.h>
#include <fmt/format.h>
#include <gflags/gflags.h>
#include <unistd.h>

#include <ranges>
#include <string>
#include <vector>

static const char* const usage =
    R"(Usage: rmdir [OPTION]... DIRECTORY...
    Remove the DIRECTORY(ies), if they are empty.

          --ignore-fail-on-non-empty
                      ignore each failure that is solely because a directory
                        is non-empty
      -p, --parents   remove DIRECTORY and its ancestors; e.g., 'rmdir -p a/b/c' is
                        similar to 'rmdir a/b/c a/b a'
      -v, --verbose   output a diagnostic for every directory processed
          --help     display this help and exit
          --version  output version information and exit)";

DEFINE_bool(parents, false, "remove DIRECTORY and its ancestors");

static bool removePath(const char* path) {
  bool flag = true;
  int res = rmdir(path);
  if (res != 0) {
    flag = false;
  }
  return flag;
}

static bool removePaths(const char* path) {
  // auto paths = absl::StrSplit(path, "/");
  // for (auto path : std::ranges::views::reverse(paths)) {
  //   removePath(path.c_str());
  // }
  return true;
}

int main(int argc, char** argv) {
  gflags::SetUsageMessage(usage);
  gflags::SetVersionString("0.0.1");
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  if (argc == 1) {
    return 0;
  }

  if (FLAGS_parents) {
    removePaths(argv[1]);
  } else {
    if (auto flag = removePath(argv[1]) == false) {
      fmt::print("fail to remove {}\n", argv[1]);
    }
  }

  gflags::ShutDownCommandLineFlags();
}
