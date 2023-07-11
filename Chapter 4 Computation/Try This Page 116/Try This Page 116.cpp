// Implement square() without using the multiplication operator; that is, do the
//x*x by repeated addition (start a variable result at 0 and add x to it x times). Then run some version of “the first 
//program” using that square().

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

int square(int x) {

    int result = 0;
    for (int i = 1; i <= x; i++)
    {
        result += x;
    }

    return result;
}

int main()
{
    cout << "Number:" << '\t' << "Square:" << '\n';

    for (int i = 0; i < 100; i++)
    {
        cout << i << '\t' << square(i) << '\n';
    }

    return 0;
}

