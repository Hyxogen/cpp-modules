#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data {
        std::string _txt;

    public:
        Data();
        Data(const std::string &txt);
        Data(const Data &other);

        ~Data();

        Data &operator=(const Data &other);

        const std::string &txt() const;
};
#endif /* DATA_HPP */
