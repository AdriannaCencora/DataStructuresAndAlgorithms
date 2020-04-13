#include "Heap.h"

#include <random>

void Heap::insert(int position, int value) {
//TODO: set default value to position
	if (position != heapArray->getSize())
		position = heapArray->getSize();

	heapArray->insert(position, value);

	//TODO: Extract to function
	int currentNode = heapArray->getSize() - 1;
	int parent = (currentNode - 1) / 2;

	while (currentNode != 0 and (*heapArray)[currentNode] > (*heapArray)[parent]) {
		heapArray->swapElements(currentNode, parent);
		currentNode = parent;
		parent = (currentNode - 1) / 2;
	}

	++size;
}


void Heap::remove(int value) {

	int indexFound;

	for (int i{0}; i < heapArray->getSize(); i++) {

		if((*heapArray)[i] == value ) {
			indexFound = i;
			break;
		}
	}

	heapArray->swapElements(indexFound, heapArray->getSize() -1);
	heapArray->remove(heapArray->getSize() -1);

	//TODO: Extract to function

	 int parentIndex = indexFound;
	 int leftChildIndex = 2 * indexFound + 1;
	 int rightChildIndex = 2 * indexFound + 1;
	 int swapChildIndex;

	 while (leftChildIndex < heapArray->getSize()  or rightChildIndex < heapArray->getSize()) {

	     leftChildIndex = 2 * parentIndex + 1;
	     rightChildIndex = 2 * parentIndex + 2;

	     swapChildIndex = ((*heapArray)[leftChildIndex] > (*heapArray)[rightChildIndex]) ? leftChildIndex : rightChildIndex;

	     std::cout << leftChildIndex << "|" << rightChildIndex << "|" << swapChildIndex << std::endl;

	     if ((*heapArray)[swapChildIndex] > (*heapArray)[parentIndex]) {

	         heapArray->swapElements(parentIndex, swapChildIndex);
	         parentIndex = swapChildIndex;
	     }
	}

	--size;

}

bool Heap::search(int value) {

	if (value > (*heapArray)[0])
		return false;

	return heapArray->search(value);
}

void Heap::print() {

	printTree(std::string(""), std::string(""), 0);

	heapArray->print();
}

int Heap::getSize() const {

	return size;
}


void Heap::fillWithRandomData(int givenSize, int givenUpperRange) {
	const int upperRange = givenUpperRange;

	std::random_device seed;
    std::mt19937 randomGenerator(seed());
	std::uniform_int_distribution<> transform(1, upperRange);

	for (int position{0}; position < givenSize; ++position) {
		insert(position, transform(randomGenerator));
	}
}

void Heap::readFromFile(FileHandler& fileHandler) {

	heapArray->readFromFile(fileHandler);
}


void Heap::printTree(const std::string& sMiddle, const std::string &sBefore, int currNode) {
	std::string s;

	if (currNode < heapArray->getSize()) {
		s = sMiddle;
		if (sBefore == (std::string(1, (char)47) + std::string(1, (char)126)))
			s[s.length() - 2] = ' ';
		printTree(s + (char)124 + " ", (std::string(1, (char)47)) + std::string(1, (char)126), 2 * currNode + 2);

		s = s.substr(0, sMiddle.length() - 2);

		std::cout << s << sBefore << (*heapArray)[currNode] << std::endl;

		s = sMiddle;

		if (sBefore == (std::string(1, (char)92)) + std::string(1, (char)126))
			s[s.length() - 2] = ' ';

		printTree(s + (char)124 + " ", (std::string(1, (char)92)) + std::string(1, (char)126), 2 * currNode + 1);
}
}