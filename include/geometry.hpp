#define GLEW_STATIC

#include <GL/glew.h>

#include <vector>

#ifndef POINT_HPP
#define POINT_HPP

namespace geometry {
/**
 * @class Vertex
 * @brief Emulate a vertex
 *
 */
struct Vertex {
    GLfloat x, y, z;
    GLfloat r, g, b;
};

/**
 * @class Block
 * @brief Emulate a block with vertices
 *
 */
struct Block {
    Vertex vertices[4];

    Block(void);
    Block(GLfloat, GLfloat, GLfloat, GLfloat);
    Block(GLfloat, GLfloat, GLfloat, GLfloat *);

    void set(GLfloat, GLfloat, GLfloat, GLfloat);
    void set(GLfloat, GLfloat, GLfloat, GLfloat *);
};
}  // namespace geometry

#endif
