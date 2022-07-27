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
        long                                l = static_cast<long>(source);
        return (
            static_cast<long>(target_limits::lowest()) <= l
            && l <= static_cast<long>(target_limits::max()));
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

void print_char(int i) {
        std::cout << TypeName<char>::name() << ": ";
        if (i < 0 || i > std::numeric_limits<char>::max()) {
                std::cout << "impossible" << std::endl;
        } else if (!std::isprint(i)) {
                std::cout << "Non displayable" << std::endl;
        } else {
                std::cout << static_cast<char>(i) << std::endl;
        }
}

void print_char(long l) {
        if (!can_cast_integral_to_integral<long, char>(l)) {
                std::cout << TypeName<char>::name() << ": impossible"
                          << std::endl;
        } else {
                print_char(static_cast<int>(l));
        }
}

void print_char(double d) {
        if (!can_cast_float_to_integral<double, int>(d)) {
                std::cout << TypeName<char>::name() << ": impossible"
                          << std::endl;
        } else {
                print_char(static_cast<long>(d));
        }
}

void print_int(int i) {
        std::cout << TypeName<int>::name() << ": " << i << std::endl;
}

void print_int(long l) {
        if (!can_cast_integral_to_integral<long, int>(l)) {
                std::cout << TypeName<int>::name() << ": impossible"
                          << std::endl;
        } else {
                print_int(static_cast<int>(l));
        }
}

void print_int(double d) {
        if (!can_cast_float_to_integral<double, int>(d)) {
                std::cout << TypeName<int>::name() << ": impossible"
                          << std::endl;
        } else {
                print_int(static_cast<long>(d));
        }
}

void print_float(float f) {
        std::cout << TypeName<float>::name() << ": " << f << "f" << std::endl;
}

void print_float(double d) {
        typedef std::numeric_limits<float> float_limits;
        if (std::abs(d) == std::numeric_limits<double>::infinity() || d != d) {
                print_float(static_cast<float>(d));
        } else if (
            static_cast<double>(float_limits::lowest()) <= d
            && d <= static_cast<double>(float_limits::max())) {
                print_float(static_cast<float>(d));
        } else {
                std::cout << TypeName<float>::name() << ": impossible"
                          << std::endl;
        }
}

void print_float(int i) {
        print_float(static_cast<float>(i));
}

void print_double(double d) {
        std::cout << TypeName<double>::name() << ": " << d << std::endl;
}

void print_double(int i) {
        print_double(static_cast<double>(i));
}

template<typename T>
void print_conversions(T t) {
        print_char(t);
        print_int(t);
        print_float(t);
        print_double(t);
}

template<typename Target>
bool try_convert(const std::string &source, Target &target);

template<>
bool try_convert<long>(const std::string &source, long &target) {
        std::ptrdiff_t                    pos   = 0;
        char                             *end   = 0;
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
        long l = as_type<long>(source);
        if (!can_cast_integral_to_integral<long, int>(l)) {
                return false;
        }
        target = static_cast<int>(l);
        return true;
}

template<>
bool try_convert<char>(const std::string &source, char &target) {
        if (source.length() != 1)
                return false;
        target = source.at(0);
        return std::isprint(static_cast<int>(target));
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
        char             *end   = 0;
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
        char             *end   = 0;
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
                T t = as_type<T>(str);
                print_conversions(t);
                return true;
        } catch (const std::exception &ex) {
                return false;
        }
}

void print_conversions(const std::string &str) {
        if (print_x_conversions<int>(str))
                return;
        if (print_x_conversions<char>(str))
                return;
        if (print_x_conversions<double>(str))
                return;
        if (print_x_conversions<float>(str))
                return;
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
