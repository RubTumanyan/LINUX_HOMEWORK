#include <iostream>
#include "Sort.h"
#include "Complex.h"
#include <vector>

int main(){
	std::vector<Complex> numbers = {
		Complex(1,0),
		Complex(2,0),
		Complex(3,0),
		Complex(10,0),
		Complex(8,0),
	};

	sortComplex(numbers);
	for (auto& num : numbers){
		std::cout << num;
	}
return 0;
}
