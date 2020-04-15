#include "BST.h"

#include <string>
#include <random>
//TODO: structure is not cleared yet!
BST::Node* BST::insert(BST::Node* currentParent, int value) {

	std::cout<< "Inside func " << std::endl;

	if (currentParent == nullptr) {
		size++;
		Node* node = new Node(value);
		node->parent = currentParent;
		std::cout << "Node added " << node->data << std::endl;
		return node;
	}

	else if (currentParent->data > value) {
		currentParent->leftChild = insert(currentParent->leftChild, value);
	std::cout<< "Left " << currentParent->data << std::endl;
	}

	else if(currentParent->data < value) {
		currentParent->rightChild = insert(currentParent->rightChild, value);
	std::cout<< "Right " << currentParent->data << std::endl;
	}

	return currentParent;
	std::cout<< "Current parent data returned  " << currentParent->data << std::endl;

}

void BST::insert(int position, int value) {

	root = insert(root, value);
}

void BST::remove(int value) {}
bool BST::search(int value) {}

int BST::getSize() const {
	return size;
}


void BST::print() {

	printNode(std::string(""), std::string(""), root);
}

void BST::fillWithRandomData(int givenSize, int givenUpperRange) {

	const int upperRange = givenUpperRange;

	std::random_device seed;
    std::mt19937 randomGenerator(seed());
	std::uniform_int_distribution<> transform(1, upperRange);

//TODO: Needs alignment - position is always 0. After insert() alignement
	for (int position{0}; position < givenSize; ++position) {
		insert(position, transform(randomGenerator));
	}


}
void BST::readFromFile(FileHandler& fileHandler) {

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

void BST::fixBalance() {}

bool BST::isEmpty() {

	return size == 0;
}

void BST::rotateLeft(Node* axis) {}
void BST::rotateRight(Node* axis) {}
void BST::makeLinear() {}
void BST::makeBalanced() {}
BST::Node* BST::getMin(BST::Node* node) {}
BST::Node* BST::getMax(BST::Node* node) {}
BST::Node* BST::getPredecessor(BST::Node* node) {}
BST::Node* BST::getSuccessor(BST::Node* node) {}
bool BST::isLeftChild(BST::Node* child) {}
bool BST::isRightChild(BST::Node* child) {}

void BST::printNode(const std::string &sMiddle, const std::string &sBefore, Node* currNode) {

	std::string s;

	if (currNode != nullptr) {

		s = sMiddle;

		if (sBefore == (std::string(1, (char)47) + std::string(1, (char)126)))
			s[s.length() - 2] = ' ';

		printNode(s + (char)124 + " ", (std::string(1, (char)47)) + std::string(1, (char)126), currNode->rightChild);

		s = s.substr(0, sMiddle.length() - 2);

		std::cout << s << sBefore << currNode->data << std::endl;

		s = sMiddle;
		if (sBefore == (std::string(1, (char)92)) + std::string(1, (char)126))
			s[s.length() - 2] = ' ';
		printNode(s + (char)124 + " ", (std::string(1, (char)92)) + std::string(1, (char)126), currNode->leftChild);
	}

}



