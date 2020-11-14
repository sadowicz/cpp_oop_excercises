#include "TextWrap.h"

TextWrap::TextWrap(int columns) : columns(columns) {
    if(!this->columns) {
        throw std::invalid_argument{"Zero passed as columns."};
    }
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

    int lastWordStartSubstr = lineSubstring.find_last_of(' '); // space before last word index in substring
    int lastWordEndLine;

    if(lastWordStartSubstr != std::string::npos) {
        int lastWordStartLine = lastWordStartSubstr + substrStartIndex + 1; // last word first letter index in line string
        lastWordEndLine = line.find_first_of(' ', lastWordStartLine); // space after last word index in line string

        if(lastWordEndLine != std::string::npos) {
            lastWordEndLine--;  // last word last letter index in line string
        }
        else {
            lastWordEndLine = static_cast<int>(line.length()) - 1; // last index of line string because no spaces in line
        }

        if(lastWordEndLine >= substrStartIndex + columns) {
            int oldSubstrLen = lineSubstring.length();
            lineSubstring = line.substr(substrStartIndex, lastWordStartSubstr); // substr end before last space of old substr
            substrStartIndex -= static_cast<int>(oldSubstrLen - lineSubstring.length());
        }
    }

    if(isLastLine(lineSubstring, substrStartIndex) && lineSubstring.back() == ' ') {
        lineSubstring.pop_back();
    }
    else {
        lineSubstring += (!isLastLine(line, substrStartIndex)) ? "\n" : "";
    }

    return lineSubstring;
}

bool TextWrap::isLastLine(const std::string& line, int substrStartIndex) const {
    return (substrStartIndex >= static_cast<int>(line.length()) - columns);
}
