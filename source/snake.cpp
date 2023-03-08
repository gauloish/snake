#include <GL/gl.h>

#include <algorithm>

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
void Block::move(double x, double y) { this->position.set(x, y); }

/**
 * @brief Shift block to other position
 *
 * @param x Horizontal position
 * @param y Vertical position
 */
void Block::shift(double x, double y) {
    x += this->position.get('x');
    y += this->position.get('y');

    this->move(x, y);
}

/**
 * @brief Initalize snake with default position and color
 *
 * @tparam amount Size of snake
 */
template <const unsigned amount>
Snake<amount>::Snake(void) {
    for (int index = 0; index < amount; index++) {
        this->blocks[index] = Block();
    }
}

/**
 * @brief Initialize the snake with given position and default color
 *
 * @tparam amount Size of snake
 * @param x Initial horizontal position
 * @param y Initial vertical position
 */
template <const unsigned amount>
Snake<amount>::Snake(double x, double y) {
    for (int index = 0; index < amount; index++) {
        this->blocks[index] = Block(x, y);
    }
}

/**
 * @brief Initialize the snake with given position and color
 *
 * @tparam amount Size of snake
 * @param x Initial horizontal position
 * @param y Initial vertical position
 * @param color Snake color
 */
template <const unsigned amount>
Snake<amount>::Snake(double x, double y, double color) {
    for (int index = 0; index < amount; index++) {
        this->blocks[index] = Block(x, y, color);
    }
}

/**
 * @brief Draw the snake
 *
 * @tparam amount Size of snake
 * @param size Size of side block
 */
template <const unsigned amount>
void Snake<amount>::draw(double size) {
    for (int index = 0; index < this->size; index++) {
        this->blocks[index].draw(size);
    }
}

/**
 * @brief Move the snake
 *
 * @tparam amount Size of snake
 * @param size Size of side block
 * @param hor Sense in horizontal
 * @param ver Sense in vertical
 */
template <const unsigned amount>
void Snake<amount>::move(double size, int hor, int ver) {
    size = 2.0 / size;

    for (int index = 1; index < this->size; index++) {
        double x = this->blocks[index - 1].get('x');
        double y = this->blocks[index - 1].get('y');

        this->blocks[index].move(x, y);
    }

    this->blocks[0].shift(size * hor, size * ver);
}

/**
 * @brief Added one more block to snake
 */
template <const unsigned amount>
void Snake<amount>::shift(void) {
    this->size = std::min(amount, this->size + 1);
}

}  // namespace snake
