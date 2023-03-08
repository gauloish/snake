#include "../include/settings.hpp"

namespace settings {
const unsigned unit = 25;
const unsigned size = unit * unit;

int width = size;
int height = size;

char title[6] = "Snake";

double back_colors[7][4] = {
    {0.96, 0.24, 0.30, 1.0},  // red
    {0.00, 0.81, 0.90, 1.0},  // blue
    {0.92, 0.81, 0.16, 1.0},  // yellow
    {0.18, 0.85, 0.56, 1.0},  // green
    {0.49, 0.08, 0.67, 1.0},  // purple
    {0.96, 0.50, 0.20, 1.0},  // orange
    {1.00, 0.38, 0.48, 1.0}   // pink
};

double food_colors[7][4] = {
    {0.70, 0.08, 0.14, 1.0},  // red
    {0.09, 0.63, 0.69, 1.0},  // blue
    {0.76, 0.65, 0.07, 1.0},  // yellow
    {0.06, 0.72, 0.44, 1.0},  // green
    {0.38, 0.04, 0.52, 1.0},  // purple
    {0.70, 0.32, 0.04, 1.0},  // orange
    {0.69, 0.05, 0.14, 1.0}   // pink
};
}  // namespace settings
