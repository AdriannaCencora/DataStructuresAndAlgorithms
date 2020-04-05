#pragma once

#include <bits/stdc++.h>

#include "GenericStructure.h"

class Test {
	public:
    Test() = default;

	void run();

	private:
	const int UPPER_RANGE = INT_MAX;
	const int NUMBER_OF_OPERATIONS = 100;

    std::ofstream outputFile{};
	std::string fileName{};
	std::unique_ptr<GenericStructure> structure{};

	void prependFile(std::string name);
	void saveToFile(int testSize, int time);
	void saveToFile(std::string message);

	void prepareStructure(int size);

	void insertionTests(bool byValue);
	void insertFront(bool byValue);
	void insertBack(bool byValue);
	void insertAtPosition(bool byValue);

	void deletionTests(bool byValue);
	void deleteFront(bool byValue);
	void deleteBack(bool byValue);
	void deleteAtPosition(bool byValue);


	void searchTests();
};
