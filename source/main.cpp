#include <GLFW/glfw3.h>

#include <cstdlib>
#include <iostream>

int main() {
    if (not glfwInit()) {
        std::cout << "an error has been ocurried!";

        std::exit(EXIT_FAILURE);

        return 0;
    }

    GLFWwindow *window;

    window = glfwCreateWindow(640, 480, "Simple example", nullptr, nullptr);

    if (not window) {
        std::cout << "an error has been ocurried!";

        glfwTerminate();

        std::exit(EXIT_FAILURE);
    }

    std::cout << "ended!";

    glfwTerminate();
}
