
#ifndef POINT_HPP
#define POINT_HPP

namespace point {
class Point {
   private:
    double x;
    double y;

   public:
    Point(void);
    Point(double, double);

    void set(double, double);
    double get(char);
};
}  // namespace point

#endif
