#include <iostream>
#include <fstream>
#include <string>

bool compareFilesLineByLine(const std::string& file1Path, const std::string& file2Path) {
    std::ifstream file1(file1Path);
    std::ifstream file2(file2Path);

    if (!file1.is_open() || !file2.is_open()) {
        std::cerr << "Error: Could not open one or both files." << std::endl;
        return false;
    }

    std::string line1, line2;
    int lineNumber = 1;
    bool identical = true;

    while (std::getline(file1, line1) && std::getline(file2, line2)) {
        if (line1 != line2) {
            std::cout << "Difference found at line " << lineNumber << ":" << std::endl;
            std::cout << "File 1: " << line1 << std::endl;
            std::cout << "File 2: " << line2 << std::endl;
            identical = false;
        }
        lineNumber++;
    }

    // Check if one file has more lines than the other
    if (std::getline(file1, line1) || std::getline(file2, line2)) {
        std::cout << "Files have different number of lines." << std::endl;
        identical = false;
    }

    return identical;
}

int main() {
    std::string file1 = "file1.txt";
    std::string file2 = "file2.txt";

    if (compareFilesLineByLine(file1, file2)) {
        std::cout << "Files are identical." << std::endl;
    } else {
        std::cout << "Files are different (details above)." << std::endl;
    }

    return 0;
}