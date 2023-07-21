// 5.exercise.10.cpp
//
// Modify the program from exercise 8 to use double instead of int. Also, make
// a vector of doubles containing the N-1 differences between adjacent values
// and write out that vector of differences.

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void printNums(vector<double> vector, int howMany) {
    for (size_t i = 0; i < howMany; i++)
        cout << vector[i] << " ";
}

double calculateSum(vector<double> vector, int howMany) {
    double sum{ 0.0 };
    //check if n is bigger than the count of entered numbers
    if (howMany > vector.size())
        throw runtime_error("You need to enter more numbers.\n");

    //calculate the sum of first howMany numbers
    for (size_t i = 0; i < howMany; i++)
        sum += vector[i];

    return sum;
}

vector<double> calculateDiff(vector<double> vec, int howMany) {
    //pre-condition
    if (howMany < 2) 
        throw runtime_error("There aren't enough numbers to calculate the differences.\n");

    vector<double> diffVec;
    double diff{ 0.0 };

    for (size_t i = 1; i < howMany; i++)
    {
        diff = vec[i] - vec[i - 1];
        diffVec.push_back(diff);
    }

    return diffVec;
}

int main()
{
    while (true)
    {
        vector<double> numVec{};
        int n{ 0 };
        double num{0.0}, sum{ 0.0 };
        string exit{ "" };
        try
        {
            cout << "Please enter the number of values you want to sum: ";
            //check if n is valid
            if (cin >> n)
            {
                if (n < 0)
                    throw runtime_error("That's not possible. Enter a positive number.\n");
            }
            else
                throw runtime_error("Please enter a number.\n");

            cout << "Please enter some integers (press '|' to stop):";

            //get the number series and add it to a vector
            while (cin >> num)
                numVec.push_back(num);

            //when a number isnt entered
            cin.clear();
            cin >> exit;
            //if a value is entered that is not a number or |, throw an error
            if (exit != "|")
                throw runtime_error("\nPlease enter a valid input.\n");
            //if '|' is entered, continue with the program
            else {
                sum = calculateSum(numVec, n);
                calculateDiff(numVec, n);
                //print result
                cout << "\nThe sum of the first " << n << " numbers ( ";
                printNums(numVec, n);
                cout << ") is " << sum << ".\n\n";
                cout << "The differences between the first " << n << " numbers are :\n";
                printNums(calculateDiff(numVec, n), n-1);
                cout << "\n\n";
                cout << "----------------------------------------------------\n\n";
            }
        }
        catch (runtime_error& e)
        {
            cerr << "Runtime Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

}

