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
Object::Object(GLfloat x, GLfloat y, GLfloat step, GLfloat color) {
    this->set(x, y, step, color);
    this->configure();
}

/**
 * @brief Initialize object with given values
 *
 * @param x Horizontal position
 * @param y Vertical position
 * @param step Block side size
 * @param color Object color array
 */
Object::Object(GLfloat x, GLfloat y, GLfloat step, GLfloat *color) {
    this->set(x, y, step, color);
    this->configure();
}

/**
 * @brief Set object values
 *
 * @param x Horizontal position
 * @param y Vertical position
 */
void Object::set(GLfloat x, GLfloat y) { this->set(x, y, this->step, this->color); }

/**
 * @brief Set object values
 *
 * @param x Horizontal position
 * @param y Vertical position
 * @param step Block side size
 * @param color Object color
 */
void Object::set(GLfloat x, GLfloat y, GLfloat step, GLfloat color) {
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

    this->step = step;

    this->color[0] = color;
    this->color[1] = color;
    this->color[2] = color;
}

/**
 * @brief Set object values
 *
 * @param x Horizontal position
 * @param y Vertical position
 * @param step Block side size
 * @param color Object color array
 */
void Object::set(GLfloat x, GLfloat y, GLfloat step, GLfloat *color) {
    this->square = geometry::Block(x, y, step, color);

    for (int index = 0; index < 4; index++) {
        this->data[6 * index + 0] = this->square.vertices[index].x;
        this->data[6 * index + 1] = this->square.vertices[index].y;
        this->data[6 * index + 2] = this->square.vertices[index].z;
        this->data[6 * index + 3] = this->square.vertices[index].r;
        this->data[6 * index + 4] = this->square.vertices[index].g;
        this->data[6 * index + 5] = this->square.vertices[index].b;
    }

    for (int index = 0; index < 24; index++) {
        std::cout << this->data[index] << " ";
    }

    std::cout << "\n";

    this->indices[0] = 0;
    this->indices[1] = 1;
    this->indices[2] = 2;
    this->indices[3] = 2;
    this->indices[4] = 3;
    this->indices[5] = 0;

    this->step = step;

    this->color[0] = color[0];
    this->color[1] = color[1];
    this->color[2] = color[2];
}

/**
 * @brief Configure object to render
 */
void Object::configure(void) {
    const char *vertexSource = R"glsl(
		#version 150 core

		in vec3 position;
		in vec3 color;

		out vec4 middleColor;

		void main()
		{
			gl_Position = vec4(position, 1.0);
			middleColor = vec4(color, 1.0);
		}
	)glsl";

    const char *fragmentSource = R"glsl(
		#version 150 core

		in vec4 middleColor;
		out vec4 outColor;

		void main()
		{
			outColor = middleColor;
		}
	)glsl";

    // Vertex Shader
    {
        GLint status;
        GLchar log[512];

        this->vertex = glCreateShader(GL_VERTEX_SHADER);

        glShaderSource(this->vertex, 1, &vertexSource, nullptr);
        glCompileShader(this->vertex);

        glGetShaderiv(this->vertex, GL_COMPILE_STATUS, &status);

        if (status == GL_FALSE) {
            glGetShaderInfoLog(this->vertex, 512, nullptr, log);

            std::cout << log << std::endl;
        }
    }

    // Fragment Shader
    {
        GLint status;
        GLchar log[512];

        this->fragment = glCreateShader(GL_FRAGMENT_SHADER);

        glShaderSource(this->fragment, 1, &fragmentSource, nullptr);
        glCompileShader(this->fragment);

        glGetShaderiv(this->fragment, GL_COMPILE_STATUS, &status);

        if (status == GL_FALSE) {
            glGetShaderInfoLog(this->fragment, 512, nullptr, log);

            std::cout << log << std::endl;
        }
    }

    // Link Shaders
    {
        GLint status;
        GLchar log[512];

        this->program = glCreateProgram();

        glAttachShader(this->program, this->vertex);
        glAttachShader(this->program, this->fragment);

        glLinkProgram(this->program);
        glUseProgram(this->program);

        glGetProgramiv(this->program, GL_LINK_STATUS, &status);

        if (status == GL_FALSE) {
            glGetProgramInfoLog(this->program, 512, NULL, log);

            std::cout << log << std::endl;
        }
    }

    // Vertex Data and Attributes
    glGenVertexArrays(1, &this->array);
    glBindVertexArray(this->array);

    glGenBuffers(1, &this->buffer);

    glBindBuffer(GL_ARRAY_BUFFER, this->buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(this->data), this->data, GL_STATIC_DRAW);

    glGenBuffers(1, &this->element);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->element);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->indices), this->indices, GL_STATIC_DRAW);

    GLint position = glGetAttribLocation(this->program, "position");
    glEnableVertexAttribArray(position);
    glVertexAttribPointer(position, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void *)(0 * sizeof(GLfloat)));

    GLint color = glGetAttribLocation(this->program, "color");
    glEnableVertexAttribArray(color);
    glVertexAttribPointer(color, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void *)(3 * sizeof(GLfloat)));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

/**
 * @brief Draw object in screen
 */
void Object::draw(void) {
    glUseProgram(program);
    glBindVertexArray(array);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
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
