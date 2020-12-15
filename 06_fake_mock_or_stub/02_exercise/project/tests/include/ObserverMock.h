#pragma once

#include "Observer.h"
#include "TestIncludes.h"

class ObserverMock : public Observer {

public:

    MOCK_METHOD2(remember, void(std::string question, std::string answer));
    MOCK_CONST_METHOD1(answer, std::string(std::string question));
};