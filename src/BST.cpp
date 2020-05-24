#include "BST.h"

#include <string>
#include <random>

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

	root = insert(root, value);
}

void BST::remove(int value) {

	Node* nodeToDelete = findNodeByValue(value);

	if (nodeToDelete != nullptr) {
		remove(nodeToDelete);
		size--;
	}

}

void BST::remove(BST::Node* nodeToDelete) {

	if (nodeToDelete->rightChild == nullptr and nodeToDelete->leftChild == nullptr) {

		if (nodeToDelete == root) {
			clearStructure(root);
			return;
		}
		if (nodeToDelete->parent->rightChild == nodeToDelete)
			nodeToDelete->parent->rightChild = nullptr;
		else
			nodeToDelete->parent->leftChild = nullptr;
	}

	else if (nodeToDelete->rightChild != nullptr and nodeToDelete->leftChild == nullptr and nodeToDelete->parent != nullptr) {

		if (nodeToDelete->parent->rightChild == nodeToDelete)
			nodeToDelete->parent->rightChild = nodeToDelete->rightChild;
		else
			nodeToDelete->parent->leftChild = nodeToDelete->rightChild;

		nodeToDelete->rightChild->parent = nodeToDelete->parent;

	}

	else if (nodeToDelete->leftChild != nullptr and nodeToDelete->rightChild == nullptr and nodeToDelete->parent != nullptr) {

		if (nodeToDelete->parent->rightChild == nodeToDelete)
			nodeToDelete->parent->rightChild = nodeToDelete->leftChild;
		else
			nodeToDelete->parent->leftChild = nodeToDelete->leftChild;

		nodeToDelete->leftChild->parent = nodeToDelete->parent;
	}

	else {
		Node* node = getSuccessor(nodeToDelete);

		if (node == nullptr)
			node = getPredecessor(nodeToDelete);

		nodeToDelete->data = node->data;
		remove(node);
	}


}

BST::Node* BST::findNodeByValue(int value) {

	Node* node = root;

	while(node != nullptr and node->data != value) {

		if (value < node->data)
			node = node->leftChild;
		else
			node = node->rightChild;
	}

	return node;
}


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

	clearStructure(root);

	const int upperRange = givenUpperRange;

	std::random_device seed;
    std::mt19937 randomGenerator(seed());
	std::uniform_int_distribution<> transform(1, upperRange);

	for (int position{0}; position < givenSize; ++position) {
		insert(position, transform(randomGenerator));
	}

}
void BST::readFromFile(FileHandler& fileHandler) {

	clearStructure(root);
	int buffer{};
	int tmpSize{};

	fileHandler.inputFile >> tmpSize;
	int position{0};

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


BST::Node* BST::getPredecessor(BST::Node* node) {

	if (node->leftChild != nullptr)
		return getMax(node->leftChild);

	Node* parentNode = node->parent;

	while (parentNode != nullptr and parentNode->rightChild != node) {
		node = parentNode;
		parentNode = node->parent;
	}

	return parentNode;

}

BST::Node* BST::getSuccessor(BST::Node* node) {

	if (node->rightChild != nullptr)
		return getMin(node->rightChild);

	Node* parentNode = node->parent;

	while (parentNode != nullptr and parentNode->leftChild != node) {
		node = parentNode;
		parentNode = node->parent;
	}

	return parentNode;

}

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
	node->parent = nullptr;
	node->leftChild = nullptr;
	node->rightChild = nullptr;
	node = nullptr;
	size = 0;


	}

}

void BST::clearStructure() {
	this->~BST();
}
