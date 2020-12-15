#include "Space.h"

#include <limits>

void Space::create(unsigned int dimensions) {

    dimensionsCount = dimensions;

    auto infiniteNumberOfPoints = std::numeric_limits<std::size_t>::max();
    points.resize(infiniteNumberOfPoints);
}

unsigned int Space::dimensions() const {
    return dimensionsCount;
}
