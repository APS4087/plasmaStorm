// In Rectangle.cpp

#include "Rectangle.h"
#include <stdexcept>

Rectangle::Rectangle(std::string name, bool containsWarpSpace, const int vertices[][2])
    : ShapeTwoD(name, containsWarpSpace)
{
    // Initialize the vertices array
    for (int i = 0; i < 4; ++i)
    {
        this->vertices[i][0] = vertices[i][0];
        this->vertices[i][1] = vertices[i][1];
    }
}

double Rectangle::computeArea() const
{
    // Find the maximum and minimum x and y coordinates
    int minX = vertices[0][0], maxX = vertices[0][0];
    int minY = vertices[0][1], maxY = vertices[0][1];
    for (int i = 1; i < 4; ++i)
    {
        minX = std::min(minX, vertices[i][0]);
        maxX = std::max(maxX, vertices[i][0]);
        minY = std::min(minY, vertices[i][1]);
        maxY = std::max(maxY, vertices[i][1]);
    }

    // Calculate the width and height of the rectangle
    int width = maxX - minX;
    int height = maxY - minY;

    // Calculate and return the area
    return static_cast<double>(width) * height;
}

bool Rectangle::isPointInShape(int x, int y) const
{
    // Get the vertices of the rectangle
    std::vector<std::pair<int, int>> vertices = getVertices();

    // Find the minimum and maximum x and y coordinates of the rectangle
    int xMin = vertices[0].first, xMax = vertices[0].first;
    int yMin = vertices[0].second, yMax = vertices[0].second;
    for (const auto &vertex : vertices)
    {
        xMin = std::min(xMin, vertex.first);
        xMax = std::max(xMax, vertex.first);
        yMin = std::min(yMin, vertex.second);
        yMax = std::max(yMax, vertex.second);
    }

    // Check if the point lies within the rectangle's boundaries
    return (x >= xMin && x <= xMax && y >= yMin && y <= yMax);
}

bool Rectangle::isPointOnShape(int x, int y) const
{
    // Check if the point lies on any of the sides of the rectangle
    auto vertices = this->getVertices();

    // Find the minimum and maximum x and y coordinates
    int minX = vertices[0].first;
    int maxX = vertices[0].first;
    int minY = vertices[0].second;
    int maxY = vertices[0].second;
    for (size_t i = 1; i < vertices.size(); ++i)
    {
        minX = std::min(minX, vertices[i].first);
        maxX = std::max(maxX, vertices[i].first);
        minY = std::min(minY, vertices[i].second);
        maxY = std::max(maxY, vertices[i].second);
    }

    // Check if the point lies on the boundary of the rectangle
    return (x == minX || x == maxX) && (y >= minY && y <= maxY) ||
           (y == minY || y == maxY) && (x >= minX && x <= maxX);
}

std::string Rectangle::toString() const
{
    std::string verticesStr = "Vertices: ";
    for (int i = 0; i < 4; ++i)
    {
        verticesStr += "(" + std::to_string(vertices[i][0]) + "," + std::to_string(vertices[i][1]) + ") ";
    }
    return ShapeTwoD::toString() + ", Type: Rectangle, " + verticesStr;
}

std::vector<std::pair<int, int>> Rectangle::getVertices() const
{
    std::vector<std::pair<int, int>> result;
    for (int i = 0; i < 4; ++i)
    {
        result.push_back({vertices[i][0], vertices[i][1]});
    }
    return result;
}