#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <random>

#include "../include/functions.hpp"
#include "../include/geometry.hpp"
#include "../include/object.hpp"
#include "../include/settings.hpp"
#include "../include/snake.hpp"

namespace functions {
/**
 * @brief Generate a randum integer number inside a given range
 *
 * @param inferior Smaller value in range
 * @param superior Greater value in range
 * @return Random integer in range
 */
int random(int inferior, int superior) {
    static std::random_device device;
    static std::mt19937 engine(device());

    std::uniform_int_distribution<int> uniform(inferior, superior);

    return uniform(engine);
}

/**
 * @brief Initialize objects in game
 *
 * @param snake Snake
 * @param base Background
 */
void init(snake::Snake &snake, object::Object &base, object::Object &food) {
    int color = random(0, 6);

    glClearColor(settings::fore[color][0], settings::fore[color][1], settings::fore[color][2], 1.0);

    GLfloat snake_x = 2.0 * random(0, settings::unit - 1) / (GLfloat)settings::unit - 1.0;
    GLfloat snake_y = 2.0 * random(0, settings::unit - 1) / (GLfloat)settings::unit - 1.0;

    snake.set(snake_x, snake_y, 2.0 / (GLfloat)settings::unit, 0.9);
    base.set(-1.0, 1.0, 2.0, settings::back[color]);

    while (true) {
        GLfloat food_x = 2.0 * random(0, settings::unit - 1) / (GLfloat)settings::unit - 1.0;
        GLfloat food_y = 2.0 * random(0, settings::unit - 1) / (GLfloat)settings::unit - 1.0;

        if (food_x != snake_x and food_y != snake_y) {
            food.set(food_x, food_y, 2.0 / (GLfloat)settings::unit, settings::fore[color][0]);

            break;
        }
    }

    snake.configure();
    base.configure();
    food.configure();
}

/**
 * @brief Centralize window in screen
 *
 * @param window Game window
 */
void centralize(GLFWwindow *window) {
    GLint width;
    GLint height;

    glfwGetFramebufferSize(window, &width, &height);

    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);

    glfwSetWindowPos(window, (mode->width - width) / 2, (mode->height - height) / 2);
}

/**
 * @brief Update the global states of objects and capture events
 *
 * @param window Windows where be running the stuffs
 * @param snake The snake object
 */
void update(GLFWwindow *window, snake::Snake &snake) {
    GLint keys[4][3] = {
        {GLFW_KEY_LEFT, GLFW_KEY_H, GLFW_KEY_A},   // Left
        {GLFW_KEY_RIGHT, GLFW_KEY_L, GLFW_KEY_D},  // Right
        {GLFW_KEY_DOWN, GLFW_KEY_J, GLFW_KEY_S},   // Down
        {GLFW_KEY_UP, GLFW_KEY_K, GLFW_KEY_W},     // Right
    };

    GLint senses[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int sense = 0; sense < 4; sense++) {
        for (int key = 0; key < 3; key++) {
            GLint state = glfwGetKey(window, keys[sense][key]);

            if (state == GLFW_PRESS) {
                snake.sense(senses[sense][0], senses[sense][1]);
            }
        }
    }

    snake.move();
}

/**
 * @brief Reshape view port in window
 *
 * @param window Game window
 */
void reshape(GLFWwindow *window) {
    GLint width;
    GLint height;

    glfwGetFramebufferSize(window, &width, &height);

    GLfloat position = (width - height) / 2.0;

    if (height < width) {
        glViewport(position, 0, height, height);
    } else {
        glViewport(0, -position, width, width);
    }
}

/**
 * @brief Render the game scene and your all stuffs
 *
 * @param window Window where will be rendered stuffs
 * @param snake The snake object
 */
void render(GLFWwindow *window, snake::Snake &snake, object::Object &base, object::Object &food) {
    glClear(GL_COLOR_BUFFER_BIT);

    base.draw();
    snake.draw();
    food.draw();

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

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow *window = glfwCreateWindow(settings::width, settings::height, settings::title, nullptr, nullptr);

    if (not window) {
        std::cerr << "Error: GLFW window did not created!";

        glfwTerminate();

        return;
    }

    glfwMakeContextCurrent(window);

    GLenum status = glewInit();

#ifdef GLEW_ERROR_NO_GLX_DISPLAY
    GLboolean error = (status != GLEW_OK && status != GLEW_ERROR_NO_GLX_DISPLAY);
#else
    GLboolean error = (status != GLEW_OK);
#endif

    if (error) {
        std::cerr << "Error: " << glewGetErrorString(status) << "\n";

        glfwTerminate();

        return;
    }

    std::cout << "Status: Using OpenGL " << glGetString(GL_VERSION) << "\n";
    std::cout << "Status: Using GLEW   " << glewGetString(GLEW_VERSION) << "\n";
    std::cout << "Status: Using GLFW   " << glfwGetVersionString() << "\n";

    centralize(window);

    while (not glfwWindowShouldClose(window)) {
        snake::Snake snake = snake::Snake(settings::size);

        object::Object base = object::Object();
        object::Object food = object::Object();

        init(snake, base, food);

        while (not glfwWindowShouldClose(window)) {
            reshape(window);
            update(window, snake, food);
            render(window, snake, base, food);
        }
    }

    glfwTerminate();
}
}  // namespace functions
