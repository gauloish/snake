#include "../include/point.hpp"

namespace point {
Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

void Point::set(int x, int y) {
    this->x = x;
    this->y = y;
}

int Point::get(char coordinate) {
    int value = 0;

    if (coordinate == 'x') {
        value = this->x;
    } else {
        value = this->y;
    }

    return value;
}
}  // namespace point
