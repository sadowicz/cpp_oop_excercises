#include "Observer.h"

void Observer::remember(std::string question, std::string answer) {

    answers[question] = answer;
}

std::string Observer::answer(std::string question) const {

    if (not answers.count(question)) {
        return "I do not know...";
    }

    return answers.at(question);
}
