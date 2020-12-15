#pragma once

class Observer {
public:

    virtual ~Observer() = default;

    virtual void remember(std::string question, std::string answer) = 0;
    virtual std::string answer(std::string question) const = 0;

};
