
#ifndef POINT_HPP
#define POINT_HPP

namespace point {
class Point {
   private:
    int x;
    int y;

   public:
    Point(int, int);

    void set(int, int);
    int get(char);
};
}  // namespace point

#endif
