#include "Cross.h"
#include <cmath>

Cross::Cross(std::string name, bool containsWarpSpace, const int vertices[][2])
    : ShapeTwoD(name, containsWarpSpace)
{
    // Initialize the vertices array
    for (int i = 0; i < 12; ++i)
    {
        this->vertices[i][0] = vertices[i][0];
        this->vertices[i][1] = vertices[i][1];
    }
}

double Cross::computeArea() const
{
    // Since the coordinates are going to be entered adjancently
    // Apply the shoelace formula to calculate the area of the polygon formed by the vertices (big brain formula again)
    double area = 0.0;
    for (int i = 0; i < 12; ++i)
    {
        int j = (i + 1) % 12; // Next vertex
        area += (vertices[i][0] * vertices[j][1]) - (vertices[j][0] * vertices[i][1]);
    }
    return std::abs(area) / 2.0; // Absolute value and divide by 2 to get the area
}

// Function to calculate the orientation of three points
// Returns positive if the point q is left of the line segment p1p2
// Returns negative if it's right, and zero if they are collinear
int Cross::isLeft(std::pair<int, int> p1, std::pair<int, int> p2, std::pair<int, int> q) const
{
    return ((p2.first - p1.first) * (q.second - p1.second)) - ((q.first - p1.first) * (p2.second - p1.second));
}

bool Cross::isPointInShape(int x, int y) const
{
    // Compute winding number
    int wn = 0; // Winding number
    std::vector<std::pair<int, int>> vertices = getVertices();

    for (size_t i = 0; i < vertices.size() - 1; i++)
    {
        if (vertices[i].second <= y)
        {
            if (vertices[i + 1].second > y && isLeft(vertices[i], vertices[i + 1], {x, y}) > 0)
            {
                wn++;
            }
        }
        else
        {
            if (vertices[i + 1].second <= y && isLeft(vertices[i], vertices[i + 1], {x, y}) < 0)
            {
                wn--;
            }
        }
    }

    // Handle the case when the polygon is not closed
    if (vertices[vertices.size() - 1].second <= y)
    {
        if (vertices[0].second > y && isLeft(vertices[vertices.size() - 1], vertices[0], {x, y}) > 0)
        {
            wn++;
        }
    }
    else
    {
        if (vertices[0].second <= y && isLeft(vertices[vertices.size() - 1], vertices[0], {x, y}) < 0)
        {
            wn--;
        }
    }

    // Point is inside if winding number is non-zero
    return wn != 0;
}

bool Cross::isPointOnShape(int x, int y) const
{
    // Define function to check if a point (x,y) lies on a line segment (x1,y1)-(x2,y2)
    auto isOnLineSegment = [](int x, int y, int x1, int y1, int x2, int y2)
    {
        return ((x >= std::min(x1, x2) && x <= std::max(x1, x2)) &&
                (y >= std::min(y1, y2) && y <= std::max(y1, y2)) &&
                ((y - y1) * (x2 - x1) == (y2 - y1) * (x - x1)));
    };

    std::vector<std::pair<int, int>> vertices = getVertices();
    // Check if the point is on any of the line segments forming the cross
    for (size_t i = 0; i < vertices.size() - 1; i++)
    {
        if (isOnLineSegment(x, y, vertices[i].first, vertices[i].second, vertices[i + 1].first, vertices[i + 1].second))
            return true;
    }

    // Check the closing segment
    if (isOnLineSegment(x, y, vertices[vertices.size() - 1].first, vertices[vertices.size() - 1].second, vertices[0].first, vertices[0].second))
        return true;

    return false;
}

std::string Cross::toString() const
{
    std::string verticesStr = "Vertices: ";
    for (int i = 0; i < 12; ++i)
    {
        verticesStr += "(" + std::to_string(vertices[i][0]) + "," + std::to_string(vertices[i][1]) + ") ";
    }
    return ShapeTwoD::toString() + ", Type: Cross, " + verticesStr;
}

std::vector<std::pair<int, int>> Cross::getVertices() const
{
    std::vector<std::pair<int, int>> result;
    for (int i = 0; i < 12; ++i)
    {
        result.push_back({vertices[i][0], vertices[i][1]});
    }
    return result;
}
