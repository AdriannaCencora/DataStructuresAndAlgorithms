#pragma once

#include "GenericStructure.h"
#include <memory>

class Application {
	public:
    Application() = default;

    ~Application() = default;
    void run();


	private:
	std::unique_ptr<GenericStructure> structure{};
    char userChoice{};
	char operationChosen{};
    bool isRunning{true};

    void displaySubMenu();
    void displayMenu();

	void chooseOperation();

};
