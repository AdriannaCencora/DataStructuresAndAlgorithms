#include "DynamicArray.h"

#include <iostream>
#include <random>

void DynamicArray::insert(int position, int value) {

}

void DynamicArray::remove(int position) {

}

int DynamicArray::search(int value) {

}

int DynamicArray::getSize() {

	return logicalSize;
}

void DynamicArray::print() {

	std::cout << "Dynamic array elements are: " << std::endl;

	for (int i{0}; i < logicalSize; i++) {
		std::cout << data[i] << " ";
	}

	std::cout << std::endl;
}

void DynamicArray::fillWithRandomData(){

	const int upperRange = 15500;
	std::random_device seed;
    std::mt19937 randomGenerator(seed());
	std::uniform_int_distribution<> transform(1, upperRange);

	for (int position{0}; position < logicalSize; ++position) {
		data[position] = transform(randomGenerator);
	}
}

void DynamicArray::readFromFile(){

}
