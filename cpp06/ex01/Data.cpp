#include "Data.hpp"

Data::Data() : _txt("empty") { }

Data::Data(const std::string &txt) : _txt(txt) { }

Data::Data(const Data &other) : _txt(other._txt) { }

Data::~Data() { }

Data &Data::operator=(const Data &other) {
        if (this != &other) {
                _txt = other._txt;
        }
        return *this;
}

const std::string &Data::txt() const {
        return _txt;
}
