#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "../include/functions.hpp"
#include "../include/geometry.hpp"
#include "../include/settings.hpp"
#include "../include/snake.hpp"

namespace functions {
/**
 * @brief Update the global states of objects and capture events
 *
 * @param window Windows where be running the stuffs
 * @param snake The snake object
 */
void update(GLFWwindow *window, snake::Snake &snake) {
    int keys[4][3] = {
        {GLFW_KEY_LEFT, GLFW_KEY_H, GLFW_KEY_A},   // Left
        {GLFW_KEY_RIGHT, GLFW_KEY_L, GLFW_KEY_D},  // Right
        {GLFW_KEY_DOWN, GLFW_KEY_J, GLFW_KEY_S},   // Down
        {GLFW_KEY_UP, GLFW_KEY_K, GLFW_KEY_W},     // Right
    };

    int senses[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int sense = 0; sense < 4; sense++) {
        for (int key = 0; key < 3; key++) {
            int state = glfwGetKey(window, keys[sense][key]);

            if (state == GLFW_PRESS) {
                snake.sense(senses[sense][0], senses[sense][1]);
            }
        }
    }
}

/**
 * @brief Render the game scene and your all stuffs
 *
 * @param window Window where will be rendered stuffs
 * @param snake The snake object
 */
void render(GLFWwindow *window, snake::Snake &snake) {
    // do something

    glfwSwapBuffers(window);
    glfwPollEvents();
}

/**
 * @brief Run the game
 */
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

    GLenum status = glewInit();

#ifdef GLEW_ERROR_NO_GLX_DISPLAY
    if (status != GLEW_OK && status != GLEW_ERROR_NO_GLX_DISPLAY)
#else
    if (status != GLEW_OK)
#endif
    {
        std::cerr << "Error: " << glewGetErrorString(status) << "\n";

        glfwTerminate();

        return;
    }

    std::cout << "Status: Using OpenGL " << glGetString(GL_VERSION) << "\n";
    std::cout << "Status: Using GLEW   " << glewGetString(GLEW_VERSION) << "\n";
    std::cout << "Status: Using GLFW   " << glfwGetVersionString() << "\n";

    GLuint buffer;
    glGenBuffers(1, &buffer);

    std::cout << "Buffer: " << buffer << "\n";

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
