#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex{
	private:
		double real;
		double imag;
	public:
		Complex(double r , double i);

		double getReal()const;
		double getImag()const;

		Complex operator+(const Complex& other)const;
		Complex operator-(const Complex& other)const;
		Complex operator*(double scalar)const;
		double abs()const;

                bool operator>(const Complex& other)const;
		
		friend std::ostream& operator<<(std::ostream& os, Complex& o);

};

#endif
