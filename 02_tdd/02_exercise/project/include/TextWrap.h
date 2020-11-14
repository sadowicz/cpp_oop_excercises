#pragma once

#include <string>
#include <stdexcept>

class TextWrap {
public:

    explicit TextWrap(int columns = 1);

    std::string wrap(const std::string &line) const;

private:
    int columns;

    std::string createWrappedLine(const std::string& line, int& substrStartIndex) const;
    void wordShrinkLine(const std::string& line, std::string& lineSubstring, int& substrStartIndex) const;
    bool isLastLine(const std::string& line, int substrStartIndex) const;
};