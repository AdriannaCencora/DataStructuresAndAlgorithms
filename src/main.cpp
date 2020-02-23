#include <iostream>

#include "DynamicArray.h"

int main() {
	std::unique_ptr<GenericStructure> structure{};
	structure = std::make_unique<DynamicArray>(5);

	structure->fillWithRandomData();
	structure->print();

    return 0;
}
