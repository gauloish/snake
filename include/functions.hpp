#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../include/object.hpp"
#include "../include/snake.hpp"

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

namespace functions {
int randomic(int, int);
void init(snake::Snake &, object::Object &, object::Object &);
void update(GLFWwindow *, snake::Snake &, object::Object &);
void render(GLFWwindow *, snake::Snake &, object::Object &, object::Object &);
void reshape(GLFWwindow *);
void centralize(GLFWwindow *);
void run(void);
}  // namespace functions

#endif
