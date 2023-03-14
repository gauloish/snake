#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "../include/geometry.hpp"
#include "../include/render.hpp"

namespace render {
/**
 * @brief Initialize object with default values (null values)
 */
Object::Object(void) : Object::Object(0.0, 0.0, 0.0, 0.0) {}

/**
 * @brief Initialize object with given values
 *
 * @param x Horizontal position
 * @param y Vertical position
 * @param step Block side size
 * @param color Object color
 */
Object::Object(double x, double y, double step, double color) {
    this->set(x, y, step, color);
    this->configure();
}

/**
 * @brief Set object values
 *
 * @param x Horizontal position
 * @param y Vertical position
 * @param step Block side size
 * @param color Object color
 */
void Object::set(double x, double y, double step, double color) {
    this->square = geometry::Block(x, y, step, color);

    for (int index = 0; index < 4; index++) {
        this->data[6 * index + 0] = this->square.vertices[index].x;
        this->data[6 * index + 1] = this->square.vertices[index].y;
        this->data[6 * index + 2] = this->square.vertices[index].z;
        this->data[6 * index + 3] = this->square.vertices[index].r;
        this->data[6 * index + 4] = this->square.vertices[index].g;
        this->data[6 * index + 5] = this->square.vertices[index].b;
    }

    this->indices[0] = 0;
    this->indices[1] = 1;
    this->indices[2] = 2;
    this->indices[3] = 2;
    this->indices[4] = 3;
    this->indices[5] = 0;
}

/**
 * @brief Configure object to render
 */
void Object::configure(void) {
    const char *vertexSource = R"glsl(
		#version 330 core

		layout (location = 0) in vec3 position;

		void main()
		{
			gl_Position = vec4(position, 1.0);
		}
	)glsl";

    const char *fragmentSource = R"glsl(
		#version 330 core

		layout (location = 1) in vec3 color;
		out vec4 outColor;

		void main()
		{
			outColor = vec4(color, 1.0);
		}
	)glsl";

    // Vertex Shader
    {
        int status;
        char log[512];

        this->vertex = glCreateShader(GL_VERTEX_SHADER);

        glShaderSource(this->vertex, 1, &vertexSource, nullptr);
        glCompileShader(this->vertex);

        glGetShaderiv(this->vertex, GL_COMPILE_STATUS, &status);

        if (status == GL_FALSE) {
            glGetShaderInfoLog(this->vertex, 512, nullptr, log);

            std::cout << "Error: " << log << std::endl;
        }
    }

    // Fragment Shader
    {
        int status;
        char log[512];

        this->fragment = glCreateShader(GL_FRAGMENT_SHADER);

        glShaderSource(this->fragment, 1, &fragmentSource, nullptr);
        glCompileShader(this->fragment);

        glGetShaderiv(this->fragment, GL_COMPILE_STATUS, &status);

        if (status == GL_FALSE) {
            glGetShaderInfoLog(this->fragment, 512, nullptr, log);

            std::cout << "Error: " << log << std::endl;
        }
    }

    // Link Shaders
    {
        int status;
        char log[512];

        this->program = glCreateProgram();

        glAttachShader(this->program, this->vertex);
        glAttachShader(this->program, this->fragment);

        glLinkProgram(this->program);
        glUseProgram(this->program);

        glGetProgramiv(this->program, GL_LINK_STATUS, &status);

        if (status == GL_FALSE) {
            glGetProgramInfoLog(this->program, 512, NULL, log);

            std::cout << "Error: " << log << std::endl;
        }
    }

    // Vertex Data and Attributes
    glGenBuffers(1, &this->buffer);
    glGenBuffers(1, &this->element);
}

/**
 * @brief Draw object in screen
 */
void Object::draw(void) {
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(this->data), this->data,
                 GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->element);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->indices), this->indices,
                 GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 6 * sizeof(double),
                          (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_DOUBLE, GL_FALSE, 6 * sizeof(double),
                          (void *)3);
    glEnableVertexAttribArray(1);

    glUseProgram(this->program);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

/**
 * @brief Delete shaders, buffers and programs in object
 */
Object::~Object(void) {
    glDeleteShader(vertex);
    glDeleteShader(fragment);

    glDeleteBuffers(1, &buffer);
    glDeleteBuffers(1, &element);
    glDeleteProgram(program);
}
}  // namespace render
