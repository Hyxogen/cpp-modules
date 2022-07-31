#include <cassert>
#include <iostream>

#include "MutantStack.hpp"

#define ASSERT_THROW(x, type)                                                  \
 try {                                                                         \
  x;                                                                           \
  assert(0 && "Did not throw");                                                \
 } catch (const type &ex) {                                                    \
  (void) ex;                                                                   \
 } catch (const std::exception &ex) {                                          \
  assert(0 && "Threw something else");                                         \
 }

#define ASSERT_NOTHROW(x)                                                      \
 try {                                                                         \
  x;                                                                           \
 } catch (const std::exception &ex) {                                          \
  (void) ex;                                                                   \
  assert(0 && "Did throw");                                                    \
 }

#define ASSERT_EQUAL(a, b)  assert((a == b) && "Not equal")
#define ASSERT_NEQUAL(a, b) assert((a != b) && "Not equal")
#define ASSERT_TRUE(cond)   assert((cond) && "False")
#define ASSERT_FALSE(cond)  assert(!(cond) && "True")

void pushpop_tests() {
        MutantStack<int> mstack;

        ASSERT_TRUE(mstack.empty());

        mstack.push(5);
        ASSERT_FALSE(mstack.empty());
        ASSERT_EQUAL(mstack.size(), 1);
        ASSERT_EQUAL(mstack.top(), 5);

        mstack.push(17);
        ASSERT_FALSE(mstack.empty());
        ASSERT_EQUAL(mstack.size(), 2);
        ASSERT_EQUAL(mstack.top(), 17);

        mstack.pop();
        ASSERT_FALSE(mstack.empty());
        ASSERT_EQUAL(mstack.size(), 1);
        ASSERT_EQUAL(mstack.top(), 5);

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        ASSERT_EQUAL(mstack.size(), 4);
        ASSERT_EQUAL(mstack.top(), 737);
}

void iterator_tests() {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        ASSERT_NEQUAL(it, mstack.end());
        ASSERT_EQUAL(*it, 5);
        ++it;
        ASSERT_EQUAL(*it, 17);
        ++it;
        ASSERT_EQUAL(*it, 3);
        ++it;
        ASSERT_EQUAL(*it, 5);
        ++it;
        ASSERT_EQUAL(*it, 737);
        ++it;
        ASSERT_EQUAL(*it, 0);
	++it;
	ASSERT_EQUAL(it, mstack.end());
}

int main() {
        pushpop_tests();
        iterator_tests();
        return 0;
}
