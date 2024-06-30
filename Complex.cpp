#include "Complex.hpp"
#include <sstream>

Complex::Complex(double r, double i) : real(r), imag(i) {}

double Complex::get_real() const {
    return real;
}

double Complex::get_imag() const {
    return imag;
}

std::string Complex::to_string() const {
    std::ostringstream oss;
    oss << real << " + " << imag << "i";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.get_real() << " + " << c.get_imag() << "i";
    return os;
}

bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

bool Complex::operator>(const Complex& other) const {
    return (real > other.real) || (real == other.real && imag > other.imag);
}

bool Complex::operator<(const Complex& other) const {
    return (real < other.real) || (real == other.real && imag < other.imag);
}
