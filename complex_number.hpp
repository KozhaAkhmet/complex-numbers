#include <string>
#include <sstream>

class ComplexNumber {
    friend bool operator==(const ComplexNumber &lhs, const ComplexNumber &rhs);
    friend ComplexNumber operator+(const ComplexNumber &lhs, const ComplexNumber &rhs);
    friend ComplexNumber operator-(const ComplexNumber &lhs, const ComplexNumber &rhs);
    friend ComplexNumber operator*(const ComplexNumber &lhs, const ComplexNumber &rhs);
    friend std::ostream &operator<<(std::ostream &os, const ComplexNumber &rhs);
    friend std::istream &operator>>(std::istream &in, ComplexNumber &rhs);

   private:
    double reel;
    double img;

   public:
    ComplexNumber(double reel = 0, double img = 0);
    ComplexNumber(const ComplexNumber &source);
    ~ComplexNumber();

    double getReel() const {
        return this->reel;
    }
    double getImg() const {
        return this->img;
    }
    std::string to_string() const;

    ComplexNumber &operator=(const ComplexNumber &rhs);  // Copy assignment
    ComplexNumber &operator=(ComplexNumber &&rhs);       // Move assignment
};
