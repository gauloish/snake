#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>

#ifndef RENDER_HPP
#define RENDER_HPP

namespace render {
class Object {
   private:
    double *points;

    unsigned int array;
    unsigned int buffer;
    unsigned int vertex;
    unsigned int fragment;
    unsigned int program;

    int state;
    int length;
    int position;
    int color;

   public:
    Object(std::vector<double>);
    ~Object(void);

    void setup(void);
    void draw(void);
};
}  // namespace render

#endif
