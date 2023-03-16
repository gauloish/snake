#define GLEW_STATIC

#include <GL/glew.h>

#include "../include/settings.hpp"

namespace settings {
const GLuint unit = 25;
const GLuint size = unit * unit;

GLuint rate = 5;
GLuint state = 0;

GLint width = size;
GLint height = size;

GLchar title[6] = "Snake";

GLfloat back[7][3] = {
    {0.96, 0.24, 0.30},  // red
    {0.00, 0.81, 0.90},  // blue
    {0.92, 0.81, 0.16},  // yellow
    {0.18, 0.85, 0.56},  // green
    {0.49, 0.08, 0.67},  // purple
    {0.96, 0.50, 0.20},  // orange
    {1.00, 0.38, 0.48}   // pink
};

GLfloat fore[7][3] = {
    {0.70, 0.08, 0.14},  // red
    {0.09, 0.63, 0.69},  // blue
    {0.76, 0.65, 0.07},  // yellow
    {0.06, 0.72, 0.44},  // green
    {0.38, 0.04, 0.52},  // purple
    {0.70, 0.32, 0.04},  // orange
    {0.69, 0.05, 0.14}   // pink
};
}  // namespace settings
