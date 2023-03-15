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

    GLfloat step;
    GLfloat color[3];

    GLfloat data[24];
    GLuint indices[6];

    GLuint array;
    GLuint buffer;
    GLuint element;
    GLuint vertex;
    GLuint fragment;
    GLuint program;

   public:
    Object(void);
    Object(GLfloat, GLfloat, GLfloat, GLfloat);
    Object(GLfloat, GLfloat, GLfloat, GLfloat *);
    ~Object(void);

    void set(GLfloat, GLfloat);
    void set(GLfloat, GLfloat, GLfloat, GLfloat);
    void set(GLfloat, GLfloat, GLfloat, GLfloat *);
    void configure(void);
    void draw(void);
};
}  // namespace render

#endif
