#include "Test.h"
#include "DoubleLinkedList.h"
#include "DynamicArray.h"

#include <fstream>
#include <sstream>
#include <chrono>

void Test::run() {
	srand (time(NULL));

	structure = std::make_unique<DoubleLinkedList>();
	prependFile("DoubleLinkedList");
	insertionTests(true);
	deletionTests(true);
	searchTests();

	structure = std::make_unique<DynamicArray>();
	prependFile("DynamicArray");
	insertionTests(false);
	deletionTests(false);
	searchTests();
}

void Test::prependFile(std::string structureName) {
	fileName = structureName;
	fileName.append(".txt");

	std::ofstream ofs;
	ofs.open(fileName, std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	saveToFile(structureName);


}

void Test::prepareStructure(int size) {

	for (int i = size; i >= 0; i-- ) {
			structure->insert(0, i);
	}

}

void Test::insertionTests(bool byValue) {
	insertFront(byValue);
	insertBack(byValue);
	insertAtPosition(byValue);
}

void Test::deletionTests(bool byValue) {
	deleteFront(byValue);
	deleteBack(byValue);
	deleteAtPosition(byValue);
}


void Test::saveToFile(int testSize, int time) {

	outputFile.open(fileName, std::ios::out | std::ios::app);
	if (outputFile.good())
	{
		try {
					outputFile << testSize << ": " << time << std::endl;

				}
		catch (...)
		{
					std::cout << "Gotcha!" << std::endl;
					system("pause");
				}
		}
	else
	{
			std::cout << "Test file error occured!" << std::endl;
			system("pause");
		}
	outputFile.close();
}


void Test::saveToFile(std::string message){

	outputFile.open(fileName, std::ios::out | std::ios::app);
	if (outputFile.good())
		outputFile << message << std::endl;
	else
	{
			std::cout << "Test file error occured!" << std::endl;
			system("pause");
		}
	outputFile.close();
}


void Test::insertFront(bool byValue) {
	std::chrono::high_resolution_clock::time_point startTime;
	std::chrono::high_resolution_clock::time_point endTime;

	long totalTime = 0;

	saveToFile("Insert at beginning");

	for(int testCase{1}; testCase < 10; testCase++) {

		prepareStructure(testCase * 2000);

		for (int k{0}; k < 1000; k++) {
			startTime = std::chrono::high_resolution_clock::now();

			structure->insert(0, k);

			endTime = std::chrono::high_resolution_clock::now();

			if (byValue)
				structure->remove(k);
			else
			   structure->remove(0);

			totalTime += (long)std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
		}

		saveToFile(testCase * 2000, totalTime/1000);
		totalTime = 0;
	}
}


void Test::insertBack(bool byValue) {
	std::chrono::high_resolution_clock::time_point startTime;
	std::chrono::high_resolution_clock::time_point endTime;

	long totalTime = 0;

	saveToFile("Insert back");

	for(int testCase{1}; testCase < 10; testCase++) {

		prepareStructure(testCase * 2000);

		for (int k{0}; k < 1000; k++) {
			startTime = std::chrono::high_resolution_clock::now();

			structure->insert(structure->getSize(), k);

			endTime = std::chrono::high_resolution_clock::now();

			if (byValue)
				structure->remove(k);
			else
			   structure->remove(structure->getSize() - 1);

			totalTime += (long)std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
		}

		saveToFile(testCase * 2000, totalTime/1000);
		totalTime = 0;
	}
}


void Test::insertAtPosition(bool byValue) {
	std::chrono::high_resolution_clock::time_point startTime;
	std::chrono::high_resolution_clock::time_point endTime;

	long totalTime = 0;
	int randomValue;

	saveToFile("Insert randomly");

	for(int testCase{1}; testCase < 10; testCase++) {

		prepareStructure(testCase * 2000);

		for (int k{0}; k < 1000; k++) {

			randomValue = rand() % structure->getSize();

			startTime = std::chrono::high_resolution_clock::now();

			structure->insert(randomValue, k);

			endTime = std::chrono::high_resolution_clock::now();

			if (byValue)
				structure->remove(k);
			else
			   structure->remove(0);

			totalTime += (long)std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
		}

		saveToFile(testCase * 2000, totalTime/1000);
		totalTime = 0;
	}
}


void Test::deleteFront(bool byValue) {
	std::chrono::high_resolution_clock::time_point startTime;
	std::chrono::high_resolution_clock::time_point endTime;

	long totalTime = 0;

	saveToFile("Remove at beginning");

	for(int testCase{1}; testCase < 10; testCase++) {

		prepareStructure(testCase * 2000);

		for (int k{0}; k < 1000; k++) {
			startTime = std::chrono::high_resolution_clock::now();

			if (byValue)
				structure->remove(k);
			else
			   structure->remove(0);

			endTime = std::chrono::high_resolution_clock::now();

			totalTime += (long)std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
		}

		saveToFile(testCase * 2000, totalTime/1000);
		totalTime = 0;
	}

}

void Test::deleteBack(bool byValue) {
	std::chrono::high_resolution_clock::time_point startTime;
	std::chrono::high_resolution_clock::time_point endTime;

	long totalTime = 0;

	saveToFile("Remove back");

	for(int testCase{1}; testCase < 10; testCase++) {

		prepareStructure(testCase * 2000);

		for (int k{0}; k < 1000; k++) {
			startTime = std::chrono::high_resolution_clock::now();

			if (byValue)
				structure->remove(testCase * 2000 - 1 - k);
			else
			   structure->remove(structure->getSize() - 1);

			endTime = std::chrono::high_resolution_clock::now();

			totalTime += (long)std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
		}

		saveToFile(testCase * 2000, totalTime/1000);
		totalTime = 0;
	}


}
void Test::deleteAtPosition(bool byValue) {
	std::chrono::high_resolution_clock::time_point startTime;
	std::chrono::high_resolution_clock::time_point endTime;

	long totalTime{0};
	int indexToDelete{};
	int* helperArray;
	int randomValue;

	saveToFile("Remove at randomly");

	for(int testCase{1}; testCase < 10; testCase++) {

		prepareStructure(testCase * 2000);

		if (byValue) {
			helperArray = new int [testCase * 2000 - 1];

			for (int i = 0; i < testCase * 2000; i++) {
				helperArray[i] = i;
			}
		}

		for (int k{0}; k < 1000; k++) {

			if (byValue)
				indexToDelete = rand() % (testCase * 2000 - 1);


			randomValue = rand() % structure->getSize();

			startTime = std::chrono::high_resolution_clock::now();

			if (byValue) {
				structure->remove(helperArray[indexToDelete]);

			}
			else
			   structure->remove(randomValue);

			endTime = std::chrono::high_resolution_clock::now();

			totalTime += (long)std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
		}

		saveToFile(testCase * 2000, totalTime/1000);
		totalTime = 0;
	}
}


void Test::searchTests() {
	std::chrono::high_resolution_clock::time_point startTime;
	std::chrono::high_resolution_clock::time_point endTime;

	long totalTime = 0;

	int randomValue;

	saveToFile("Search");

	for(int testCase{1}; testCase < 10; testCase++) {

		prepareStructure(testCase * 2000);

		for (int k{0}; k < 1000; k++) {
			randomValue = rand() % structure->getSize();

			startTime = std::chrono::high_resolution_clock::now();
			structure->search(randomValue);
			endTime = std::chrono::high_resolution_clock::now();

			totalTime += (long)std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
		}

		saveToFile(testCase * 2000, totalTime/1000);
		totalTime = 0;
	}

}
