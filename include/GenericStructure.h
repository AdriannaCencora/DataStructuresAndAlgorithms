#pragma once

class GenericStructure {
    public:
        virtual ~GenericStructure() = default;

        virtual void insert(int position, int value) = 0;
        virtual void remove(int position) = 0;
        virtual int search(int value) = 0;
        virtual int getSize() = 0;
        virtual void print() = 0;
        virtual void fillWithRandomData() = 0;
		virtual void readFromFile() = 0;
};
