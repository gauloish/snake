#include <vector>

#ifndef POINT_HPP
#define POINT_HPP

namespace geometry {
/**
 * @class Vertex
 * @brief Emulate a vertex with position and color
 *
 */
struct Vertex {
    double position[3];
    double color[3];

    Vertex(void);
    Vertex(double[3], double[3]);
};

/**
 * @class Polygon
 * @brief A
 *
 */
struct Polygon {
    std::vector<Vertex> vertices;

    Polygon(void);
    Polygon(std::vector<Vertex>);
};
}  // namespace geometry

#endif
