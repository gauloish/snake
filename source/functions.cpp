#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "../include/functions.hpp"
#include "../include/geometry.hpp"
#include "../include/settings.hpp"
#include "../include/snake.hpp"

namespace functions {
void update(GLFWwindow *window, snake::Snake &snake) {
    int state = glfwGetKey(window, GLFW_KEY_ENTER);

    if (state == GLFW_PRESS) {
        std::cout << "space!\n";
    }
}

void render(GLFWwindow *window, snake::Snake &snake) {
    // do something

    glfwSwapBuffers(window);
    glfwPollEvents();
}

void run(void) {
    if (not glfwInit()) {
        std::cerr << "Error: GLFW did not initialized!";

        return;
    }

    GLFWwindow *window = glfwCreateWindow(settings::width, settings::height,
                                          settings::title, nullptr, nullptr);

    if (not window) {
        std::cerr << "Error: GLFW window did not created!";

        glfwTerminate();

        return;
    }

    glfwMakeContextCurrent(window);

    while (not glfwWindowShouldClose(window)) {
        snake::Snake snake = snake::Snake(settings::size);

        while (not glfwWindowShouldClose(window)) {
            update(window, snake);
            render(window, snake);
        }
    }

    glfwTerminate();
}
}  // namespace functions
