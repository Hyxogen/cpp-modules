#ifndef HARL_HPP
#define HARL_HPP

#include <string>

#define HARL_INFOPROC_COUNT 8

class Harl {
    typedef void (Harl::*info_proc)() const;

    static const info_proc procs[HARL_INFOPROC_COUNT];

    void debug() const;
    void info() const;
    void warning() const;
    void error() const;
    void unknown() const;

public:
    Harl();

    void complain(const std::string &level) const;
};

std::size_t hash(const std::string &str);

#endif
