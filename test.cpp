#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "Cross.h"
#include <iostream>

void testRectangle() {
    // Define vertices for a rectangle
    int vertices[4][2] = {{0, 0}, {0, 5}, {5, 5}, {5, 0}};

    // Create a rectangle object
    Rectangle rectangle("MyRectangle", false, vertices);

    // Test computeArea function
    std::cout << "Area of the rectangle: " << rectangle.computeArea() << std::endl;

    // Test isPointInShape function
    int x, y;
    std::cout << "Enter a point (x y) to check if it's inside the rectangle: ";
    std::cin >> x >> y;
    if (rectangle.isPointInShape(x, y)) {
        std::cout << "The point is inside the rectangle." << std::endl;
    } else {
        std::cout << "The point is not inside the rectangle." << std::endl;
    }

    // Test isPointOnShape function
    std::cout << "Enter a point (x y) to check if it's on the rectangle's boundary: ";
    std::cin >> x >> y;
    if (rectangle.isPointOnShape(x, y)) {
        std::cout << "The point is on the boundary of the rectangle." << std::endl;
    } else {
        std::cout << "The point is not on the boundary of the rectangle." << std::endl;
    }
}



void testSquare() {
    // Define vertices for a square
    int vertices[4][2];
    std::cout << "Enter the coordinates for the 4 vertices of the square:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << "Vertex " << i + 1 << " (x y): ";
        std::cin >> vertices[i][0] >> vertices[i][1];
    }

    // Create a square object
    Square square("MySquare", false, vertices);

    // Test computeArea function
    std::cout << "Area of the square: " << square.computeArea() << std::endl;

    /*
    // Test isPointInShape function
    int x, y;
    std::cout << "Enter a point (x): ";
    std::cin >> x;
    std::cout << "Enter a point (y): ";
    std::cin >> y;
    if (square.isPointInShape(x, y)) {
        std::cout << "The point is inside the square." << std::endl;
    } else {
        std::cout << "The point is not inside the square." << std::endl;
    }

    // Test isPointOnShape function
    std::cout << "Enter a point (x): ";
    std::cin >> x;
    std::cout << "Enter a point (y): ";
    std::cin >> y;
    if (square.isPointOnShape(x, y)) {
        std::cout << "The point is on the boundary of the square." << std::endl;
    } else {
        std::cout << "The point is not on the boundary of the square." << std::endl;
    }
    */
}

void testRectangleArea() {
    int rectangleVertices[4][2];
    std::cout << "Enter the coordinates for the 4 vertices of the rectangle:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << "Vertex " << i + 1 << " (x y): ";
        std::cin >> rectangleVertices[i][0] >> rectangleVertices[i][1];
    }

    Rectangle rectangle("MyRectangle", false, rectangleVertices);


    std::cout << "Rectangle Info: " << rectangle.toString() << std::endl;

    std::cout << "Area :" << rectangle.computeArea() << std::endl;
}

void testSquareArea() {
    int rectangleVertices[4][2];
    std::cout << "Enter the coordinates for the 4 vertices of the rectangle:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << "Vertex " << i + 1 << " (x y): ";
        std::cin >> rectangleVertices[i][0] >> rectangleVertices[i][1];
    }

    Square sq("MyRectangle", false, rectangleVertices);


    std::cout << "Rectangle Info: " << sq.toString() << std::endl;

    std::cout << "Area :" << sq.computeArea() << std::endl;
}


void testCircleToString() {
    int centerX, centerY;
    double radius;

    std::cout << "Enter the center coordinates of the circle (x y): ";
    std::cin >> centerX >> centerY;

    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    Circle circle("MyCircle", true, centerX, centerY, radius);

    std::cout << "Circle Info: " << circle.toString() << std::endl;
}


void testCrossToString() {
    int vertices[12][2];

    std::cout << "Enter the coordinates for the 12 vertices of the cross:" << std::endl;
    for (int i = 0; i < 12; ++i) {
        std::cout << "Vertex " << i + 1 << " (x y): ";
        std::cin >> vertices[i][0] >> vertices[i][1];
    }

    Cross cross("MyCross", false, vertices);

    std::cout << "Cross Info: " << cross.toString() << std::endl;
}

void testCrossArea() {
    int vertices[12][2];

    std::cout << "Enter the coordinates for the 12 vertices of the cross:" << std::endl;
    for (int i = 0; i < 12; ++i) {
        std::cout << "Vertex " << i + 1 << " (x y): ";
        std::cin >> vertices[i][0] >> vertices[i][1];
    }

    Cross cross("MyCross", false, vertices);

    double area = cross.computeArea();

    std::cout << "Cross Area: " << area << std::endl;
}

int main() {
    testCrossArea();
    return 0;
}



