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

/**
 * @brief Draw a block in scene
 *
 * @param size Size of side block
 */
void Block::draw(double size) {
    size = 2.0 / size;

    double x = this->position.get('x');
    double y = this->position.get('y');

    glColor3d(this->color, this->color, this->color);

    glBegin(GL_POLYGON);
    glVertex2d(x, y);
    glVertex2d(x + size, y);
    glVertex2d(x + size, y - size);
    glVertex2d(x, y - size);
    glEnd();
}

/**
 * @brief Move block to other position
 *
 * @param x Horizontal position
 * @param y Vertical position
 */
void Block::move(double x, double y) {
    this->position.set(x, y);
    //
}
}  // namespace snake
