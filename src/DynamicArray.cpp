#include "DynamicArray.h"

#include <iostream>
#include <random>

void DynamicArray::insert(int position, int value) {

	if (position == 0) {
		insertFront(value);
	}

	else if (position == logicalSize) {
		insertBack(value);
	}

	else if (position < 0 or position > logicalSize) {
		throw std::bad_alloc();
	}

	else {
		insertAtPosition(position, value);
	}

}

void DynamicArray::remove(int position) {

}

bool  DynamicArray::search(int value) {
	for (int position{0}; position < logicalSize; ++position) {
		if (data[position] == value)
			return true;
	}

	return false;
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

void DynamicArray::insertFront(int value) {

	if (logicalSize == capacity) {

	}

}
void DynamicArray::insertBack(int value) {
	if (logicalSize == capacity) {
		capacity *= 2;

	}


	data[logicalSize] = value;
	++logicalSize;
}

void DynamicArray::resize(newCapacity) {

	std::unique_ptr<int[]> dataCopy = std::make_unique<int[]>(newCapacity);

	for(int position{0}, position < logicalSize; ++position) {
		dataCopy[position] = data[position]
	}

	delete data[];

	data = dataCopy;


}

void DynamicArray::insertAtPosition(int position, int value) {

}
