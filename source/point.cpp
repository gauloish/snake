#include "../include/point.hpp"

namespace point {
Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

void Point::set(double x, double y) {
    this->x = x;
    this->y = y;
}

double Point::get(char coordinate) {
    double value = 0;

    if (coordinate == 'x') {
        value = this->x;
    } else {
        value = this->y;
    }

    return value;
}
}  // namespace point
