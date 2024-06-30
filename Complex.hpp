//efiphi10@gmail.com
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <string>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0);

    double get_real() const;
    double get_imag() const;

    std::string to_string() const;

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    bool operator>(const Complex& other) const;
    bool operator<(const Complex& other) const;
};

#endif // COMPLEX_HPP
