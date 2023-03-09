#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// #include "../include/point.hpp"
// #include "../include/settings.hpp"
#include "../include/snake.hpp"

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

namespace functions {
void update(GLFWwindow *, snake::Snake &);
void render(GLFWwindow *, snake::Snake &);
void run(void);
}  // namespace functions

#endif
