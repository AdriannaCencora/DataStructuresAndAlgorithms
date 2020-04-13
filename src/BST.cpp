#include "BST.h"

#include <string>

void BST::insert(int position, int value) {}
void BST::remove(int value) {}
bool BST::search(int value) {}
int BST::getSize() const {
	return size;
}
void BST::print() {}
void BST::fillWithRandomData(int givenSize, int givenUpperRange) {}
void BST::readFromFile(FileHandler& fileHandler) {}

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



