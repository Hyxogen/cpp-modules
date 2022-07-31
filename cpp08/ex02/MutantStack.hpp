#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
    public:
        typedef std::stack<T>                                 base;
        typedef typename base::container_type::iterator       iterator;
        typedef typename base::container_type::const_iterator const_iterator;

        MutantStack() : base() { }
        MutantStack(const MutantStack &other) : base(other) { }
        ~MutantStack() { }

        MutantStack &operator=(const MutantStack &other) {
                base::operator=(other);
                return *this;
        }

        iterator begin() {
                return base::c.begin();
        }

        const_iterator begin() const {
                return base::c.begin();
        }

        iterator end() {
                return base::c.end();
        }

        const_iterator end() const {
                return base::c.end();
        }
};
#endif /* MUTANTSTACK_HPP */
