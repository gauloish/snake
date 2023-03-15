#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../include/geometry.hpp"

#ifndef OBJECT_HPP
#define OBJECT_HPP

namespace object {
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

    GLfloat get(GLchar);
    void set(GLfloat, GLfloat);
    void set(GLfloat, GLfloat, GLfloat, GLfloat);
    void set(GLfloat, GLfloat, GLfloat, GLfloat *);
    void configure(void);
    void draw(void);
};
}  // namespace object

#endif
