#ifndef SQUARE_H
#define SQUARE_H

#include "ShapeTwoD.h"
#include <vector>

class Square : public ShapeTwoD {
protected:
    int vertices[4][2]; // Vertices of the square

public:
    Square(std::string name, bool containsWarpSpace, const int vertices[][2]);

    double computeArea() const override;

    bool isPointInShape(int x, int y) const override;

    bool isPointOnShape(int x, int y) const override;

    std::string toString() const override;

    std::vector<std::pair<int, int>> getVertices() const;
};

#endif // SQUARE_H
