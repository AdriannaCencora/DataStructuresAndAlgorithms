#pragma once

#include "FileHandler.h"

class GenericStructure {
    public:
        virtual ~GenericStructure() = default;

        virtual void insert(int position, int value) = 0;
        virtual void remove(int position) = 0;
        virtual bool search(int value) = 0;
        virtual int getSize() const = 0;
        virtual void print() = 0;
        virtual void fillWithRandomData(int givenSize, int givenUpperRange) = 0;
		virtual void readFromFile(FileHandler& fileHandler) = 0;
};
