#include "BST.h"

#include <string>
#include <random>
//TODO: structure is not cleared properly
BST::Node* BST::insert(BST::Node* currentParent, int value) {

	if (currentParent == nullptr) {
		size++;
		Node* node = new Node(value);
		node->parent = currentParent;
		return node;
	}

	else if (currentParent->data > value) {
		currentParent->leftChild = insert(currentParent->leftChild, value);
	}

	else if(currentParent->data < value) {
		currentParent->rightChild = insert(currentParent->rightChild, value);
	}

	return currentParent;

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

	print();
	std::cout << "!!!" << std::endl;
	makeLinear();
	print();
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


bool BST::isEmpty() {

	return size == 0;
}

void BST::rotateLeft(Node* axisNode) {

	if (axisNode->rightChild == nullptr)
		return;

	if (axisNode->parent != nullptr) {

		if (axisNode->parent->leftChild == axisNode)
			axisNode->parent->leftChild = axisNode->rightChild;

		else if (axisNode->parent->rightChild == axisNode)
			axisNode->parent->rightChild == axisNode->rightChild;
	}

	axisNode->rightChild->parent = axisNode->parent;
	axisNode->parent = axisNode->rightChild;
	axisNode->rightChild->leftChild = axisNode;

	if (axisNode->rightChild->leftChild != nullptr) {
		axisNode->rightChild = axisNode->rightChild->leftChild;
	}
}

void BST::rotateRight(Node* axisNode) {

	if (axisNode->leftChild == nullptr)
		return;

	if (axisNode == nullptr)
		return;

	Node* leftChildCopied = axisNode->leftChild;
	Node* parentCopied = axisNode->parent;

	if (leftChildCopied->rightChild) {

		axisNode->leftChild = leftChildCopied->rightChild;
		axisNode->leftChild->parent = axisNode;
	}

	leftChildCopied->rightChild = axisNode;
	leftChildCopied->parent = parentCopied;
	axisNode->parent = leftChildCopied;


	if (parentCopied != nullptr) {

		if (parentCopied->leftChild == axisNode) {
			parentCopied->leftChild = leftChildCopied;
		}

		else if (parentCopied->rightChild == axisNode) {
			parentCopied->rightChild == axisNode->leftChild;
		}

	}

	else
		root = leftChildCopied;




	//
//	// setting childs
//	if (axisNode->leftChild->rightChild != nullptr) {
//		axisNode->leftChild = axisNode->leftChild->rightChild;
//		axisNode->leftChild->parent = axisNode;
//	}
//
//	axisNode->leftChild->rightChild = axisNode;
//
//
//	axisNode->leftChild->parent = axisNode->parent;
//	axisNode->parent = axisNode->leftChild;
//
//	if (axisNode->leftChild->parent == nullptr)
//		root = axisNode->leftChild;

//	axisNode->leftChild->parent = axisNode->parent;
//	axisNode->parent = axisNode->leftChild;
//	axisNode->leftChild->rightChild = axisNode;



}


void BST::makeLinear() {

	Node* currentAxisNode = root;

	while (currentAxisNode != nullptr) {

		if (currentAxisNode->leftChild != nullptr) {
			rotateRight(currentAxisNode);
			currentAxisNode = currentAxisNode->parent;
		}

		else {
			currentAxisNode = currentAxisNode->rightChild;

		}
	}

}

void BST::makeBalanced() {}
void BST::fixBalance() {}
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



