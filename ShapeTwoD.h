#ifndef SHAPETWOD_H
#define SHAPETWOD_H

#include <string>
#include <vector>

class ShapeTwoD
{
protected:
    std::string name;
    bool containsWarpSpace;
    std::string warpSpace;
    double area;

public:
    ShapeTwoD(std::string name, bool containsWarpSpace);

    std::string getName() const;

    bool getContainsWarpSpace() const;

    double getArea() const; // Getter method for area

    void setArea(double area); // Setter method for area

    virtual double computeArea() const = 0;

    virtual bool isPointInShape(int x, int y) const = 0;

    virtual bool isPointOnShape(int x, int y) const = 0;

    void setName(std::string name);

    void setContainsWarpSpace(bool containsWarpSpace);

    virtual std::string toString() const;

    virtual std::vector<std::pair<int, int>> getVertices() const = 0; // Virtual function to get vertices

    virtual ~ShapeTwoD();
};

#endif // SHAPETWOD_H
