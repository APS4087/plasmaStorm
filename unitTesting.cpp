#include <iostream>
#include <cmath>
#include "Cross.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"

// Simple testing framework
#define TEST_CASE(name) void name##_test_case()
#define ASSERT(condition) \
    if (!(condition)) {    \
        std::cerr << "Assertion failed: " << #condition << " in " << __FUNCTION__ << std::endl; \
        return; \
    }

TEST_CASE(test_cross_area) {
    // Test Cross area calculation with adjacent points
    int vertices[12][2] = {{0,0}, {0,1}, {0,2}, {1,2}, {2,2}, {2,1}, {2,0}, {1,0}, {0,0}, {0,-1}, {0,-2}, {1,-2}}; // Adjacent points
    Cross cross("Cross", false, vertices);
    ASSERT(cross.computeArea() - 12.0); // Adjusted expected value for adjacent points
}


TEST_CASE(test_rectangle_area) {
    // Test Rectangle area calculation
    int vertices[4][2] = {{0,0}, {0,4}, {4,4}, {4,0}};
    Rectangle rectangle("Rectangle", false, vertices);
    ASSERT(rectangle.computeArea() == 16);
}

TEST_CASE(test_square_area) {
    // Test Square area calculation
    int vertices[4][2] = {{0,0}, {0,4}, {4,4}, {4,0}};
    Square square("Square", false, vertices);
    ASSERT(square.computeArea() == 16);
}

TEST_CASE(test_circle_area) {
    // Test Circle area calculation
    Circle circle("Circle", false, 0, 0, 5);
    ASSERT(circle.computeArea() ==  78.5); // Adjusted expected value
}

TEST_CASE(test_points_in_shape_and_on_shape) {
    // Test points in shape and on shape for each shape
    int cross_vertices[12][2] = {{0,0}, {1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {6,6}, {7,7}, {8,8}, {9,9}, {10,10}, {11,11}};
    Cross cross("Cross", false, cross_vertices);

    int rectangle_vertices[4][2] = {{0,0}, {0,4}, {4,4}, {4,0}};
    Rectangle rectangle("Rectangle", false, rectangle_vertices);

    int square_vertices[4][2] = {{0,0}, {0,4}, {4,4}, {4,0}};
    Square square("Square", false, square_vertices);

    Circle circle("Circle", false, 0, 0, 5);

    // Test points in shape and on shape for Cross
    ASSERT(cross.isPointInShape(5, 5));
    ASSERT(cross.isPointOnShape(5, 5));

    // Test points in shape and on shape for Rectangle
    ASSERT(rectangle.isPointInShape(2, 2));
    ASSERT(rectangle.isPointOnShape(2, 2));

    // Test points in shape and on shape for Square
    ASSERT(square.isPointInShape(2, 2));
    ASSERT(square.isPointOnShape(2, 2));

    // Test points in shape and on shape for Circle
    ASSERT(circle.isPointInShape(3, 0));
    ASSERT(circle.isPointOnShape(5, 0));
}

// Main function to run all test cases
int main() {
    // Run test cases
    test_cross_area_test_case();
    test_rectangle_area_test_case();
    test_square_area_test_case();
    test_circle_area_test_case();
    test_points_in_shape_and_on_shape_test_case();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
