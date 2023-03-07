#include "point.hpp"

#ifndef SNAKE_HPP
#define SNAKE_HPP

namespace snake {
/**
 * @class Block
 * @brief A part of snake, a block of it
 */
class Block {
   private:
    point::Point position;

    double color;

   public:
    Block(void);
    Block(double, double);
    Block(double, double, double);

    void draw(double);
    void move(double, double);
};

/**
 * @class Snake
 * @brief A set of blocks forming a snake
 */
template <const unsigned amount>
class Snake {
   private:
    Block blocks[amount];

   public:
    Snake(void);
    Snake(double, double);
    Snake(double, double, double);

    void draw(double);
    void move(double, double, bool);
};

}  // namespace snake

#endif
