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
        int x = -1;
        int y = 2;
        int z = 4;
        // . . .
        int area1 = area(x, y);
        int area2 = framed_area(1, z);
        int area3 = framed_area(y, z);
        double ratio = area1 / area3;
    }

    catch (Bad_area) {
        cout << "Oops! bad arguments to area()\n";
    }
}

