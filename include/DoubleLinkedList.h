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
        virtual void fillWithRandomData();
		virtual void readFromFile();

    private:
		bool isEmpty();

		struct Node {
			Node(int nodeData) : data(nodeData) {}

			int data{};
			Node* next{nullptr};
			Node* prev{nullptr};
		};

		Node* head{nullptr};
		Node* tail{nullptr};
		Node* currentNode{nullptr};

		size_t size{};

//		void insertFront(int value);
//		void insertBack(int value);
//		void insertAtPosition(int position, int value);


//        std::unique_ptr<int[]> data{};

};
