#define GLEW_STATIC

#include <GL/glew.h>

#ifndef SETTINGS_HPP
#define SETTINGS_HPP

namespace settings {
extern const GLuint unit;
extern const GLuint size;

extern GLint width;
extern GLint height;

extern GLchar title[6];

extern GLfloat back[7][4];
extern GLfloat fore[7][4];
}  // namespace settings

#endif
