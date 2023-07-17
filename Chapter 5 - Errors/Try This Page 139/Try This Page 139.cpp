// Try This Page 139.cpp : Try to compile those examples and see how the compiler responds. Try
//thinking of a few more errors yourself, and try those.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int area(int length, int width); // calculate area of a rectangle

int main()
{
    int x0 = arena(7); // error: undeclared function
    int x1 = area(7); // error: wrong number of arguments
    int x2 = area("seven", 2); // error: 1st argument has a wrong type
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
