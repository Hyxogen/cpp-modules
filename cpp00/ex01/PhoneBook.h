#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"

#include <cstddef>
#include <ostream>

#ifndef CONTACT_SIZE
# define CONTACT_SIZE 2
#elif CONTACT_SIZE <= 0
# error "CONTACT_SIZE must be a positive integer"
#endif

struct PhoneBook {
    typedef Contact           value_type;
    typedef std::size_t       size_type;
    typedef std::ptrdiff_t    difference_type;
    typedef value_type       &reference;
    typedef const value_type &const_reference;
    typedef value_type       *pointer;
    typedef const value_type *const_pointer;
    typedef pointer           iterator;
    typedef const_pointer     const_iterator;

private:
    size_type  _index, _size;
    value_type contacts[CONTACT_SIZE];

    size_type increment_index();

    pointer       data();
    const_pointer data() const;

    size_type &size();
    size_type &index();

    iterator begin();
    iterator end();

    reference operator[](size_type pos);

public:
    PhoneBook();

    void add_contact(const_reference contact);

    reference       at(size_type pos);
    const_reference at(size_type pos) const;

    const_iterator begin() const;
    const_iterator end() const;

    const_iterator cbegin() const;
    const_iterator cend() const;

    size_type size() const;
    size_type index() const;

    const_reference operator[](size_type pos) const;
};

std::ostream &operator<<(std::ostream &os, const PhoneBook &phone_book);

#endif
