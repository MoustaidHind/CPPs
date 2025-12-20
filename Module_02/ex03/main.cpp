#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    std::cout << "Triangle: A(0,0), B(10,0), C(0,10)" << std::endl;

    // INSIDE
    Point p1(1, 1);
    std::cout << "Point (1, 1) [Inside] : " << (bsp(a, b, c, p1) ? "True" : "False") << std::endl;

    // OUTSIDE
    Point p2(10, 10);
    std::cout << "Point (10, 10) [Outside] : " << (bsp(a, b, c, p2) ? "True" : "False") << std::endl;

    // ON THE EDGE
    Point p3(5, 0);
    std::cout << "Point (5, 0) [On Edge] : " << (bsp(a, b, c, p3) ? "True" : "False") << std::endl;

    // VERTEX
    Point p4(0, 0);
    std::cout << "Point (0, 0) [Vertex] : " << (bsp(a, b, c, p4) ? "True" : "False") << std::endl;

    return 0;
}