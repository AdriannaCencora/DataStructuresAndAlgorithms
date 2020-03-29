#pragma once

#include <fstream>
#include <string>
#include <iostream>

class FileHandler {
	public:
    explicit FileHandler(std::string &_fileName) : inputFile(_fileName, std::ios::in) {
	        if (!inputFile.is_open()) {
			            std::cerr << "File couldn't be opened!" << std::endl;
			            return;
			        }
	    }

    ~FileHandler()  {
	        inputFile.close();
	    }

	private:
    std::fstream inputFile;


};

