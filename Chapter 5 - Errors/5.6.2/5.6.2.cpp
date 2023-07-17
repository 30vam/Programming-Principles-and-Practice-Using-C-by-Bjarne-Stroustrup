// 5.6.1 Bad Argument.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Bad_area { }; // a type specifically for reporting errors from area()
// calculate area of a rectangle;
// throw a Bad_area exception in case of a bad argument
int area(int length, int width)
{
    if (length <= 0 || width <= 0) throw Bad_area{};
    return length * width;
}

constexpr int frame_width = 2;
int framed_area(int x, int y) // calculate area within frame
{
    return area(x - frame_width, y - frame_width);
}

int main()
{
    try {
        vector<int> v; // a vector of ints
        for (int x; cin >> x; )
            v.push_back(x); // set values
        for (int i = 0; i <= v.size(); ++i) // print values
            cout << "v[" << i << "] == " << v[i] << '\n';
    }
    catch (out_of_range) {
        cerr << "Oops! Range error\n";
        return 1;
    }
    catch (...) { // catch all other exceptions
        cerr << "Exception: something went wrong\n";
        return 2;
    }
}

