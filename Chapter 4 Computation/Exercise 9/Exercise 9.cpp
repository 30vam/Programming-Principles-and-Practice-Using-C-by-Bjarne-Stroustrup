// 4.exercise.09.cpp
//
// Try to calculate the number of rice grains that the inventor asked for in
// exercise 8 above. You'll find that the number is so large that it won't
// fit in an int or a double. Observe what happens when the number gets too
// large to represent exactly as an int and as a double. What is the largest
// number of squares for which you can calculate the exact number of grains
// (using an int)? What is the largest number of squares for which you can
// calculate the approximate number of grains (using a double)?

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const vector<double> grainsVec{10000000000000000000.0};

//function for calculating how many squares are needed for x amount of grains:
double calculateSquares(int maxSquares) {
    double totalGrain{ 0.0 };
    int square{ 0 };

    for (double currentGrain = 1; square < maxSquares; currentGrain *= 2)
    {
        square++;
        totalGrain += currentGrain;
        cout << "Current square: " << square << " | This square's grain: " << currentGrain << " | Total sum of grains: " << totalGrain << endl;
    }

    return totalGrain;
}

int main()
{
    int maxSquare{ 64 };
    cout << maxSquare << " squares adds up to " << calculateSquares(maxSquare) << " grains of rice.\n\n\n";

    return 0;
}