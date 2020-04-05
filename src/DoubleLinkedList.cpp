#include "DoubleLinkedList.h"

#include <random>

void DoubleLinkedList::insert(int position, int value) {

	if (position == 0)
		insertFront(value);

	else if (position == size)
		insertBack(value);

	else if (position < 0 or position > size)
		throw std::invalid_argument("Out of range.");

	else
		insertAtPosition(position, value);
}

void DoubleLinkedList::insertFront(int value) {

	Node* newNode = new Node(value);

	if (isEmpty()) {
		head = newNode;
		tail = newNode;
	}

	else {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}

	++size;

}

void DoubleLinkedList::insertBack(int value)  {

	Node* newNode = new Node(value);

	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;

	++size;

}

void DoubleLinkedList::insertAtPosition(int position, int value) {
	findNodeAtPosition(position);
	Node* newNode = new Node(value);

	newNode->next = currentNode;
	newNode->prev = currentNode->prev;
	newNode->prev->next = newNode;
	currentNode->prev = newNode;

	++size;

}

void DoubleLinkedList::remove(int value) {

	findNodeByValue(value);

	if (currentNode == nullptr)
		std::cout << std::endl << "Node doesn't exist" << std::endl;

	else if (currentNode == head) {
		currentNode->next->prev = nullptr;
		head = currentNode->next;
	}

	else if (currentNode == tail) {
		currentNode->prev->next = nullptr;
		tail = currentNode->prev;
	}


	else {
		currentNode->prev->next = currentNode->next;
		currentNode->next->prev = currentNode->prev;

	}

	--size;
}


bool DoubleLinkedList::search(int value) {
	findNodeByValue(value);

	if (currentNode != nullptr) {
		return true;
	}

	return false;

}

int DoubleLinkedList::getSize() const {
	return size;
}

void DoubleLinkedList::print() {

	currentNode = head;

	while (currentNode != nullptr) {
		std::cout<< currentNode->data << " ";
		currentNode = currentNode->next;
	}
}

void DoubleLinkedList::fillWithRandomData(int givenSize, int givenUpperRange) {

	const int upperRange = givenUpperRange;

	std::random_device seed;
    std::mt19937 randomGenerator(seed());
	std::uniform_int_distribution<> transform(1, upperRange);

	for (int position{0}; position < givenSize; ++position) {
		insert(position, transform(randomGenerator));
	}
}
void DoubleLinkedList::readFromFile(FileHandler& fileHandler) {

	int buffer{};
	int tmpSize{};

	fileHandler.inputFile >> tmpSize;
	int position{};

	while(fileHandler.inputFile >> buffer) {
		insert(position, buffer);
		++position;
	}
}

bool DoubleLinkedList::isEmpty() {
	return size==0;
}

void DoubleLinkedList::findNodeAtPosition(int position) {

	if(isEmpty())
		currentNode = nullptr;

	else {
		currentNode = head;

		for(int i{0}; i <= position and currentNode != nullptr; i++) {
			if (i != position)
				currentNode = currentNode->next;
		}
	}
}

void DoubleLinkedList::findNodeByValue(int value) {

	currentNode = head;

	while(currentNode != nullptr and currentNode->data != value) {
			currentNode = currentNode->next;
		}


}
