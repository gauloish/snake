#include "point.hpp"

#ifndef SNAKE_HPP
#define SNAKE_HPP

namespace snake {
/**
 * @class Block
 * @brief A part of snake, a block of it
 *
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
}  // namespace snake

#endif
