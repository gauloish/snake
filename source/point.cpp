#include "../include/point.hpp"

namespace point {
/**
 * @brief Initialize a null point
 */
Point::Point(void) {
    this->x = 0;
    this->y = 0;
}

/**
 * @brief Initialize a point with passed coordinates
 *
 * @param x Abscissa (Horizontal)
 * @param y Ordinate (Vertical)
 */
Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

/**
 * @brief Set point coordinates
 *
 * @param x Abscissa (Horizontal)
 * @param y Ordinate (Vertical)
 */
void Point::set(double x, double y) {
    this->x = x;
    this->y = y;
}

/**
 * @brief Return a point coordinate value
 *
 * @param coordinate Coordinate char
 * @return Coordinate value
 */
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
