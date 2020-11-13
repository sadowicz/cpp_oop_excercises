#include "TextWrap.h"

TextWrap::TextWrap(int columns) : columns(columns) {

}

std::string TextWrap::wrap(const std::string& line) const {

    if (line.size() > 1) {
        std::string result;

        for(int i = 0; i < line.size(); i += columns) {
            result += createWrappedLine(line, i);
        }

        return result;
    }

    return line;
}

std::string TextWrap::createWrappedLine(const std::string& line, int& substrStartIndex) const {

    std::string lineSubstring = line.substr(substrStartIndex, columns);

    if(lineSubstring.front() == ' '){
        lineSubstring.erase(0,1);

        if(!isLastLine(line, substrStartIndex)) {
            lineSubstring.push_back(line[substrStartIndex + columns]);
            substrStartIndex++;
        }
    }

    if(lineSubstring.back() == ' ') {
        lineSubstring.back() = '\n';
    }
    else {
        lineSubstring += (!isLastLine(line, substrStartIndex)) ? "\n" : "";
    }

    return lineSubstring;
}

bool TextWrap::isLastLine(const std::string& line, int substrStartIndex) const {
    return (substrStartIndex >= line.size() - columns);
}
