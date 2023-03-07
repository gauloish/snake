
#ifndef POINT_HPP
#define POINT_HPP

class Point {
   private:
    int x;
    int y;

   public:
    Point(int x, int y);

    void set(int x, int y);
    int get(char value);
};

#endif
