#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <random>
#include "Cross.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h "

// Convert string to lowercase
void toLower(std::string &str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void inputSensorData(std::list<ShapeTwoD *> &shapes)
{
    std::string name;
    std::string specialType;

    std::cout << "Please enter the name of the shape (Cross, Rectangle, Square, Circle): ";
    std::cin >> name;
    // Convert the input shape name to lowercase
    toLower(name);

    do
    {
        std::cout << "Please enter the special type (NS for no warp space, WS for warp space): ";
        std::cin >> specialType;
        // Convert the special type input to lowercase
        toLower(specialType);
    } while (specialType != "ws" && specialType != "ns");

    // Create a pointer to ShapeTwoD to hold the created shape object
    ShapeTwoD *shape = nullptr;

    // Check if special type indicates warp space
    bool containsWarpSpace = (specialType == "ws") ? true : false;

    if (name == "cross")
    {
        std::cout << "Creating a cross..." << std::endl;

        int vertices[12][2]; // Array to store 12 vertices

        std::cout << "Please enter the 12 vertices coordinates:" << std::endl;
        for (int i = 0; i < 12; ++i)
        {
            std::cout << "Please enter x value for vertex " << i + 1 << ": ";
            std::cin >> vertices[i][0];
            std::cout << "Please enter y value for vertex " << i + 1 << ": ";
            std::cin >> vertices[i][1];
        }

        // Create a Cross object with the entered vertices
        shape = new Cross("Cross", containsWarpSpace, vertices);
    }
    else if (name == "rectangle")
    {
        std::cout << "Creating a rectangle..." << std::endl;

        int vertices[4][2]; // Array to store 4 vertices

        std::cout << "Please enter the 4 vertices coordinates:" << std::endl;
        for (int i = 0; i < 4; ++i)
        {
            std::cout << "Please enter x value for vertex " << i + 1 << ": ";
            std::cin >> vertices[i][0];
            std::cout << "Please enter y value for vertex " << i + 1 << ": ";
            std::cin >> vertices[i][1];
        }

        // Create a Rectangle object with the entered vertices
        shape = new Rectangle("Rectangle", containsWarpSpace, vertices);
    }
    else if (name == "square")
    {
        std::cout << "Creating a square..." << std::endl;

        int vertices[4][2]; // Array to store 4 vertices

        std::cout << "Please enter the 4 vertices coordinates:" << std::endl;
        for (int i = 0; i < 4; ++i)
        {
            std::cout << "Please enter x value for vertex " << i + 1 << ": ";
            std::cin >> vertices[i][0];
            std::cout << "Please enter y value for vertex " << i + 1 << ": ";
            std::cin >> vertices[i][1];
        }

        // Create a Square object with the entered vertices
        shape = new Square("Square", containsWarpSpace, vertices);
    }
    else if (name == "circle")
    {
        std::cout << "Creating a circle..." << std::endl;

        int centerX, centerY;
        double radius;

        std::cout << "Please enter the center coordinates x: ";
        std::cin >> centerX;
        std::cout << "Please enter the center coordinates y: ";
        std::cin >> centerY;
        std::cout << "Please enter the radius: ";
        std::cin >> radius;

        // Create a Circle object with the entered center coordinates and radius
        shape = new Circle("Circle", containsWarpSpace, centerX, centerY, radius);
    }
    else
    {
        std::cout << "Invalid shape name. Please enter 'Cross', 'Rectangle', 'Square', or 'Circle'." << std::endl;
        return;
    }

    // Set the containsWarpSpace property
    shape->setContainsWarpSpace(containsWarpSpace);
    // Store the created shape in the list
    shapes.push_back(shape);

    // Output message indicating all data have been stored
    std::cout << "All data for the shape have been stored." << std::endl;
}

// Function to compute areas for all shapes in the list and store them
void computeAllAreas(std::list<ShapeTwoD *> &shapes)
{
    // Iterate through the list of shapes
    int counter = 0;
    for (auto &shape : shapes)
    {

        double area = shape->computeArea(); // Compute the area for the current shape

        shape->setArea(area); // Set the computed area directly for the current shape
        counter++;
    }

    // Output confirmation message
    std::cout << "Areas computed and set for all shapes. (" << counter << " records updated!)" << std::endl;
}

void printVertices(const ShapeTwoD &shape)
{
    std::cout << "Vertices:" << std::endl;
    auto vertices = shape.getVertices(); // Get vertices of the shape
    for (size_t i = 0; i < vertices.size(); ++i)
    {
        std::cout << "Point [" << i << "] : (" << vertices[i].first << ", " << vertices[i].second << ")" << std::endl;
    }
}

void printPerimeterPoints(const ShapeTwoD *s)
{
    // Get the vertices of the shape
    if (s->getName() == "Circle")
    {
        const Circle *circlePtr = dynamic_cast<const Circle *>(s);
        if (circlePtr)
        {
            int x = circlePtr->getVertices()[0].first;
            int y = circlePtr->getVertices()[0].second;
            double r = const_cast<Circle *>(circlePtr)->getRadius();

            std::cout << "\nPoints on perimeter: ";
            bool isPointOn;

            // Define cardinal directions: North, East, South, West
            int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            for (auto dir : directions)
            {
                int dx = dir[0] * static_cast<int>(r);
                int dy = dir[1] * static_cast<int>(r);
                isPointOn = circlePtr->isPointOnShape(x + dx, y + dy);
                if (isPointOn)
                    std::cout << "(" << x + dx << ',' << y + dy << "), ";
            }

            std::cout << "\b\b" << std::endl
                      << std::endl;

            // Print points inside the circle
            std::cout << "\nPoints inside shape: ";
            int centerX = x;
            int centerY = y;
            for (int px = centerX - r + 1; px < centerX + r; ++px)
            {
                for (int py = centerY - r + 1; py < centerY + r; ++py)
                {
                    // Exclude points on the shape boundary and vertices
                    if (!circlePtr->isPointOnShape(px, py) && circlePtr->isPointInShape(px, py) && !(px == centerX && py == centerY))
                    {
                        std::cout << "(" << px << ',' << py << "), ";
                    }
                }
            }
            std::cout << "\b\b" << std::endl
                      << std::endl;
        }
    }
    else if (s->getName() == "Cross")
    {
        const Cross *cross = dynamic_cast<const Cross *>(s);
        if (!cross)
        {
            std::cout << "Shape is not a Cross.\n";
            return;
        }

        // Get the vertices of the cross
        std::vector<std::pair<int, int>> vertices = cross->getVertices();

        std::cout << "Points on shape boundary:\n";
        for (size_t i = 0; i < vertices.size(); ++i)
        {
            // Avoid printing the vertices themselves
            // Print points between current vertex and next vertex (inclusive)
            int nextIndex = (i + 1) % vertices.size();
            int xDiff = vertices[nextIndex].first - vertices[i].first;
            int yDiff = vertices[nextIndex].second - vertices[i].second;
            int steps = std::max(std::abs(xDiff), std::abs(yDiff));
            for (int step = 1; step < steps; ++step)
            {
                int x = vertices[i].first + (xDiff * step) / steps;
                int y = vertices[i].second + (yDiff * step) / steps;
                if (cross->isPointOnShape(x, y))
                {
                    std::cout << "(" << x << ", " << y << "), ";
                }
            }
        }
        std::cout << std::endl;

        // Generate points inside the shape
        std::cout << "Points inside shape:\n";
        int xMin = vertices[0].first, xMax = vertices[0].first;
        int yMin = vertices[0].second, yMax = vertices[0].second;
        for (const auto &vertex : vertices)
        {
            xMin = std::min(xMin, vertex.first);
            xMax = std::max(xMax, vertex.first);
            yMin = std::min(yMin, vertex.second);
            yMax = std::max(yMax, vertex.second);
        }
        for (int x = xMin + 1; x < xMax; ++x)
        {
            for (int y = yMin + 1; y < yMax; ++y)
            {
                // Avoid points already on the shape boundary
                if (cross->isPointInShape(x, y) && !cross->isPointOnShape(x, y))
                {
                    std::cout << "(" << x << ", " << y << "), ";
                }
            }
        }
        std::cout << std::endl;
    }
    else
    {
        std::vector<std::pair<int, int>> pts = s->getVertices();

        // Find the minimum and maximum x and y coordinates
        int xMin = pts[0].first, xMax = pts[0].first;
        int yMin = pts[0].second, yMax = pts[0].second;
        for (const auto &vertex : pts)
        {
            xMin = std::min(xMin, vertex.first);
            xMax = std::max(xMax, vertex.first);
            yMin = std::min(yMin, vertex.second);
            yMax = std::max(yMax, vertex.second);
        }

        // Print points on the perimeter
        std::cout << "\nPoints on perimeter: ";
        for (int x = xMin + 1; x < xMax; ++x)
        {
            if (s->isPointOnShape(x, yMin))
            {
                std::cout << "(" << x << ',' << yMin << "), ";
            }
            if (s->isPointOnShape(x, yMax))
            {
                std::cout << "(" << x << ',' << yMax << "), ";
            }
        }
        for (int y = yMin + 1; y < yMax; ++y)
        {
            if (s->isPointOnShape(xMin, y))
            {
                std::cout << "(" << xMin << ',' << y << "), ";
            }
            if (s->isPointOnShape(xMax, y))
            {
                std::cout << "(" << xMax << ',' << y << "), ";
            }
        }
        std::cout << "\b\b" << std::endl;
        // Print points inside the shape
        std::cout << "\nPoints inside shape: ";
        for (int x = xMin + 1; x < xMax; ++x)
        {
            for (int y = yMin + 1; y < yMax; ++y)
            {
                if (s->isPointInShape(x, y))
                {
                    std::cout << "(" << x << ',' << y << "), ";
                }
            }
        }
        std::cout << "\b\b" << std::endl
                  << std::endl;
    }
}

// Function to check if a point is a vertex of the cross
bool isVertex(const std::vector<std::pair<int, int>> &vertices, const std::pair<int, int> &point)
{
    for (const auto &vertex : vertices)
    {
        if (vertex == point)
        {
            return true;
        }
    }
    return false;
}

void printShapeReport(const std::list<ShapeTwoD *> &shapes)
{
    std::cout << "Printing information about shape objects:" << std::endl;
    std::cout << shapes.size() << " records available...." << std::endl;
    int counter = 0;

    for (const auto &shape : shapes)
    {
        if (shape)
        { // Check if shape object is not null
            std::cout << std::endl;
            std::cout << "Shape [" << counter << "]" << std::endl;
            std::cout << "Shape Name: " << shape->getName() << std::endl;
            std::string specialTypeString = (shape->getContainsWarpSpace()) ? "WS" : "NS";
            std::cout << "Special Type: " << specialTypeString << std::endl;
            std::cout << "Area: " << shape->getArea() << " units square" << std::endl;
            printVertices(*shape);
            printPerimeterPoints(shape);
            std::cout << "---------------------------------" << std::endl;

            counter++;
            // Add any other relevant information about the shape object
        }
        else
        {
            std::cout << "Encountered a null shape object in the list." << std::endl;
        }
    }
}

// Comparator function for sorting shapes by area (ascending)
bool sortByAreaAscending(const ShapeTwoD *a, const ShapeTwoD *b)
{
    return a->getArea() < b->getArea();
}

// Comparator function for sorting shapes by area (descending)
bool sortByAreaDescending(const ShapeTwoD *a, const ShapeTwoD *b)
{
    return a->getArea() > b->getArea();
}

// Comparator function for sorting shapes by special type and area
bool sortBySpecialTypeAndArea(const ShapeTwoD *a, const ShapeTwoD *b)
{
    // Sort by special type (WS first)
    if (a->getContainsWarpSpace() && !b->getContainsWarpSpace())
        return true;
    if (!a->getContainsWarpSpace() && b->getContainsWarpSpace())
        return false;

    // If both shapes have the same special type, sort by area in descending order
    return a->getArea() > b->getArea();
}

// Function to sort and print shape data based on user's choice
void sortShapeData(std::list<ShapeTwoD *> &shapes, char option)
{
    switch (option)
    {
    case 'a': // Sort by area (ascending)
        std::cout << "Sorting by Area (ascending)" << std::endl;
        shapes.sort(sortByAreaAscending);
        break;
    case 'b': // Sort by area (descending)
        std::cout << "Sorting by Area (descending)" << std::endl;
        shapes.sort(sortByAreaDescending);
        break;
    case 'c': // Sort by special type and area
        std::cout << "Sorting by Special Type" << std::endl;
        shapes.sort(sortBySpecialTypeAndArea);
        break;
    default:
        std::cout << "Invalid option. Please choose a valid option (a, b, c)." << std::endl;
        return;
    }

    // Print sorted shape data
    std::cout << "Printing information about shape objects after sorting:" << std::endl;
    std::cout << shapes.size() << " records available...." << std::endl;
    int counter = 0;
    for (const auto &shape : shapes)
    {
        if (shape)
        { // Check if shape object is not null
            std::cout << std::endl;
            std::cout << "Shape [" << counter << "]" << std::endl;
            std::cout << "Shape Name: " << shape->getName() << std::endl;
            std::string specialTypeString = (shape->getContainsWarpSpace()) ? "WS" : "NS";
            std::cout << "Special Type: " << specialTypeString << std::endl;
            std::cout << "Area: " << shape->getArea() << " units square" << std::endl;
            printVertices(*shape);
            printPerimeterPoints(shape);
            std::cout << "---------------------------------" << std::endl;
            counter++;
        }
        else
        {
            std::cout << "Encountered a null shape object in the list." << std::endl;
        }
    }
}

void userSortShapeData(std::list<ShapeTwoD *> &shapes)
{
    // Prompt user for sorting option
    std::cout << std::endl;
    std::cout << "Choose sorting option:" << std::endl;
    std::cout << "a) Sort by area (ascending)" << std::endl;
    std::cout << "b) Sort by area (descending)" << std::endl;
    std::cout << "c) Sort by special type and area" << std::endl;
    std::cout << "Please enter your choice: ";
    char option;
    std::cin >> option;
    std::cout << std::endl;

    // Convert the option to lowercase
    option = tolower(option);

    // Check if the option is valid
    if (option != 'a' && option != 'b' && option != 'c')
    {
        std::cout << "Invalid option. Please enter a valid option (a, b, c)." << std::endl;
        return;
    }

    // Sort and print shape data based on user's choice
    sortShapeData(shapes, option);
}

//---------------ADDTIONAL FEATURES -------------------------------

// Function to search for shapes by name (case-insensitive)
void searchByName(const std::list<ShapeTwoD *> &shapes, std::string name)
{
    bool found = false;
    // Convert the user input name to lowercase
    toLower(name);
    for (const auto &shape : shapes)
    {
        std::string shapeName = shape->getName();
        // Convert the shape name to lowercase for comparison
        toLower(shapeName);
        if (shapeName == name)
        {
            // Print information about the found shape
            std::cout << std::endl;
            std::cout << "Shape found:" << std::endl;
            std::cout << "Name: " << shape->getName() << std::endl;
            std::string specialTypeString = (shape->getContainsWarpSpace()) ? "WS" : "NS";
            std::cout << "Special Type: " << specialTypeString << std::endl;
            std::cout << "Area: " << shape->getArea() << " units square" << std::endl;
            printVertices(*shape);
            printPerimeterPoints(shape);
            std::cout << "---------------------------------" << std::endl;
            found = true;
            // If you want to stop searching after finding the first match, you can break out of the loop here
            // break;
        }
    }
    if (!found)
    {
        std::cout << "No shape found with the specified name." << std::endl;
    }
}

void showMenu()
{
    std::cout << std::endl;
    std::cout << "Student ID     : 8215510" << std::endl;
    std::cout << "Student Name   : Aung Pyae Soe" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Welcome to Assn2 Program!" << std::endl;
    std::cout << "Menu Options:" << std::endl;
    std::cout << "1) Input sensor data" << std::endl;
    std::cout << "2) Compute area (for all records)" << std::endl;
    std::cout << "3) Print shapes report" << std::endl;
    std::cout << "4) Sort shape data" << std::endl;
    std::cout << "5) Search by shape name" << std::endl;
    std::cout << "0) Exit " << std::endl;
}

int getUserChoice()
{
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

int main()
{
    int choice;
    std::list<ShapeTwoD *> shapes;
    std::string searchName;
    do
    {
        showMenu();
        choice = getUserChoice();

        switch (choice)
        {
        case 1:
            // Code for inputting sensor data
            std::cout << "You chose option 1: Input sensor data" << std::endl;
            inputSensorData(shapes);
            break;
        case 2:
            // Code for computing area
            std::cout << "You chose option 2: Compute area (for all records)" << std::endl;
            computeAllAreas(shapes);
            break;
        case 3:
            // Code for printing shapes report
            std::cout << "You chose option 3: Print shapes report" << std::endl;
            printShapeReport(shapes);
            break;
        case 4:
            // Code for sorting shape data
            std::cout << "You chose option 4: Sort shape data" << std::endl;
            userSortShapeData(shapes);
            break;
        case 5:
            // Code for searching shapes by name
            std::cout << "You chose option 5: Search shapes by name" << std::endl;
            std::cout << "Enter the name of the shape you want to search for: ";
            std::cin >> searchName;
            searchByName(shapes, searchName);
            break;

        case 0:
            // Code for sorting shape data
            std::cout << "Thanks for using the program !! " << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 4." << std::endl;
        }
    } while (choice != 0);

    // Delete any remaining dynamically allocated shape objects
    for (auto &shape : shapes)
    {
        delete shape;
    }

    return 0;
}
