#include "DoubleLinkedList.h"

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
	currentNode->prev->next = newNode;
	currentNode->prev = newNode;

	++size;
}

void DoubleLinkedList::remove(int value) {}
bool DoubleLinkedList::search(int value) {}

int DoubleLinkedList::getSize() {
	return size;
}

void DoubleLinkedList::print() {}
void DoubleLinkedList::fillWithRandomData(int givenSize, int givenUpperRange) {}
void DoubleLinkedList::readFromFile() {}

bool DoubleLinkedList::isEmpty() {
	return size==0;
}

void DoubleLinkedList::findNodeAtPosition(int position) {

	if(isEmpty())
		currentNode = nullptr;

	else {
		currentNode = head;

		for(int i{0}; i <= position and currentNode != nullptr; ++i) {
			currentNode = currentNode->next;
		}
	}
}
