// Try This Page 146.cpp : Test this program with a variety of values. Print out the values of area1, area2,
//area3, and ratio.Insert more tests until all errors are caught.How do you
//know that you caught all errors ? This is not a trick question; in this particular
//example you can give a valid argument for having caught all errors.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


// ask user for a yes-or-no answer;
// return 'b' to indicate a bad answer (i.e., not yes or no)
char ask_user(string question)
{
    cout << question << "? (yes or no)\n";
    string answer = " ";
    cin >> answer;
    if (answer == "y" || answer == "yes") return 'y';
    if (answer == "n" || answer == "no") return 'n';
    return 'b'; // ‘b’ for “bad answer”
}
// calculate area of a rectangle;
// return –1 to indicate a bad argument
int area(int length, int width)
{
    if (length <= 0 || width <= 0) return –1;
    return length * width;
}

int main()
{
  
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
