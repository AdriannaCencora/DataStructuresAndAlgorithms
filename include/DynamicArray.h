#pragma once

#include "GenericStructure.h"

#include <memory>

class DynamicArray : public GenericStructure {
    public:
        DynamicArray() {}
        DynamicArray(int size) : logicalSize(size), capacity(size*2), data(std::make_unique<int[]>(capacity)) {}
        virtual ~DynamicArray() {}

        virtual void insert(int position, int value);
        virtual void remove(int position);
        virtual bool search(int value);
        virtual int getSize();
        virtual void print();
        virtual void fillWithRandomData();
		virtual void readFromFile();

		int logicalSize;
    private:
		void insertFront(int value);
		void insertBack(int value);
		void insertAtPosition(int position, int value);

		void resize(int newCapacity);

		int capacity{};
        std::unique_ptr<int[]> data{};

};
