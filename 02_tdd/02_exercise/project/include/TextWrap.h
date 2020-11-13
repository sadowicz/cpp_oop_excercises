#pragma once

#include <string>

class TextWrap {
public:

    explicit TextWrap(int columns = 1);

    std::string wrap(const std::string &line) const;

private:
    int columns;

    std::string createWrappedLine(const std::string& line, int& substrStartIndex) const;
};