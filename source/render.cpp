#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>

#include "../include/render.hpp"

namespace render {
Object::Object(std::vector<double> points) {
    this->length = points.size();

    this->points = new double[this->length];

    for (int index = 0; index < this->length; index++) {
        this->points[index] = points[index];
    }
}

void Object::setup(void) {
    const char *vertexSource = R"glsl(
		#version 330 core

		layout (location = 0) in vec2 initial;
		uniform vec2 position;

		void main()
		{
			gl_Position = vec4(initial, 0.0, 0.1) + vec4(position, 0.0, 1.0);
		}
	)glsl";

    const char *fragmentSource = R"glsl(
		#version 330 core

		uniform vec4 color;
		out vec4 outColor;

		void main()
		{
			outColor = vec4(1.0, 1.0, 1.0, 1.0);
		}
	)glsl";

    // Vertex Shader
    this->vertex = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(this->vertex, 1, &vertexSource, nullptr);
    glCompileShader(this->vertex);
    glGetShaderiv(this->vertex, GL_COMPILE_STATUS, &this->state);

    if (this->state == GL_TRUE) {
        std::cout << "Vertex shader was compiled successfully.\n";
    }

    // Fragment Shader
    this->fragment = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(this->fragment, 1, &fragmentSource, nullptr);
    glCompileShader(this->fragment);
    glGetShaderiv(this->fragment, GL_COMPILE_STATUS, &this->state);

    if (this->state == GL_TRUE) {
        std::cout << "Fragment shader was compiled successfully.\n";
    }

    // Link Shaders
    this->program = glCreateProgram();

    glAttachShader(this->program, this->vertex);
    glAttachShader(this->program, this->fragment);

    glLinkProgram(this->program);
    glUseProgram(this->program);

    this->position = glGetUniformLocation(this->program, "position");
    this->color = glGetUniformLocation(this->program, "color");

    // Vertex Data and Attributes
    glGenVertexArrays(1, &this->array);
    glBindVertexArray(this->array);

    glGenBuffers(1, &this->buffer);
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(this->points), this->points,
                 GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_DOUBLE, GL_FALSE, 2 * sizeof(double),
                          (void *)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Object::draw(void) {
    glUseProgram(program);
    glBindVertexArray(array);
    glDrawArrays(GL_TRIANGLES, 0, int(this->length / 2));
    glBindVertexArray(0);
}

Object::~Object(void) {
    delete[] this->points;

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    glDeleteVertexArrays(1, &vertex);
    glDeleteBuffers(1, &buffer);
    glDeleteProgram(program);
}
}  // namespace render
