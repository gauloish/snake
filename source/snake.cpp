#include <algorithm>
#include <vector>

#include "../include/geometry.hpp"
#include "../include/snake.hpp"

namespace snake {
/**
 * @brief Initalize snake with default position and color
 *
 * @param amount Size of snake
 */
Snake::Snake(const unsigned amount) : amount(amount) {
    this->blocks = std::vector<geometry::Block>(this->amount);

    for (int index = 0; index < this->amount; index++) {
        this->blocks[index] = geometry::Block();
    }
}

/**
 * @brief Initialize the snake with given position and default color
 *
 * @param x Initial horizontal position
 * @param y Initial vertical position
 * @param amount Size of snake
 */
Snake::Snake(double x, double y, const unsigned amount) : amount(amount) {
    this->blocks = std::vector<geometry::Block>(this->amount);

    for (int index = 0; index < amount; index++) {
        this->blocks[index] = geometry::Block(x, y);
    }
}

/**
 * @brief Initialize the snake with given position and color
 *
 * @param x Initial horizontal position
 * @param y Initial vertical position
 * @param color Snake color
 * @param amount Size of snake
 */
Snake::Snake(double x, double y, double color, const unsigned amount)
    : amount(amount) {
    this->blocks = std::vector<geometry::Block>(this->amount);

    for (int index = 0; index < amount; index++) {
        this->blocks[index] = geometry::Block(x, y, color);
    }
}

/**
 * @brief Draw the snake
 *
 * @param size Size of side block
 */
void Snake::draw(double size) {
    for (int index = 0; index < this->size; index++) {
        this->blocks[index].draw(size);
    }
}

/**
 * @brief Move the snake
 *
 * @param size Size of side block
 * @param horizontal Sense in horizontal
 * @param vertical Sense in vertical
 */
void Snake::move(double size) {
    size = 2.0 / size;

    for (int index = 1; index < this->size; index++) {
        double x = this->blocks[index - 1].get('x');
        double y = this->blocks[index - 1].get('y');

        this->blocks[index].move(x, y);
    }

    this->blocks[0].move(size * this->horizontal, size * this->vertical);
}

/**
 * @brief Change the snake movement sense
 *
 * @param horizontal Horizontal sense
 * @param vertical Vertical sense
 */
void Snake::sense(int horizontal, int vertical) {
    this->horizontal = horizontal;
    this->vertical = vertical;
}

/**
 * @brief Added one more block to snake
 */
void Snake::shift(void) { this->size = std::min(this->amount, this->size + 1); }

}  // namespace snake
