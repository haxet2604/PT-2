#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <fstream>
#include <string>
#include <vector>

class FileProcessor {
private:
    std::ifstream fileStream;

public:
    FileProcessor(const std::string& fileName);
    ~FileProcessor();

    std::vector<std::string> getLinesWithTwoDigitNumbers();
};

#endif
