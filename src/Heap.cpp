#include "Heap.h"

#include <random>

void Heap::insert(int position, int value) {
	if (position != heapArray->getSize())
		position = heapArray->getSize();

	heapArray->insert(position, value);

	fixUp(heapArray->getSize() - 1);

	++size;
}

void Heap::fixUp(int indexFound) {

	int currentNode = indexFound;
	int parent = (currentNode - 1) / 2;

	while (currentNode != 0 and (*heapArray)[currentNode] > (*heapArray)[parent]) {
		heapArray->swapElements(currentNode, parent);
		currentNode = parent;
		parent = (currentNode - 1) / 2;
	}


}

void Heap::fixDown(int indexFound) {

	 int parentIndex = indexFound;
	 int leftChildIndex = 2 * indexFound + 1;
	 int rightChildIndex = 2 * indexFound + 2;
	 int swapChildIndex;

	 while (leftChildIndex < heapArray->getSize()  and rightChildIndex < heapArray->getSize()) {


	     swapChildIndex = ((*heapArray)[leftChildIndex] > (*heapArray)[rightChildIndex]) ? leftChildIndex : rightChildIndex;

	     if ((*heapArray)[swapChildIndex] > (*heapArray)[parentIndex]) {

	         heapArray->swapElements(parentIndex, swapChildIndex);
	         parentIndex = swapChildIndex;
	     }
	     leftChildIndex = 2 * parentIndex + 1;
	     rightChildIndex = 2 * parentIndex + 2;
	}


}

void Heap::remove(int value) {

	int indexFound;

	for (int i{0}; i < heapArray->getSize(); i++) {

		if((*heapArray)[i] == value ) {
			indexFound = i;
			break;
		}
	}

	bool isBigger;
	(*heapArray)[heapArray->getSize() -1] > (*heapArray)[indexFound] ? isBigger = true : isBigger = false;

	heapArray->swapElements(indexFound, heapArray->getSize() -1);
	heapArray->remove(heapArray->getSize() -1);

//	std::cout << "Before fix" << std::endl;
//	print();
//
	if (isBigger)
		fixUp(indexFound);
	else
		fixDown(indexFound);

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
	//TODO: Implement validation of size of read data
	int buffer{};
	int tmpSize{};

	fileHandler.inputFile >> tmpSize;
	int position{0};
//TODO: Needs alignment - position is always 0. After insert() alignement
	while(fileHandler.inputFile >> buffer) {
		insert(position, buffer);
	}

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

void Heap::clearStructure() {
	heapArray->clearStructure();
}
