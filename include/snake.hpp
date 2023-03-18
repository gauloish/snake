#include <vector>

#include "glibs.hpp"
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

    GLint x;
    GLint y;

    GLfloat step;
    GLboolean eat;

   public:
    Snake(const GLuint);

    GLint get(GLuint, GLchar);
    void set(GLint, GLint, GLfloat, GLfloat);
    void set(GLint, GLint, GLfloat, GLfloat *);
    void configure(void);
    void draw(void);
    void move(void);
    void sense(GLint, GLint);
    GLint verify(object::Object &);
    GLuint length(void);
    void shift(void);
};
}  // namespace snake

#endif
