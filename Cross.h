#ifndef CROSS_H
#define CROSS_H

#include "ShapeTwoD.h"
#include <vector>

class Cross : public ShapeTwoD
{
protected:
    int vertices[12][2]; // Vertices of the cross

public:
    Cross(std::string name, bool containsWarpSpace, const int vertices[][2]);

    double computeArea() const override;
    bool isPointInShape(int x, int y) const override;
    bool isPointOnShape(int x, int y) const override;

    std::string toString() const override;
    std::vector<std::pair<int, int>> getVertices() const;
    int isLeft(std::pair<int, int> p1, std::pair<int, int> p2, std::pair<int, int> q) const;
};

#endif // CROSS_H
