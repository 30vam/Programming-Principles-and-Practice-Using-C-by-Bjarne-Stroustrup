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
    double cash, resault = 0;
    char unit = ' ';

    constexpr double exchangeRateYen = 0.0076;
    constexpr double exchangeRateKroner = 0.097;
    constexpr double exchangeRatePound = 1.23;

    cout << "Please enter the amount of cash along with its currency (y for yen, k for kroner, and p for pound):\n";
    cin >> cash >> unit;

    if (unit == 'y')
        resault = cash * exchangeRateYen;
    else if (unit == 'k')
        resault = cash * exchangeRateKroner;
    else if (unit == 'p')
        resault = cash * exchangeRatePound;
    else
        cout << "Sorry, I don't know a unit called '" << unit << "'\n";

    cout << cash << unit << " = " << resault << " dollars.";
}

