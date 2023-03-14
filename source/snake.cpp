#include <algorithm>
#include <vector>

#include "../include/render.hpp"
#include "../include/snake.hpp"

namespace snake {
/**
 * @brief Initalize snake with default position and color
 *
 * @param amount Size of snake
 */
Snake::Snake(const unsigned amount) : amount(amount) {
    this->body = std::vector<render::Object>(this->amount);

    for (int index = 0; index < this->amount; index++) {
        this->body[index] = render::Object();
    }
}

/**
 * @brief Initialize the snake with given position and default color
 *
 * @param x Initial horizontal position
 * @param y Initial vertical position
 * @param amount Size of snake
 */
Snake::Snake(double x, double y, double step, double color, const unsigned amount) : amount(amount) {
    this->body = std::vector<render::Object>(this->amount);

    for (int index = 0; index < amount; index++) {
        this->body[index] = render::Object(x, y, step, color);
    }
}

/**
 * @brief Draw the snake
 *
 * @param size Size of side block
 */
void Snake::draw(void) {
    for (int index = 0; index < this->size; index++) {
        this->body[index].draw();
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
    double step = 2.0 / size;

    for (int index = 1; index < this->size; index++) {
        this->body[index] = this->body[index - 1];
    }

    this->body[0].set(step * this->horizontal, step * this->vertical);
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
