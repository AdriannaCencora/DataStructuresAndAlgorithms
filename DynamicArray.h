#include "GenericStructure.h"

#include <memory>

class DynamicArray : public GenericStructure {
    public:
        DynamicArray() {}
        DynamicArray(int size) : size(size), data(std::make_unique<int[]>(size)) {}
        virtual ~DynamicArray() {}

        virtual void insert(int position, int value);
        virtual void remove(int position);
        virtual int search(int value);
        virtual int getSize();
        virtual void print();
        virtual void generate();

    private:
        std::unique_ptr<int[]> data{};
        std::size_t size{};

};
