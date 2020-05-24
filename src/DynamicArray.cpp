#include "DynamicArray.h"

#include <iostream>
#include <random>

void DynamicArray::insert(int position, int value) {


	if (position == 0)
		insertFront(value);

	else if (position == size)
		insertBack(value);

	else if (position < 0 or position > size)
		throw std::bad_alloc();

	else
		insertAtPosition(position, value);

}

void DynamicArray::remove(int position) {

	if (position < 0 or position >= size or (getSize() == 0)) {
		throw std::bad_alloc();
	}

	for (int i{position}; i < (size -1); ++i) {
		data[i] = data[i + 1];
	}

	size--;
}

bool DynamicArray::search(int value) {

	for (int position{0}; position < size; ++position) {
		if (data[position] == value)
			return true;
	}

	return false;
}

void DynamicArray::print() {

	std::cout <<  std::endl << "Dynamic array elements are: " << std::endl;

	for (int i{0}; i < size; i++) {
		std::cout << data[i] << " ";
	}

	std::cout << std::endl;
}

void DynamicArray::fillWithRandomData(int givenSize, int givenUpperRange){

	const int upperRange = givenUpperRange;

	std::random_device seed;
    std::mt19937 randomGenerator(seed());
	std::uniform_int_distribution<> transform(1, upperRange);

	for (int position{0}; position < givenSize; ++position) {
		insert(position, transform(randomGenerator));
	}
}

void DynamicArray::readFromFile(FileHandler& fileHandler){
	int buffer{};
	int tmpSize{};

	fileHandler.inputFile >> tmpSize;
	int position{};

	while(fileHandler.inputFile >> buffer) {
		insert(position, buffer);
		++position;
	}
}

void DynamicArray::insertFront(int value) {

	if (size == capacity) {
		resize(capacity * 2);
	}

	if (getSize() != 0) {
		for(int position{size-1}; position >= 0; --position) {
			data[position + 1] = data[position];
		}
	}

	data[0] = value;
	++size;
}

void DynamicArray::insertBack(int value) {
	if (size == capacity) {
		resize(capacity * 2);
	}

	data[size] = value;
	++size;
}

void DynamicArray::resize(int newCapacity) {

	std::unique_ptr<int[]> dataCopy = std::make_unique<int[]>(newCapacity);

	for(int position{0}; position < size; ++position) {
		dataCopy[position] = data[position];
	}

	capacity = newCapacity;
	reassign(std::move(dataCopy));
}



void DynamicArray::reassign(std::unique_ptr<int[]> newData) {
	data.reset();
	data = std::move(newData);
}

void DynamicArray::insertAtPosition(int position, int value) {
	if (size == capacity) {
			resize(capacity * 2);
		}

	ror(position);

	data[position] = value;
	++size;

}
void DynamicArray::ror(int position) {

	for (int i{size}; i > position; --i) {
		data[i] = data[i-1];
	}
}

int DynamicArray::getSize() const {
	return size;
}

int DynamicArray::getCapacity() const {
	return capacity;
}

int DynamicArray::getDataAt(int position) const {
	return data[position];
}

void DynamicArray::swapElements(int first, int second) {
	int tmp;
	tmp = data[first];
	data[first] = data[second];
	data[second] = tmp;

}


void DynamicArray::clearStructure() {
	size = 0;
}

int DynamicArray::operator[](int position) {
	return data[position];
}
