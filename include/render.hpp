#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../include/geometry.hpp"

#ifndef RENDER_HPP
#define RENDER_HPP

namespace render {
/**
 * @class Object
 * @brief A Object in game, a renderable square
 *
 */
class Object {
   private:
    geometry::Block square;

    double data[24];
    double indices[6];

    unsigned int buffer;
    unsigned int element;
    unsigned int vertex;
    unsigned int fragment;
    unsigned int program;

   public:
    Object(void);
    Object(double, double, double, double);
    ~Object(void);

    void set(double, double, double, double);
    void configure(void);
    void draw(void);
};
}  // namespace render

#endif
