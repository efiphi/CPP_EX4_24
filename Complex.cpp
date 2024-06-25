#include "Complex.hpp"
#include <cmath>

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real * other.real + other.imag * other.imag;
    return Complex((real * other.real + imag * other.imag) / denominator, (imag * other.real - real * other.imag) / denominator);
}

bool Complex::operator<(const Complex& other) const {
    return std::sqrt(real * real + imag * imag) < std::sqrt(other.real * real + other.imag * imag);
}

bool Complex::operator>(const Complex& other) const {
    return other < *this;
}

bool Complex::operator<=(const Complex& other) const {
    return !(other < *this);
}

bool Complex::operator>=(const Complex& other) const {
    return !(*this < other);
}

bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real << " + " << c.imag << "i";
    return os;
}
