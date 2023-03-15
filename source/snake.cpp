#define GLEW_STATIC

#include <GL/glew.h>

#include <algorithm>
#include <iostream>
#include <vector>

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
 * @brief Set the snake with given position and color
 *
 * @param x Initial horizontal position
 * @param y Initial vertical position
 * @param step Block side size
 * @param color Snake color
 * @param amount Size of snake
 */
void Snake::set(GLfloat x, GLfloat y, GLfloat step, GLfloat color) {
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
void Snake::set(GLfloat x, GLfloat y, GLfloat step, GLfloat *color) {
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
        for (int index = this->size - 1; index > 0; index--) {
            this->body[index] = this->body[index - 1];
        }

        this->x += this->step * this->horizontal;
        this->y += this->step * this->vertical;

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
 * @brief Added one more block to snake
 */
void Snake::shift(void) { this->size = std::min(this->amount, this->size + 1); }
}  // namespace snake
