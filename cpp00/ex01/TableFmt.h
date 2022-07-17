#ifndef TABLE_FORMATTER_H
#define TABLE_FORMATTER_H

#include "Util.h"

#include <iomanip>
#include <ostream>
#include <sstream>

template<int ColumnWidth, int Columns, char Separator>
struct TableFmt {
private:
    std::size_t       _index;
    std::stringstream _stream;
    const std::string _separator;

public:
    TableFmt() :
        _index(0), _separator(std::string(
                       ColumnWidth * Columns + Columns + 1, Separator)) { }

    template<typename T>
    TableFmt &write(const T &t) {
        std::stringstream tmp;

        if (_index == 0) {
            _stream << _separator << std::endl << '|';
        }
        tmp << t;
        _stream << std::setw(ColumnWidth)
                << truncate(tmp.str(), ColumnWidth, '.') << '|';
        _index = (_index + 1) % Columns;
        if (_index == 0) {
            _stream << std::endl;
        }
        return *this;
    }

    std::ostream &flush(std::ostream &os) {
        os << _stream.str() << _separator << std::endl;
        _stream.clear();
        return os;
    }
};

template<int Width, int Columns, char Separator, typename T>
TableFmt<Width, Columns, Separator> &
operator<<(TableFmt<Width, Columns, Separator> &fmt, const T &t) {
    return fmt.write(t);
}

template<int Width, int Columns, char Separator>
std::ostream &
operator<<(std::ostream &os, TableFmt<Width, Columns, Separator> &fmt) {
    return fmt.flush(os);
}

#endif
