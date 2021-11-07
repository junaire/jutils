#include <fmt/format.h>

#include <cstdlib>

///        Print the full filename of the current working directory.
///
///       -L, --logical
///              use PWD from environment, even if it contains symlinks
///
///       -P, --physical
///              avoid all symlinks
///
///       --help display this help and exit
///
///       --version
///              output version information and exit
///
///       If no option is specified, -P is assumed.

int main() {
    const auto* pwd = secure_getenv("PWD");
    fmt::print("{}\n", pwd);
}
