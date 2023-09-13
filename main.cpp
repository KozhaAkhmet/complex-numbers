#include "complex_number.hpp"
#include <iostream>

int main() {
    ComplexNumber a(1123,1012);
    ComplexNumber b;
    ComplexNumber c(a);

    b = a;
    std::cout << "b = a  "<< b.getReel() << " " << b.getImg() << std::endl;
    
    b = ComplexNumber(50,30);
    std::cout << "b = ComplexNumber(50,30)  "<<b.getReel() << " " << b.getImg() << std::endl;

    b = c + a;
    std::cout << "b = c + a  "<< b.getReel() << " " << b.getImg() << std::endl;

    bool equal = b == c;
    std::cout << "is b = c equal?  "<< equal << std::endl;
    std::cout << b << std::endl;

    ComplexNumber g(10,-1);
    ComplexNumber h(1,1);
    ComplexNumber result(g*h);
    std::cout << "g*h  " << g*h << std::endl;

    std::cin >> b; 
    std::cout << b << std::endl;

}