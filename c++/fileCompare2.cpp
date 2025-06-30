#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class readFile {

private:
    std::vector<std::string> log;
    int o = 1;

public:
    readFile(std::string myFile)
    {
        std::string buffer;
        std::string b;
        std::ifstream input_file(myFile);

        if (!input_file.is_open())
        {
            std::cout << "Could not open the file " << myFile << std::endl;
            exit(EXIT_FAILURE);
        }

        while (input_file >> buffer)
        {
            if (o > 2)
            {
                log.push_back(b);
                o = 0;
                b.erase();
            }
            else {
                b.append(buffer);
                b.append(" ");
                ++o;
            }
        }

        input_file.close();
    }

    size_t getSize() { return log.size(); }
    std::string getLine(size_t index){ return log[index]; }
};

int main()
{
    size_t maxSize;

    readFile txt1("concurrentThreads.cpp");
    readFile txt2("conditionalVariable.cpp");

    txt1.getSize() <= txt2.getSize() ? maxSize = txt1.getSize() : maxSize = txt2.getSize();
   
    for (size_t x = 0; x < maxSize; ++x)
    {
        std::cout << "debug txt1: " << txt1.getLine(x) << std::endl;
        std::cout << "debug txt2: " << txt2.getLine(x) << std::endl;
        if (txt1.getLine(x) != txt2.getLine(x))
            std::cout << "this line is not the same : " << txt1.getLine(x) << std::endl;
    }

    return 0;
}