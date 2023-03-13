#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../include/geometry.hpp"

#ifndef RENDER_HPP
#define RENDER_HPP

namespace render {
class Object {
   private:
    geometry::Block square;
    double data[24];

    unsigned int array;
    unsigned int buffer;
    unsigned int vertex;
    unsigned int fragment;
    unsigned int program;

    int state;

   public:
    Object(void);
    Object(double, double, double, double);
    ~Object(void);

    void set(double, double, double, double);
    void configure(void);
    void draw(double, double);
};
}  // namespace render

#endif
