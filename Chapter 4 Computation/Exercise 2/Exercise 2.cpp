/*2. If we define the median of a sequence as “a number so that exactly as many elements come before
it in the sequence as come after it, ” fix the program in §4.6.3 so that it always prints out a
median.Hint: A median need not be an element of the sequence.*/


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
    double median = 0;

    for (double temp; cin >> temp;)
    {
        //put temp into vector
        temps.push_back(temp);
    }

    // compute mean temperature
    double tempsum = 0;
    for (double temp : temps)
        tempsum += temp;

    cout << "Average Temperature: " << tempsum / temps.size() << '\n';

    // compute median temperature:
    sort(temps.begin(), temps.end());
    int vecSize = temps.size();

    //if the vector size is odd:
    if (vecSize % 2 != 0)
        median = temps[vecSize / 2];
    else //else if the size is evenL
        median = (temps[vecSize / 2] + temps[vecSize/2 - 1])/2; // -1, because the index starts from 0, but vecsize starts from 1.

    cout << "Median Temperature: " << median << '\n';
}

