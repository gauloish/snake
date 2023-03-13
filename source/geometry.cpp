#include <algorithm>

#include "../include/geometry.hpp"

namespace geometry {
/**
 * @brief Initialize a block with default values
 */
Block::Block(void) { this->set(0.0, 0.0, 0.0, 0.0); }

/**
 * @brief Initialize a block with given values
 *
 * @param x Horizontal position
 * @param y Vertical position
 * @param step Size of block side
 * @param color Block color
 */
Block::Block(double x, double y, double step, double color) {
    this->set(x, y, step, color);
}

/**
 * @brief Set a block with given values
 *
 * @param x Horizontal position
 * @param y Vertical position
 * @param step Size of block side
 * @param color Block color
 */
void Block::set(double x, double y, double step, double color) {
    this->vertices[0] = Vertex{x, y, 1.0, color, color, color};
    this->vertices[1] = Vertex{x + step, y, 1.0, color, color, color};
    this->vertices[2] = Vertex{x + step, y - step, 1.0, color, color, color};
    this->vertices[3] = Vertex{x, y - step, 1.0, color, color, color};
}
}  // namespace geometry
