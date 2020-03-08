#pragma once

#include "GenericStructure.h"

#include <memory>

class DynamicArray : public GenericStructure {
    public:
        DynamicArray() :  capacity(4), data(std::make_unique<int[]>(capacity)) {}
        DynamicArray(int size) : size(size), capacity(size*2), data(std::make_unique<int[]>(capacity)) {}
        virtual ~DynamicArray() {}

        virtual void insert(int position, int value);
        virtual void remove(int position);
        virtual bool search(int value);
        virtual void print();
        virtual void fillWithRandomData();
		virtual void readFromFile();

		int getSize() const;
		int getCapacity() const;
		int getDataAt(int position) const;

    private:
		void insertFront(int value);
		void insertBack(int value);
		void insertAtPosition(int position, int value);
		void reassign(std::unique_ptr<int[]>);
		void resize(int newCapacity);
		void ror(int position);

		int size{};
		int capacity{};
        std::unique_ptr<int[]> data{};

};
