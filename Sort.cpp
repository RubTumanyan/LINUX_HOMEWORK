#include <iostream>
#include "Sort.h"
#include <algorithm>
#include <vector>
#include "Complex.h"
void sortComplex(std::vector<Complex>&  numbers){
	int size = numbers.size();
	for (int i = 0 ; i < size - 1 ; i++) {
		bool end = false;
		for (int j = 0 ; j < size - 1 - i ; j++) {
			if (numbers[j] > numbers[j+1]) {
				std::swap(numbers[j],numbers[j+1]);
				end = true;
			}
		}
		if (!end){
			break;
		}

	}
}
