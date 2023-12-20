#include "fileprocessor.h"
#include <iostream>
#include <sstream>

FileProcessor::FileProcessor(const std::string& fileName) {
    fileStream.open(fileName);
    if (!fileStream.is_open()) {
        throw std::runtime_error("Unable to open file");
    }
    std::cout << "File opened successfully\n";
}

FileProcessor::~FileProcessor() {
    if (fileStream.is_open()) {
        fileStream.close();
        std::cout << "File closed\n";
    }
}

std::vector<std::string> FileProcessor::getLinesWithTwoDigitNumbers() {
    std::vector<std::string> result;
    std::string line;

    while (std::getline(fileStream, line)) {
        std::istringstream iss(line);
        std::string word;

        while (iss >> word) {
            if (word.length() == 2 && std::isdigit(word[0]) && std::isdigit(word[1])) {
                result.push_back(line);
                break;
            }
        }
    }

    return result;
}
