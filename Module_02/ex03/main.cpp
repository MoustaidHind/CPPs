#include "Point.hpp"

// Prototype for the function (if not already in a header like bsp.hpp)
bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
    // 1. Define the Triangle
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    std::cout << "--- BSP Test ---" << std::endl;
    std::cout << "Triangle: A(0,0), B(10,0), C(0,10)" << std::endl;

    // 2. Test Case: STRICTLY INSIDE
    // Point (1, 1) is near the corner A, definitely inside.
    Point p1(1.0f, 1.0f);
    std::cout << "Point (1, 1) [Inside] : " << (bsp(a, b, c, p1) ? "True" : "False") << std::endl;

    // 3. Test Case: STRICTLY OUTSIDE
    // Point (10, 10) is far to the top-right.
    Point p2(10.0f, 10.0f);
    std::cout << "Point (10, 10) [Outside] : " << (bsp(a, b, c, p2) ? "True" : "False") << std::endl;

    // 4. Test Case: ON THE EDGE (Should be FALSE)
    // Point (5, 0) sits exactly on the line AB.
    Point p3(5.0f, 0.0f);
    std::cout << "Point (5, 0) [On Edge] : " << (bsp(a, b, c, p3) ? "True" : "False") << std::endl;

    // 5. Test Case: VERTEX (Should be FALSE)
    // Point (0, 0) is exactly point A.
    Point p4(0.0f, 0.0f);
    std::cout << "Point (0, 0) [Vertex] : " << (bsp(a, b, c, p4) ? "True" : "False") << std::endl;

    return 0;
}