#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ShapeTwoD.h"
#include <vector>
#include <string>

class Rectangle : public ShapeTwoD
{
protected:
    int vertices[4][2]; // for rectangle
    std::string warpSpace;

public:
    Rectangle(std::string name, bool containsWarpSpace, const int vertices[][2]);

    double computeArea() const override;

    bool isPointInShape(int x, int y) const override;

    bool isPointOnShape(int x, int y) const override;

    std::string toString() const override;

    std::vector<std::pair<int, int>> getVertices() const;
};

#endif // RECTANGLE_H
