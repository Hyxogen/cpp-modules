#include <iostream>

#include "Harl.hpp"

#define LEVELS_COUNT 4

#define LEVELS_LIST                                                            \
 X(DEBUG)                                                                      \
 X(INFO)                                                                       \
 X(WARNING)                                                                    \
 Y(ERROR)

enum Level {
#define X(level) level,
#define Y(level) level
        LEVELS_LIST
#undef X
#undef Y
};

const static std::string LEVELS[LEVELS_COUNT] = {
#define X(level) #level,
#define Y(level) #level
        LEVELS_LIST
#undef X
#undef Y
};

static void complain_all(const Harl &harl, int level) {
        switch (level) {
        default:
                harl.complain("UNKNOWN");
                break;
#define X(level)                                                               \
 case level:                                                                   \
  std::cout << "[ " << LEVELS[level] << " ]" << std::endl;                     \
  harl.complain(LEVELS[level]);
#define Y(level) X(level)
                LEVELS_LIST
#undef X
#undef Y
        }
}

int main(int argc, char **argv) {
        if (argc != 2) {
                std::cerr << argv[0] << " <level>" << std::endl;
                return 1;
        }
#define X(level)                                                               \
 if (LEVELS[level] == argv[1]) {                                               \
  complain_all(Harl(), level);                                                 \
  return 0;                                                                    \
 }
#define Y(level) X(level)
        LEVELS_LIST
#undef X
#undef Y
        complain_all(Harl(), -1);
        return 0;
}
