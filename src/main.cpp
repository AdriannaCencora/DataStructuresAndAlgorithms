#include <iostream>
#include <memory>
#include <DynamicArray.h>
#include <DoubleLinkedList.h>
#include "Application.h"

int main() {

	Application app;
	app.run();

	std::unique_ptr<GenericStructure> structure{};
//	int i;
//	std::cin >> i;
	structure = std::make_unique<DoubleLinkedList>();

	structure->fillWithRandomData(10,1000);
//	structure->print();
//	if (structure->search(200)) {
//		std::cout << "Number found" ;
//	}
//	else
//		std::cout << "Number not found" ;
//
	structure->insert(2, 200);
	structure->insert(2, 666);






    return 0;
}
