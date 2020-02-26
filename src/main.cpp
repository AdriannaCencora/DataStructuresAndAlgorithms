#include <iostream>

#include "DynamicArray.h"

int main() {
	std::unique_ptr<GenericStructure> structure{};
	structure = std::make_unique<DynamicArray>(5);

	structure->fillWithRandomData();
	structure->print();
	if (structure->search(200)) {
		std::cout << "Number found" ;
	}
	else
		std::cout << "Number not found" ;

	structure->insert(2, 200);

    return 0;
}
