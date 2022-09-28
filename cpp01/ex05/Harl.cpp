#include "Harl.hpp"

#include <iostream>

Harl::Harl() { }

void Harl::debug() const {
        std::cout
            << "I love having extra bacon for my "
               "7XL-double-cheese-triple-pickle-special-ketchup burger. I "
               "really do!"
            << std::endl;
}

void Harl::info() const {
        std::cout
            << "I cannot believe adding extra bacon costs more money. You "
               "didn’t put enough bacon in my burger! If you did, I wouldn’t "
               "be asking for more!"
            << std::endl;
}

void Harl::warning() const {
        std::cout
            << "I think I deserve to have some extra bacon for free. I’ve been "
               "coming for years whereas you started working here since last "
               "month."
            << std::endl;
}

void Harl::error() const {
        std::cout << "This is unacceptable! I want to speak to the manager now."
                  << std::endl;
}

void Harl::unknown() const {
        std::cout << "I CAN'T HEAR WHAT YOU'RE SAYING!" << std::endl;
}

Harl::info_proc Harl::get_info_proc(const std::string &level) const {
        static const Harl::entry entries[4] = {
                {  "DEBUG",   &Harl::debug},
                {   "INFO",    &Harl::info},
                {"WARNING", &Harl::warning},
                {  "ERROR",   &Harl::error}
        };
        for (std::size_t idx = 0; idx < sizeof(entries) / sizeof(entries[0]);
             idx++) {
                if (entries[idx].level == level) {
                        return entries[idx].proc;
                }
        }
        return &Harl::unknown;
}

void Harl::complain(const std::string &level) const {
        const Harl::info_proc proc = get_info_proc(level);
        (this->*(proc))();
}
