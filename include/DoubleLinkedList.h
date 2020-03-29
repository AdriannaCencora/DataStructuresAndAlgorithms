#pragma once

#include "GenericStructure.h"

#include <memory>

class DoubleLinkedList : public GenericStructure {
    public:
        DoubleLinkedList() {}
        DoubleLinkedList(int size) : size(size) {}
        virtual ~DoubleLinkedList() {}

        virtual void insert(int position, int value);
        virtual void remove(int value);
        virtual bool search(int value);
        virtual int getSize();
        virtual void print();
        virtual void fillWithRandomData(int givenSize, int givenUpperRange);
		virtual void readFromFile();

		struct Node {
			Node(int nodeData) : data(nodeData) {}

			int data{};
			Node* next{nullptr};
			Node* prev{nullptr};
		};


    private:
		bool isEmpty();
		void findNodeAtPosition(int position);

		Node* currentNode;
		Node* head{nullptr};
		Node* tail{nullptr};
		size_t size{};

		void insertFront(int value);
		void insertBack(int value);
		void insertAtPosition(int position, int value);



};
