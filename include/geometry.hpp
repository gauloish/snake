#ifndef POINT_HPP
#define POINT_HPP

namespace geometry {
/**
 * @class Point
 * @brief Emulate Points in Plane
 *
 */
class Point {
   private:
    double x;
    double y;

   public:
    Point(void);
    Point(double, double);

    double get(char);
    void set(double, double);
};
/**
 * @class Block
 * @brief A part of snake, a block of it
 */
class Block {
   private:
    Point position;

    double color;

   public:
    Block(void);
    Block(double, double);
    Block(double, double, double);

    double get(char);
    void set(double, double);
    void draw(double);
    void move(double, double);
};

}  // namespace geometry

#endif
