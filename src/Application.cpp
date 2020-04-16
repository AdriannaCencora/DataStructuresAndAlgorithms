#include <chrono>
#include <iostream>
#include "Application.h"
#include "DynamicArray.h"
#include "DoubleLinkedList.h"
#include "Heap.h"
#include "BST.h"

#include "FileHandler.h"
#include "Test.h"

using namespace std;

void Application::displayMenu() {
    cout << "MENU" << endl;
    cout << "Pick a number." << endl;
    cout << "1. Dynamic Array." << endl;
    cout << "2. Double Linked List." << endl;
    cout << "3. Heap." << endl;
    cout << "4. BST." << endl;
    cout << "5. R&B Tree." << endl;
    cout << "6. AVL." << endl;

    cout << "t. Test." << endl;
    cout << "0. Exit." << endl << endl;
}

void Application::displaySubMenu() {
	std::cout << std::endl << std::endl;
    cout << "SUBMENU" << endl;
    cout << "Pick a number." << endl;
    cout << "1. Read data from file." << endl;
	cout << "2. Fill in random numbers" << endl;
	cout << "3. Search" << endl;
	cout << "4. Insert" << endl;
	cout << "5. Remove" << endl;
	cout << "6. Print" << endl;
	cout << "0. Exit" << endl << endl;
}

void Application::run() {
    while (isRunning) {
	        displayMenu();
	        cin >> userChoice;

			switch (userChoice) {
				case '0':
				   	{
						isRunning = false;
						break;
					}
				case '1':
					{
						structure = std::make_unique<DynamicArray>();
						chooseOperation();
					}	break;
				case '2':
					{
						structure = std::make_unique<DoubleLinkedList>();
						chooseOperation();
						break;
					}
				case '3':
					{
						structure = std::make_unique<Heap>();
						chooseOperation();
					}
				case '4':
					{
						structure = std::make_unique<BST>();
						chooseOperation();
					}
				case 't':
					{
						Test test;
						test.run();
						break;
					}
				default:
				   	{
						cout << "wrooong number, next time choose better!" << endl << endl;
						break;
					}
				}
}
}

void Application::chooseOperation() {

	bool isRunning{true};
	int position{};
	int size{};
	int value{};
	int upperRange{};

	while (isRunning) {
		displaySubMenu();
		cin >> operationChosen;

		switch (operationChosen) {
			case '0': {
				isRunning = false;
				break;
					  }
			case '1': {
				std::string fileName;
				std::cout << "Filename: " << std::endl;
				std::cin >> fileName;

				auto fileHandler = new FileHandler(fileName);
				structure->readFromFile(*fileHandler);
				delete fileHandler;
				break;
					  }
			case '2': {
				std::cout << "Size: " << std::endl;
				std::cin >> size;
				std::cout << "Upper range: " << std::endl;
				std::cin >> upperRange;
				structure->fillWithRandomData(size, upperRange);
				structure->print();
				break;
					  }
			case '3': {
				std::cout << "Value to search: " << std::endl;
				std::cin >> value;

				if (structure->search(value))
					std::cout << "Number found" ;
				else
					std::cout << "Number not found" ;

				structure->print();
				break;
					  }
			case '4': {
				std::cout << "Value to insert: " << std::endl;
				std::cin >> value;
				std::cout << "Position: " << std::endl;
				std::cin >> position;
				structure->insert(position, value);
				structure->print();
				break;
					  }
			case '5': {
				std::cout << "Remove from position (array) / remove value (list, heap]): " << std::endl;
				std::cin >> position;
				structure->remove(position);
				structure->print();
				break;
					  }
			case '6':
				structure->print();
				break;
			default:
				std::cout << "Wrooong number, next time choose better!" << endl << endl;
				break;



		}

	}

}
