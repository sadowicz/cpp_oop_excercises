#pragma once

#include "Space.h"
#include "TestIncludes.h"

class SpaceMock : public Space {

public:

    MOCK_METHOD1(create, void(unsigned int dimensions));
    MOCK_CONST_METHOD0(dimensions, unsigned int());
};