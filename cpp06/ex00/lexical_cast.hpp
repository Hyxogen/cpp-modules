#ifndef LEXICAL_CAST
#define LEXICAL_CAST

#include <cerrno>
#include <cstdlib>
#include <limits>
#include <stdexcept>
#include <string>

#define FT_BASE10_RADIX 10

namespace ft {
        template<typename Target, typename Source>
        bool try_lexical_convert(Target &target, const Source &source);

        /* I only provided one overload because I wanted to show what I would do
         * if I was allowed to use the boost library */
        template<>
        bool try_lexical_convert(std::size_t &target, const std::string &source) {
                std::ptrdiff_t    pos   = 0;
                char             *end   = NULL;
                const char *const begin = source.c_str();

                target = std::strtoul(begin, &end, FT_BASE10_RADIX);
                if ((target == std::numeric_limits<std::size_t>::max()
                     && errno == ERANGE) // checking if source would be out of
                                         // range for target
                    || end == begin // checking if no conversion could be
                                    // performed
                ) {
                        return false;
                }
                pos = static_cast<std::ptrdiff_t>(end - begin);
                return (
                    source.begin() + pos
                    == source.end()); // if conversion did not reach the end, it
                                      // would mean that the source also
                                      // contained non literals in which case we
                                      // should return false
        }

	template<typename Target>
	bool try_lexical_convert(ft::enable_if_t<ft::is_floating_point<Target>::value, Target>::type &target, const std::string &source) {
		if (source == "+inf") {
			target = std::numeric_limits<Target>::infinity();
			return true;
		} else if (source == "-inf") {
			target = -std::numeric_limits<Target>::infinity();
			return true;
		} else if (source == "nan") {
			target = std::numeric_limits<Target>::quiet_NaN();
			return true;
		}
                std::ptrdiff_t    pos   = 0;
                char             *end   = NULL;
                const char *const begin = source.c_str();

		target = std::strtod(begin, &end);
		if (target == 0 && end == begin) {
			return false;
		}
		pos = static_cast<std::ptrdiff_t>(end - begin);
		return (source.begin() + pos == source.end());
	}

        template<typename Target, typename Source>
        Target lexical_cast(const Source &source) {
                Target result = Target();

                if (!try_lexical_convert(result, source)) {
                        throw std::invalid_argument("lexical_cast");
                }
                return result;
        }
}

#endif
