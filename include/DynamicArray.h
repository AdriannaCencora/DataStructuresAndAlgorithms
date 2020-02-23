#pragma once

#include "GenericStructure.h"

#include <memory>

class DynamicArray : public GenericStructure {
    public:
        DynamicArray() {}
        DynamicArray(int size) : data(std::make_unique<int[]>(size)), logicalSize(size), capacity(size*2) {}
        virtual ~DynamicArray() {}

        virtual void insert(int position, int value);
        virtual void remove(int position);
        virtual int search(int value);
        virtual int getSize();
        virtual void print();
        virtual void fillWithRandomData();
		virtual void readFromFile();

    private:
        std::unique_ptr<int[]> data{};
        std::size_t logicalSize{};
		std::size_t capacity{};

};
