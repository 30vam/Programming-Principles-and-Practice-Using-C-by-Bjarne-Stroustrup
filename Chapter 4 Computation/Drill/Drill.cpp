#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const double equalTolerence = 0.01; //The value used to determine if 2 numbers are almost equal

//function for finding the smaller num:
double findMax(double a, double b) {
    if (a > b) 
        return a;
    else 
        return b;
}

//function for finding the larger num:
double findMin(double a, double b) {
    if (a < b)
        return a;
    else
        return b;
}

//function for determining if the numbers are ALMOST equal:
bool isAlmostEqual(double a, double b) {
    if (abs(a - b) < equalTolerence)
        return true;
    else
        return false;
}

int main()
{
    //Variables:
    double a;
    double b;
    
    //Loop while input is int:
    while (cin >> a >> b)
    {
        //if nums are equal:
        if (a == b)
        {
            cout << "The numbers are equal." << '\n';
        }

        cout << "The smaller value is: " << findMin(a, b) << '\n' << "The larger value is: " << findMax(a, b) << '\n';

        if (isAlmostEqual(a, b))
            cout << "The values are almost equal." << '\n';
        
    }

    return 0;
}

