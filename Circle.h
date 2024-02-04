#ifndef CIRCLE_H
#define CIRCLE_H

#include "ShapeTwoD.h"
#include <vector>

class Circle : public ShapeTwoD
{
protected:
    int centerX;
    int centerY;
    int radius;

public:
    Circle(std::string name, bool containsWarpSpace, int centerX, int centerY, int radius);

    double computeArea() const override;
    bool isPointInShape(int x, int y) const override;
    bool isPointOnShape(int x, int y) const override;

    std::string toString() const override;
    std::vector<std::pair<int, int>> getVertices() const;
    int getRadius();
};

#endif // CIRCLE_H
