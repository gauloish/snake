#define GLEW_STATIC

#include <GL/glew.h>

#include <vector>

#include "object.hpp"

#ifndef SNAKE_HPP
#define SNAKE_HPP

namespace snake {
/**
 * @class Snake
 * @brief A set of blocks forming a snake
 */
class Snake {
   private:
    std::vector<object::Object> body;

    GLuint size{1};
    const GLuint amount;

    GLuint counter{0};

    GLint horizontal{0};
    GLint vertical{0};

    GLfloat x;
    GLfloat y;

    GLfloat step;

   public:
    Snake(const GLuint);

    GLfloat get(GLuint, GLchar);
    void set(GLfloat, GLfloat, GLfloat, GLfloat);
    void set(GLfloat, GLfloat, GLfloat, GLfloat *);
    void configure(void);
    void draw(void);
    void move(void);
    void sense(GLint, GLint);
    void shift(void);
};
}  // namespace snake

#endif
