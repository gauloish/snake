#define GLEW_STATIC

#include <GL/glew.h>

#include <algorithm>

#include "../include/geometry.hpp"

namespace geometry {
/**
 * @brief Initialize a block with default values
 */
Block::Block(void) {}

/**
 * @brief Initialize a block with given values
 *
 * @param x Horizontal position
 * @param y Vertical position
 * @param step Size of block side
 * @param color Block color
 */
Block::Block(GLfloat x, GLfloat y, GLfloat step, GLfloat color) { this->set(x, y, step, color); }

/**
 * @brief Initialize a block with given values
 *
 * @param x Horizontal position
 * @param y Vertical position
 * @param step Size of block side
 * @param color Block color array
 */
Block::Block(GLfloat x, GLfloat y, GLfloat step, GLfloat *color) { this->set(x, y, step, color); }

/**
 * @brief Set a block with given values
 *
 * @param x Horizontal position
 * @param y Vertical position
 * @param step Size of block side
 * @param color Block color
 */
void Block::set(GLfloat x, GLfloat y, GLfloat step, GLfloat color) {
    this->vertices[0] = Vertex{x, y, 0.0, color, color, color};
    this->vertices[1] = Vertex{x + step, y, 0.0, color, color, color};
    this->vertices[2] = Vertex{x + step, y - step, 0.0, color, color, color};
    this->vertices[3] = Vertex{x, y - step, 0.0, color, color, color};
}

/**
 * @brief Set a block with given values
 *
 * @param x Horizontal position
 * @param y Vertical position
 * @param step Size of block side
 * @param color Block color array
 */
void Block::set(GLfloat x, GLfloat y, GLfloat step, GLfloat *color) {
    this->vertices[0] = Vertex{x, y, 0.0, color[0], color[1], color[2]};
    this->vertices[1] = Vertex{x + step, y, 0.0, color[0], color[1], color[2]};
    this->vertices[2] = Vertex{x + step, y - step, 0.0, color[0], color[1], color[2]};
    this->vertices[3] = Vertex{x, y - step, 0.0, color[0], color[1], color[2]};
}
}  // namespace geometry
