#include <fmt/format.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>

/// Print the user name associated with the current effective user ID.  Same as
/// id -un.
int main() {
  uid_t uid = geteuid();

  if (!uid) {
    return 0;
  }

  const auto* passwd = getpwuid(uid);
  fmt::print("{}\n", passwd->pw_name);
}
