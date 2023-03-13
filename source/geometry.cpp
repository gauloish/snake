#include <algorithm>

#include "../include/geometry.hpp"

namespace geometry {
/**
 * @brief Initialize a vertex values to default values
 */
Vertex::Vertex(void) {
    for (int index = 0; index < 4; index++) {
        this->position[index] = 0.0;
        this->color[index] = 1.0;
    }
}

/**
 * @brief Initialize a vertex with given values
 *
 * @param position Vertex position in space
 * @param color Color position
 */
Vertex::Vertex(double position[4], double color[4]) {
    for (int index = 0; index < 4; index++) {
        this->position[index] = position[index];
        this->color[index] = color[index];
    }
}

/**
 * @brief Set the vertex attribute values
 *
 * @param position Position values
 * @param color Color values
 */
void Vertex::set(double position[4], double color[4]) {
    for (int index = 0; index < 4; index++) {
        this->position[index] = std::max(std::min(position[index], 1.0), -1.0);
        this->color[index] = std::max(std::min(color[index], 1.0), 0.0);
    }
}

}  // namespace geometry
