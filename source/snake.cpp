#include <algorithm>
#include <iostream>
#include <vector>

#include "../include/glibs.hpp"
#include "../include/object.hpp"
#include "../include/settings.hpp"
#include "../include/snake.hpp"

namespace snake {
/**
 * @brief Initalize snake with default position and color
 *
 * @param amount Size of snake
 */
Snake::Snake(const GLuint amount) : amount(amount) {}

/**
 * @brief Get snake body attributes
 *
 * @param index Index block snake
 * @param letter Value
 * @return Block snake attribute
 */
GLint Snake::get(GLuint index, GLchar letter) {
    if (index < this->size) {
        return this->body[index].get(letter);
    }

    std::cerr << "Index out of range in ´Snake::get(GLuint, GLchar)´!\n";

    return 0;
}

/**
 * @brief Set the snake with given position and color
 *
 * @param x Initial horizontal position
 * @param y Initial vertical position
 * @param step Block side size
 * @param color Snake color
 * @param amount Size of snake
 */
void Snake::set(GLint x, GLint y, GLfloat step, GLfloat color) {
    this->step = step;

    this->body = std::vector<object::Object>(this->amount);

    for (int index = 0; index < this->amount; index++) {
        this->body[index].set(x, y, step, color);
    }

    this->x = x;
    this->y = y;
}

/* @brief Set the snake with given position and color
 *
 * @param x Initial horizontal position
 * @param y Initial vertical position
 * @param step Block side size
 * @param color Snake color
 * @param amount Size of snake
 */
void Snake::set(GLint x, GLint y, GLfloat step, GLfloat *color) {
    this->step = step;

    this->body = std::vector<object::Object>(this->amount);

    for (int index = 0; index < this->amount; index++) {
        this->body[index].set(x, y, step, color);
    }

    this->x = x;
    this->y = y;
}

/**
 * @brief Configure snake to render
 */
void Snake::configure(void) {
    for (int index = 0; index < this->amount; index++) {
        this->body[index].configure();
    }
}

/**
 * @brief Draw the snake
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
void Snake::move(void) {
    if (this->counter == 0) {
        if (this->eat) {
            this->eat = false;

            this->shift();
        }

        for (int index = this->size - 1; index > 0; index--) {
            this->body[index] = this->body[index - 1];
        }

        this->x += this->horizontal;
        this->y += this->vertical;

        this->body[0].set(this->x, this->y);
    }

    this->counter = (this->counter + 1) % settings::rate;
}

/**
 * @brief Change the snake movement sense
 *
 * @param horizontal Horizontal sense
 * @param vertical Vertical sense
 */
void Snake::sense(GLint horizontal, GLint vertical) {
    this->horizontal = horizontal;
    this->vertical = vertical;
}

/**
 * @brief Verify collisions and eat food
 *
 * @param food Food object
 * @return State of snake
 */
int Snake::verify(object::Object &food) {
    if (this->size == settings::size) {
        return 3;
    }
    if (this->x < 1 or this->x > settings::unit) {
        return 2;
    }
    if (this->y < 1 or this->y > settings::unit) {
        return 2;
    }

    for (int index = 1; index < this->size; index++) {
        int body_x = this->body[index].get('x');
        int body_y = this->body[index].get('y');

        if (this->x == body_x and this->y == body_y) {
            return 2;
        }
    }

    if (this->x == food.get('x') and this->y == food.get('y')) {
        this->eat = true;
        return 1;
    }

    return 0;
}

/**
 * @brief Snake length
 *
 * @return Snake length
 */
GLuint Snake::length(void) { return this->size; }

/**
 * @brief Added one more block to snake
 */
void Snake::shift(void) { this->size = std::min(this->amount, this->size + 1); }
}  // namespace snake
