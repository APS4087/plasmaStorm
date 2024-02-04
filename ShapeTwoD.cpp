#include "ShapeTwoD.h"

ShapeTwoD::ShapeTwoD(std::string name, bool containsWarpSpace) : name(name), containsWarpSpace(containsWarpSpace) {}

std::string ShapeTwoD::getName() const
{
    return name;
}

bool ShapeTwoD::getContainsWarpSpace() const
{
    return containsWarpSpace;
}

void ShapeTwoD::setName(std::string name)
{
    this->name = name;
}

void ShapeTwoD::setContainsWarpSpace(bool containsWarpSpace)
{
    this->containsWarpSpace = containsWarpSpace;
}

std::string ShapeTwoD::toString() const
{
    return "Name: " + name + ", Contains Warp Space: " + (containsWarpSpace ? "Yes" : "No");
}

void ShapeTwoD::setArea(double area)
{
    this->area = area;
}

double ShapeTwoD::getArea() const
{
    return area;
}

ShapeTwoD::~ShapeTwoD()
{
    // delete area; // delete dynamic location of area
}
