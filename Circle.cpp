#include "Circle.h"
#include <cmath>

Circle::Circle(std::string name, bool containsWarpSpace, int centerX, int centerY, int radius)
    : ShapeTwoD(name, containsWarpSpace), centerX(centerX), centerY(centerY), radius(radius) {}

double Circle::computeArea() const
{
    return 3.14 * radius * radius; // Using the value of pi from the cmath library
}

bool Circle::isPointInShape(int x, int y) const
{
    // Calculate the distance between the given point and the center of the circle
    double distance = sqrt(pow(x - centerX, 2) + pow(y - centerY, 2));
    // Check if the distance is less than or equal to the radius
    return distance <= radius;
}

bool Circle::isPointOnShape(int x, int y) const
{
    // Calculate the distance between the given point and the center of the circle
    double distance = sqrt(pow(x - centerX, 2) + pow(y - centerY, 2));
    // Check if the distance is approximately equal to the radius
    return abs(distance - radius) < 0.001; // Using a small threshold for floating-point comparison
}

int Circle::getRadius()
{
    return radius;
}

std::string Circle::toString() const
{
    return ShapeTwoD::toString() + ", Type: Circle, Center: (" + std::to_string(centerX) + "," + std::to_string(centerY) + "), Radius: " + std::to_string(radius);
}

std::vector<std::pair<int, int>> Circle::getVertices() const
{
    // For a circle, return the center coordinate as a single vertex
    return {{centerX, centerY}};
}