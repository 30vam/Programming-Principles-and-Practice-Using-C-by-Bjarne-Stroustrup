#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
inline void keep_window_open() { char ch; cin >> ch; }
// error function to be used (only) until error() is introduced in Chapter 5:
inline void simple_error(string s)	// write ``error: sТТ and exit program
{
    cerr << "error: " << s << '\n';
    keep_window_open();		// for some Windows environments
    exit(1);
}

int main()
{
    constexpr int firstNum = 48;
    constexpr int lastNum = 57;
    constexpr int firstUppercase = 65;
    constexpr int lastUppercase = 90;
    constexpr int firstLowercase = 97;
    constexpr int lastLowercase = 122;

    for (int i = firstNum; i <= lastLowercase; i++)
    {
        cout << char(i) << "\t" << i << endl;

        switch (i)
        {
        case lastNum:
            i = firstUppercase - 1;
            break;
        case lastUppercase:
            i = firstLowercase - 1;
            break;
        default:
            break;
        }
    }
    
}

