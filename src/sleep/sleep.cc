#include <fmt/format.h>
#include <gflags/gflags.h>

#include <cstdlib>
#include <ctime>

#define N 1e9
static const char* const usage =
    R"( Usage: sleep NUMBER[SUFFIX]...
  or:  sleep OPTION
Pause for NUMBER seconds.  SUFFIX may be 's' for seconds (the default),
'm' for minutes, 'h' for hours or 'd' for days.  NUMBER need not be an
integer.  Given two or more arguments, pause for the amount of time
specified by the sum of their values.

      --help     display this help and exit
      --version  output version information and exit)";

int main(int argc, char** argv) {
  gflags::SetUsageMessage(usage);
  gflags::SetVersionString("0.0.1");
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  if (argc == 1) {
    return 0;
  }

  double d = 0;
  char buf[2];
  struct timespec timeToSleep;

  // TODO(Jun): support GNU style sleep
  if (sscanf(argv[1], "%lf%1s", &d, buf) != 0) {
    return 0;
  }

  timeToSleep.tv_sec = static_cast<time_t>(d);
  timeToSleep.tv_nsec = N * (d - timeToSleep.tv_sec);

  int res = nanosleep(&timeToSleep, &timeToSleep);
  fmt::print("{}\n", res);

  gflags::ShutDownCommandLineFlags();
}
