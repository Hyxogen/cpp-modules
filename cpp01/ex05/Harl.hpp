#ifndef HARL_HPP
#define HARL_HPP

#include <string>

#define HARL_INFOPROC_COUNT 8

class Harl {
        typedef void (Harl::*info_proc)() const;

        struct entry {
                std::string     level;
                Harl::info_proc proc;
        };

        void debug() const;
        void info() const;
        void warning() const;
        void error() const;
        void unknown() const;

        Harl::info_proc get_info_proc(const std::string &level) const;

    public:
        Harl();

        void complain(const std::string &level) const;
};
#endif
