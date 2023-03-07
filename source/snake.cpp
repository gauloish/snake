#include <GL/gl.h>

#include "../include/point.hpp"
#include "../include/snake.hpp"

namespace snake {
/**
 * @brief Initialize a block with default values
 */
Block::Block(void) {
    this->position = point::Point(0, 0);
    this->color = 0.96;
}

/**
 * @brief Initialize a block with given position and default color
 *
 * @param x Horizontal position
 * @param y Vertical position
 */
Block::Block(double x, double y) {
    this->position = point::Point(x, y);
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
    this->position = point::Point(x, y);
    this->color = color;
}
}  // namespace snake
