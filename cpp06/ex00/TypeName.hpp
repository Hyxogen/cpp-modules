#ifndef TYPENAME_HPP
#define TYPENAME_HPP

#include <string>

template<class T>
struct TypeName;

#define DEFINE_TYPE_NAME(type)                                                 \
 template<>                                                                    \
 struct TypeName<type> {                                                       \
  static std::string name() {                                                  \
   return #type;                                                               \
  }                                                                            \
 };

DEFINE_TYPE_NAME(char)
DEFINE_TYPE_NAME(int)
DEFINE_TYPE_NAME(float)
DEFINE_TYPE_NAME(double)

#endif /* TYPENAME_HPP */
