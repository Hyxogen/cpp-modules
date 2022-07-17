#include "Harl.hpp"

#include <iostream>

const Harl::info_proc Harl::procs[HARL_INFOPROC_COUNT] = {
    &Harl::unknown, &Harl::unknown, &Harl::error,   &Harl::unknown,
    &Harl::info,    &Harl::unknown, &Harl::warning, &Harl::debug
};

Harl::Harl() { }

void Harl::debug() const {
    std::cout << "I love having extra bacon for my "
                 "7XL-double-cheese-triple-pickle-special-ketchup burger. I "
                 "really do!"
              << std::endl;
}

void Harl::info() const {
    std::cout << "I cannot believe adding extra bacon costs more money. You "
                 "didn’t put enough bacon in my burger! If you did, I wouldn’t "
                 "be asking for more!"
              << std::endl;
}

void Harl::warning() const {
    std::cout
        << "I think I deserve to have some extra bacon for free. I’ve been "
           "coming for years whereas you started working here since last month."
        << std::endl;
}

void Harl::error() const {
    std::cout << "This is unacceptable! I want to speak to the manager now."
              << std::endl;
}

void Harl::unknown() const {
    std::cout << "I CAN'T HEAR WHAT YOU'RE SAYING!" << std::endl;
}

void Harl::complain(const std::string &level) const {
    info_proc proc = procs[hash(level) % HARL_INFOPROC_COUNT];
    (this->*(proc))();
}

std::size_t hash(const std::string &str) {
    std::size_t result = 0;

    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        result += static_cast<int>(*it);
    }
    return result;
}
