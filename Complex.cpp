#include <iostream>
#include "Complex.h"
#include <cmath>

Complex::Complex(double r , double i) : real(r) , imag(i){}

double Complex::getReal()const{
	return real;
}
double getImag()const{
	return imag;
}

Complex Complex::operator+(const Complex& other)const{
	return Complex(other.real + real , other.imag + imag);
}
Complex Complex::operator-(const Complex& other)const{
	return Complex(real - otehr.real , imag - otehr.imag);
}
Complex Complex::operator*(double scalar)const{
	return Complex(scalar*real , scalar * imag);
}
double Complex::abs()const{
	return sqrt(real * real + imag * imag);
}
std::ostream& operator<<(std::ostream& os , Complex& o)const{
	os << o.real << " + " << o.imag << 'i' << std::endl;
	return os;
}
