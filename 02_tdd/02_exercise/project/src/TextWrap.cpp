#include "TextWrap.h"

TextWrap::TextWrap(int columns) : columns(columns) {

}

std::string TextWrap::wrap(const std::string& line) const {

    if (line.size() > 1) {
        std::string result;

        for(int i = 0; i < line.size(); i += columns) {
            result += createWrappedLine(line.substr(i, columns), (i < line.size() - columns));
        }

        return result;
    }

    return line;
}

std::string TextWrap::createWrappedLine(std::string lineSubstring, bool isLastLine) const {
    if(lineSubstring.front() == ' '){
        lineSubstring.erase(0,1);
    }
    else if(lineSubstring.back() == ' ') {
        lineSubstring.back() = '\n';
    }
    else {
        lineSubstring += (isLastLine) ? "\n" : "";
    }
    return lineSubstring;
}
