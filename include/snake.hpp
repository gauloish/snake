#define GLEW_STATIC

#include <GL/glew.h>

#include <vector>

#include "render.hpp"

#ifndef SNAKE_HPP
#define SNAKE_HPP

namespace snake {
/**
 * @class Snake
 * @brief A set of blocks forming a snake
 */
class Snake {
   private:
    std::vector<render::Object> body;

    GLuint size{1};
    const GLuint amount;

    GLint horizontal{0};
    GLint vertical{0};

    GLfloat step;

   public:
    Snake(const GLuint);

    void set(GLfloat, GLfloat, GLfloat, GLfloat);
    void set(GLfloat, GLfloat, GLfloat, GLfloat *);
    void draw(void);
    void move(void);
    void sense(GLint, GLint);
    void shift(void);
};
}  // namespace snake

#endif
