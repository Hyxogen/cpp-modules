#include <iostream>
#include <limits>
#include <stdexcept>

#include "TypeName.hpp"

static const int BASE10_RADIX = 10;

template<typename T>
T as_type(const std::string &str);

void print_error() {
        std::cerr << "failed to convert" << std::endl;
}

template<typename Source, typename Target>
bool can_cast_integral_to_integral(const Source &source) {
        typedef std::numeric_limits<Target> target_limits;
        long                                val = static_cast<long>(source);
        return (
            static_cast<long>(target_limits::lowest()) <= val
            && val <= static_cast<long>(target_limits::max()));
}

template<typename Source, typename Target>
bool can_cast_float_to_integral(const Source &source) {
        if (source != source) {
                return false;
        }
        typedef std::numeric_limits<long> long_limits;
        const bool                        can_cast_to_long =
            static_cast<double>(long_limits::lowest())
                <= static_cast<double>(source)
            && static_cast<double>(source)
                   <= -static_cast<double>(long_limits::lowest());
        return (
            can_cast_to_long
            && can_cast_integral_to_integral<long, Target>(
                static_cast<long>(source)));
}

void print_char(int val) {
        std::cout << TypeName<char>::name() << ": ";
        if (val < 0 || val > std::numeric_limits<char>::max()) {
                std::cout << "impossible" << std::endl;
        } else if (std::isprint(val) == 0) {
                std::cout << "Non displayable" << std::endl;
        } else {
                std::cout << static_cast<char>(val) << std::endl;
        }
}

void print_char(long val) {
        if (!can_cast_integral_to_integral<long, char>(val)) {
                std::cout << TypeName<char>::name() << ": impossible"
                          << std::endl;
        } else {
                print_char(static_cast<int>(val));
        }
}

void print_char(double val) {
        if (!can_cast_float_to_integral<double, int>(val)) {
                std::cout << TypeName<char>::name() << ": impossible"
                          << std::endl;
        } else {
                print_char(static_cast<long>(val));
        }
}

void print_int(int val) {
        std::cout << TypeName<int>::name() << ": " << val << std::endl;
}

void print_int(long val) {
        if (!can_cast_integral_to_integral<long, int>(val)) {
                std::cout << TypeName<int>::name() << ": impossible"
                          << std::endl;
        } else {
                print_int(static_cast<int>(val));
        }
}

void print_int(double val) {
        if (!can_cast_float_to_integral<double, int>(val)) {
                std::cout << TypeName<int>::name() << ": impossible"
                          << std::endl;
        } else {
                print_int(static_cast<long>(val));
        }
}

void print_float(float val) {
        std::cout << TypeName<float>::name() << ": " << val << "f" << std::endl;
}

void print_float(double val) {
        typedef std::numeric_limits<float> float_limits;
        if (std::abs(val) == std::numeric_limits<double>::infinity()
            || val != val
            || (static_cast<double>(float_limits::lowest()) <= val
                && val <= static_cast<double>(float_limits::max()))) {
                print_float(static_cast<float>(val));
        } else {
                std::cout << TypeName<float>::name() << ": impossible"
                          << std::endl;
        }
}

void print_float(int val) {
        print_float(static_cast<float>(val));
}

void print_double(double val) {
        std::cout << TypeName<double>::name() << ": " << val << std::endl;
}

void print_double(int val) {
        print_double(static_cast<double>(val));
}

template<typename T>
void print_conversions(T val) {
        print_char(val);
        print_int(val);
        print_float(val);
        print_double(val);
}

template<typename Target>
bool try_convert(const std::string &source, Target &target);

template<>
bool try_convert<long>(const std::string &source, long &target) {
        std::ptrdiff_t                    pos   = 0;
        char                             *end   = NULL;
        const char *const                 begin = source.c_str();
        typedef std::numeric_limits<long> target_limits;

        target = std::strtol(begin, &end, BASE10_RADIX);
        if (((target == target_limits::max()
              || target == target_limits::lowest())
             && errno == ERANGE)
            || end == begin) {
                return false;
        }
        pos = static_cast<std::ptrdiff_t>(end - begin);
        return (source.begin() + pos == source.end());
}

template<>
bool try_convert<int>(const std::string &source, int &target) {
        long val = as_type<long>(source);
        if (!can_cast_integral_to_integral<long, int>(val)) {
                return false;
        }
        target = static_cast<int>(val);
        return true;
}

template<>
bool try_convert<char>(const std::string &source, char &target) {
        if (source.length() != 1) {
                return false;
        }
        target = source.at(0);
        return std::isprint(static_cast<int>(target)) != 0;
}

template<>
bool try_convert<float>(const std::string &source, float &target) {
        typedef std::numeric_limits<float> target_limits;
        if (source == "inff") {
                target = target_limits::infinity();
                return true;
        } else if (source == "-inff") {
                target = -target_limits::infinity();
                return true;
        } else if (source == "nanf") {
                target = target_limits::quiet_NaN();
                return true;
        }
        std::ptrdiff_t    pos   = 0;
        char             *end   = NULL;
        const char *const begin = source.c_str();

        target = std::strtof(begin, &end);
        if (target == target_limits::infinity()
            || (target == 0 && end == begin)) {
                return false;
        }
        pos = static_cast<std::ptrdiff_t>(end - begin);
        return (
            source.begin() + pos == source.end()
            || ((source.begin() + pos + 1 == source.end())
                && *(source.end() - 1) == 'f'));
}

template<>
bool try_convert<double>(const std::string &source, double &target) {
        typedef std::numeric_limits<double> target_limits;
        if (source == "inf") {
                target = target_limits::infinity();
                return true;
        } else if (source == "-inf") {
                target = -target_limits::infinity();
                return true;
        } else if (source == "nan") {
                target = target_limits::quiet_NaN();
                return true;
        }
        std::ptrdiff_t    pos   = 0;
        char             *end   = NULL;
        const char *const begin = source.c_str();

        target = std::strtod(begin, &end);
        if (target == target_limits::infinity()
            || (target == 0 && end == begin)) {
                return false;
        }
        pos = static_cast<std::ptrdiff_t>(end - begin);
        return (
            source.begin() + pos == source.end()
            || ((source.begin() + pos + 1 == source.end())
                && *(source.end() - 1) == 'd'));
}

template<typename T>
T as_type(const std::string &str) {
        T result = T();
        if (!try_convert(str, result)) {
                throw std::invalid_argument("unable to convert");
        }
        return result;
}

template<typename T>
bool print_x_conversions(const std::string &str) {
        try {
                T val = as_type<T>(str);
                print_conversions(val);
                return true;
        } catch (const std::exception &ex) {
                return false;
        }
}

void print_conversions(const std::string &str) {
        if (print_x_conversions<int>(str)) {
                return;
        }
        if (print_x_conversions<char>(str)) {
                return;
        }
        if (print_x_conversions<double>(str)) {
                return;
        }
        if (print_x_conversions<float>(str)) {
                return;
        }
        print_error();
}

int main(int argc, char **argv) {
        if (argc != 2) {
                std::cerr << "usage " << argv[0] << " literal|pseudoliteral"
                          << std::endl;
                return 0;
        }
        print_conversions(std::string(argv[1]));
        return 0;
}
