#include <iostream>

#include "DynamicArray.h"
#include "DoubleLinkedList.h"

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

	std::unique_ptr<GenericStructure> structure1{};
	structure1 = std::make_unique<DoubleLinkedList>();

	structure1->insert(0, 200);
	structure1->insert(1, 200);
	structure1->insert(1, 200);
	structure1->insert(0, 200);
	structure1->insert(2, 200);
	structure1->insert(1, 200);

    return 0;
}
