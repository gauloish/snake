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
    double x, y, z;
    double r, g, b;
};

/**
 * @class Block
 * @brief Emulate a block with vertices
 *
 */
struct Block {
    Vertex vertices[4];

    Block(void);
    Block(double, double, double, double);

    void set(double, double, double, double);
};

}  // namespace geometry

#endif
