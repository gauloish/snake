#include <algorithm>

#include "../include/geometry.hpp"

namespace geometry {
/**
 * @brief Initialize a null point
 */
Point::Point(void) { this->set(0, 0); }

/**
 * @brief Initialize a point with passed coordinates
 *
 * @param x Abscissa (Horizontal)
 * @param y Ordinate (Vertical)
 */
Point::Point(double x, double y) { this->set(x, y); }

/**
 * @brief Set point coordinates
 *
 * @param x Abscissa (Horizontal)
 * @param y Ordinate (Vertical)
 */
void Point::set(double x, double y) {
    this->x = std::min(std::max(x, -1.0), 1.0);
    this->y = std::min(std::max(y, -1.0), 1.0);
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

/**
 * @brief Initialize a block with default values
 */
Block::Block(void) {
    this->position = Point(0, 0);
    this->color = 0.96;
}

/**
 * @brief Initialize a block with given position and default color
 *
 * @param x Horizontal position
 * @param y Vertical position
 */
Block::Block(double x, double y) {
    this->position = Point(x, y);
    this->color = 0.96;
}

/**
 * @brief Initialize a block with position and color given
 *
 * @param x Horizontal position
 * @param y Vertical position
 * @param color Color value
 */
Block::Block(double x, double y, double color) {
    this->position = Point(x, y);
    this->color = color;
}

/**
 * @brief Get block coordinate
 *
 * @param coordinate Coordinate char
 * @return Coordinate value
 */
double Block::get(char coordinate) { return this->position.get(coordinate); }

/**
 * @brief Draw a block in scene
 *
 * @param size Size of side block
 */
void Block::draw(double size) {
    size = 2.0 / size;

    double x = this->position.get('x');
    double y = this->position.get('y');
}

/**
 * @brief Set block to other position
 *
 * @param x Horizontal position
 * @param y Vertical position
 */
void Block::set(double x, double y) { this->position.set(x, y); }

/**
 * @brief Move block to other position
 *
 * @param x Horizontal position
 * @param y Vertical position
 */
void Block::move(double x, double y) {
    x += this->position.get('x');
    y += this->position.get('y');

    this->move(x, y);
}

}  // namespace geometry
