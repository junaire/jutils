#include <fmt/format.h>

///  Repeatedly output a line with all specified STRING(s), or 'y'.
int main(int argc, const char **argv) {
  if (argc == 1) {
    return 0;
  }

  while (true) {
    fmt::print("{}\n", argv[1]);
  }
}
