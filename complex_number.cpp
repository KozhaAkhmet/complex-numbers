#include "complex_number.hpp"

#include <iostream>
#include <sstream>

ComplexNumber::ComplexNumber(double reel_val, double img_val)
    : reel{reel_val}, img{img_val} {
    std::cout << "Three-args Constructor" << std::endl;
}

ComplexNumber::ComplexNumber(const ComplexNumber &source)
    : ComplexNumber{source.reel, source.reel} {
    std::cout << "Copy Constructor" << std::endl;
}

ComplexNumber::~ComplexNumber() {
    std::cout << "Destructor" << std::endl;
}

ComplexNumber &ComplexNumber::operator=(const ComplexNumber &rhs) {
    std::cout << "Copy Assignment" << std::endl;
    if (this == &rhs)
        return *this;

    this->reel = rhs.reel;
    this->img = rhs.img;

    return *this;
}

ComplexNumber &ComplexNumber::operator=(ComplexNumber &&rhs) {
    std::cout << "Move Assignment" << std::endl;
    if (this == &rhs)
        return *this;

    this->reel = rhs.reel;
    this->img = rhs.img;

    return *this;
}

bool operator==(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    // if(lhs.reel == rhs.reel &&
    //     lhs.img == rhs.img)
    //     return true;
    // return false;
    return lhs.reel == rhs.reel &&
                   lhs.img == rhs.img
               ? true
               : false;
}

ComplexNumber operator+(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    ComplexNumber buff{lhs.reel + rhs.reel,
                       lhs.img + rhs.img};
    return buff;
}

ComplexNumber operator-(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    ComplexNumber buff{lhs.reel - rhs.reel,
                       lhs.img - rhs.img};
    return buff;
}

/*
(a + bi) * (c + di) = 
a*c + a*di + bi*c - b*d =
(a*c - b*d) + (a*d + b*c)i

*/
ComplexNumber operator*(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    ComplexNumber buff{lhs.reel * rhs.reel - lhs.img * rhs.img,
                       lhs.reel * rhs.img + lhs.img * rhs.reel};
    return buff;
}

std::string ComplexNumber::to_string() const{
    std::stringstream buff;
    buff << this->reel << " " << this->img << "i";
    return buff.str();
}

std::ostream &operator<<(std::ostream &os, const ComplexNumber &rhs){
    os << rhs.to_string();
    return os;
}

std::istream &operator>>(std::istream &in, ComplexNumber &rhs){
    ComplexNumber buff;
    in >> buff.reel >> buff.img;
    rhs = ComplexNumber{buff};
    return in;
}
