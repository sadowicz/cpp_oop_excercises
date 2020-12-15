#pragma once

#include "Point.h"

#include <vector>

class Space {
public:

    virtual ~Space() = default;

    virtual void create(unsigned int dimensions) = 0;
    virtual unsigned int dimensions() const = 0;
};