#pragma once

#include "GenericStructure.h"
#include "DynamicArray.h"

#include <memory>
#include <string>

class Heap : public GenericStructure {
    public:
        Heap() : heapArray(std::make_unique<DynamicArray>()) {}
        Heap(int size) : size(size), heapArray(std::make_unique<DynamicArray>()) {}
        virtual ~Heap() {}

        virtual void insert(int position, int value);
        virtual void remove(int position);
        virtual bool search(int value);
        virtual void print();
		virtual int getSize() const;
        virtual void fillWithRandomData(int givenSize, int givenUpperRange);
		virtual void readFromFile(FileHandler& fileHandler);
		virtual void clearStructure();

    private:
		void printTree(const std::string& sMiddle, const std::string &sBefore, int currNode);
		int size{};
        std::unique_ptr<DynamicArray> heapArray{};
};
