#include "TextWrap.h"

TextWrap::TextWrap(int columns) : columns(columns) {

}

std::string TextWrap::wrap(const std::string& line) const {

    if (line.size() > 1) {

        return line.substr(0, columns) + "\n" + line.substr(columns);
    }

    return line;
}
