// store input temps into a vector and compute mean(average) and median(middle) temperatures

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
    vector<double> temps;
    for (double temp; cin >> temp;)
    {
        //put temp into vector
        temps.push_back(temp);
    }

    // compute mean temperature
    double tempsum = 0;
    for (double temp: temps)
        tempsum += temp;

    cout << "Average Temperature: " << tempsum/temps.size() << '\n';

    // compute median temperature:
    sort(temps.begin(), temps.end());
    cout << "Median Temperature: " << temps[temps.size()/2] << '\n';
}


