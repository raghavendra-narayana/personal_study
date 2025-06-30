#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> // for merge operations


using namespace std;

class readFile {

private:
    vector<string> log;
    int o = 1;

public:
    readFile(string myFile)
    {
        string buffer;
        string b;
        ifstream input_file(myFile);
        string line;

        if (!input_file.is_open())
        {
            cout << "Could not open the file " << myFile << endl;
            exit(EXIT_FAILURE);
        }

        while (getline(input_file, line))
        {
            log.push_back(line);
            cout << "read: ~" << line << endl;
        }

        input_file.close();
    }

    size_t getSize() { return log.size(); }
    string getLine(size_t index){ return log[index]; }
    vector<string>& getVectorLog(){ return log; }
};

int main()
{
    size_t maxSize;

    readFile txt1("concurrentThreads.cpp");
    readFile txt2("conditionalVariable.cpp");

    txt1.getSize() <= txt2.getSize() ? maxSize = txt1.getSize() : maxSize = txt2.getSize();
   
    vector<string> v3(1024);

    // using set_difference() to compute difference
    // of 2 containers v1 and v2.
    auto it = set_symmetric_difference(txt1.getVectorLog().begin(), txt1.getVectorLog().end(),
              txt2.getVectorLog().begin(), txt2.getVectorLog().end(), v3.begin());

    // resizing new container
    v3.resize(it - v3.begin());

    cout << "Difference of two containers is : " << endl;
    for (string &x : v3) 
        cout << x << endl;
    cout << endl;

    return 0;
}