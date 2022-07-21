#include <iostream>
#include <limits>
#include <cctype>

namespace ft {
	template<class T, T v>
	struct integral_constant {
		static const T value = v;
		typedef T type;
	};

	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;

	template<bool Condition, class T>
	struct enable_if { };

	template<class T>
	struct enable_if<true, T> {
		typedef T type;
	};

	template<class T, class U>
	struct is_same : false_type { };

	template<class T>
	struct is_same<T, T> : true_type { };
}

template<typename T>
struct type_name;

#define DEFINE_TYPE_NAME(type) \
	template<> \
	struct type_name<type> { \
		static const std::string name() { return #type; } \
	};

DEFINE_TYPE_NAME(char)
DEFINE_TYPE_NAME(int)
DEFINE_TYPE_NAME(float)
DEFINE_TYPE_NAME(double)

template<typename To, typename From>
typename ft::enable_if<(not ft::is_same<To, char>::value), void>::type display_conversion(const From &from) {
	const std::string name = type_name<To>::name();
	if (from > static_cast<From>(std::numeric_limits<To>::max()) || from < static_cast<From>(std::numeric_limits<To>::min())) {
		std::cout << name << ": impossible" << std::endl;
	} else { 
		std::cout << name << ": " << static_cast<To>(from) << std::endl;
	}
}

/* partial specialization for char */
template<typename To, typename From>
typename ft::enable_if<ft::is_same<To, char>::value, void>::type display_conversion(const From &from) {
	const std::string name = "char";
	if (from > static_cast<From>(std::numeric_limits<char>::max()) || from < static_cast<From>(std::numeric_limits<char>::min())) {
		std::cout << name << ": impossible" << std::endl;
	} else if (!isprint(static_cast<int>(from))) {
		std::cout << name << ": Non displayable" << std::endl;
	} else { 
		std::cout << name << ": " << static_cast<char>(from) << std::endl;
	}
}


int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "usage " << argv[0] << " literal|pseudo_literal" << std::endl;
		return 0;
	}
	const int i = 500;
	display_conversion<char>(i);
	return 0;
}
