#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

#ifndef BRAIN_IDEA_SIZE
# define BRAIN_IDEA_SIZE 100
#endif
#if BRAIN_IDEA_SIZE <= 0
# error "BRAIN_IDEA_SIZE must be a postive integer"
#endif

class Brain {
        std::string _ideas[BRAIN_IDEA_SIZE];

    public:
        Brain();
        Brain(const Brain &other);

        ~Brain();

        Brain &operator=(const Brain &other);

        std::string &at(std::size_t idx);

    private:
        void copy(const std::string ideas[BRAIN_IDEA_SIZE]);
};
#endif /* BRAIN_HPP */
