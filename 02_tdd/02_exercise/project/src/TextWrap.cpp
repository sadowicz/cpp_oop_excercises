#include "TextWrap.h"

TextWrap::TextWrap(int columns) : columns(columns) {

}

std::string TextWrap::wrap(const std::string& line) const {

    if (line.size() > 1) {
        std::string result;

        for(int i = 0; i < line.size(); i += columns) {
            result += line.substr(i, columns) + ((i < line.size() - columns) ? "\n" : "");
        }

        return result;
    }

    return line;
}
