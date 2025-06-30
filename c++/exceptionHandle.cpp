#include <iostream>
using namespace std;

int main()
{
    try {
        int x = 1;
        int y = 0;
        int ans;

        if(y==0)
            throw "divide by zero";
        ans = x / y;
    }
    catch ( char const *e) {
        cout << "This is 0 exception " << e << endl;
    }
    catch (exception E) {
        cout << "This is exception" << endl;
    }
    return 0;
}