#include <iostream>
#include "Sort.h"
#include <algorithm>
#include <vector>

void sortComplex(std::vector<Complex>&  numbers){
	for (int i = 0 ; i < numbers.size() ; i++) {
		bool end = false;
		for (int j = 0 ; j < numbers.size - 1 - i ; j++) {
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
