#include "BST.h"

#include <string>
#include <random>

//TODO: structure is not cleared properly
BST::Node* BST::insert(BST::Node* currentParent, int value) {

	if (currentParent == nullptr) {
		size++;
		Node* node = new Node(value);
		node->parent = nullptr;
		return node;
	}

	else if (currentParent->data > value) {
		currentParent->leftChild = insert(currentParent->leftChild, value);
		currentParent->leftChild->parent = currentParent;
	}

	else if(currentParent->data < value) {
		currentParent->rightChild = insert(currentParent->rightChild, value);
		currentParent->rightChild->parent = currentParent;
	}

	return currentParent;

}

void BST::insert(int position, int value) {

	//seg fault
//	clearStructure(root);

	root = insert(root, value);

}

void BST::remove(int value) {}


BST::Node* BST::search(BST::Node* node, int value) {

	if (node == nullptr)
		return nullptr;

	else if (node->data == value)
		return node;
	else if (value < node->data)
		return search(node->leftChild, value);
	else
		return search(node->rightChild, value);
}

bool BST::search(int value) {

	Node* result = search(root, value);

	return result;
}

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

	fixBalance();
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

	if (axisNode == nullptr)
		return;

	Node* rightChildCopied = axisNode->rightChild;
	Node* parentCopied = axisNode->parent;

	axisNode->rightChild = rightChildCopied->leftChild;

	if (rightChildCopied->leftChild != nullptr) {

		axisNode->rightChild->parent = axisNode;
	}

	rightChildCopied->leftChild = axisNode;
	rightChildCopied->parent = parentCopied;
	axisNode->parent = rightChildCopied;

	if (parentCopied != nullptr) {

		if (parentCopied->leftChild == axisNode) {
			parentCopied->leftChild = rightChildCopied;
		}

		else if (parentCopied->rightChild == axisNode) {
			parentCopied->rightChild = rightChildCopied;
		}
	}

	else
		root = rightChildCopied;
}

void BST::rotateRight(Node* axisNode) {

	if (axisNode->leftChild == nullptr)
		return;

	if (axisNode == nullptr)
		return;

	Node* leftChildCopied = axisNode->leftChild;
	Node* parentCopied = axisNode->parent;

	axisNode->leftChild = leftChildCopied->rightChild;

	if (leftChildCopied->rightChild != nullptr)
		axisNode->leftChild->parent = axisNode;

	leftChildCopied->rightChild = axisNode;


	leftChildCopied->parent = parentCopied;
	axisNode->parent = leftChildCopied;

	if (parentCopied != nullptr) {

		if (parentCopied->leftChild == axisNode) {
			parentCopied->leftChild = leftChildCopied;
		}

		else if (parentCopied->rightChild == axisNode) {
			parentCopied->rightChild = leftChildCopied;
		}
	}

	else
		root = leftChildCopied;
}

void BST::makeLinear() {

	Node* currentAxisNode = root;

	while (currentAxisNode != nullptr) {
		std::cout<< "***********" << std::endl;
		print();
		std::cout<< "***********" << std::endl;
		if (currentAxisNode->leftChild != nullptr) {
			rotateRight(currentAxisNode);
			currentAxisNode = currentAxisNode->parent;
		}

		else
			currentAxisNode = currentAxisNode->rightChild;
	}

}

void BST::makeBalanced() {

	int rotationNumber = pow(2, floor(log2(size + 1))) - 1;
	int firstIterationRotationNumber = size - rotationNumber;

	Node* currentAxisNode = root;

	for (int i{0}; i < firstIterationRotationNumber; i++) {
		rotateLeft(currentAxisNode);
		currentAxisNode = currentAxisNode->parent->rightChild;
	}

	while (rotationNumber > 1) {
		currentAxisNode = root;
		rotationNumber = floor(rotationNumber / 2);

		for (int i{0}; i < rotationNumber; i++) {
			rotateLeft(currentAxisNode);
			currentAxisNode = currentAxisNode->parent->rightChild;
		}

	}

}


void BST::fixBalance() {

	if (root != nullptr) {
		makeLinear();
		makeBalanced();
	}
}


BST::Node* BST::getMin(BST::Node* node) {
	while (node->leftChild != nullptr) {
		node = node->leftChild;
	}

	return node;
}

BST::Node* BST::getMax(BST::Node* node) {
	while (node->rightChild != nullptr) {
		node = node->rightChild;
	}

	return node;
}


BST::Node* BST::getPredecessor(BST::Node* node) {}
BST::Node* BST::getSuccessor(BST::Node* node) {}

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

void BST::clearStructure(BST::Node *node) {
	if (node != nullptr) {

		clearStructure(node->leftChild);
		clearStructure(node->rightChild);
		delete node;
	}

}
