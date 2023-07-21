// 5.exercise.08.cpp
//
// Write a program that reads and stores a series of integers and then computes
// the sum of the first N integers. First ask for N, then read de values into
// a vector, then calculate the sum of the first N values. For example:
//
//  "Please enter the number of values you want to sum:"
//
//      3
//
//  "Please enter some integers (press '|' to stop):"
//
//      12 23 13 24 15 |
//
//  "The sum of the first 3 numbers ( 12 23 13 ) is 48."
//
// Handle all inputs. For example, make sure to give an error message if the
// user asks for a sum of more numbers than there are in the vector.

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void printNums(vector<int> vector, int howMany) {
    for (size_t i = 0; i < howMany; i++)
        cout << vector[i] << " ";
}

int main()
{
    while (true)
    {
        vector<int> numVec{};
        int num{ 0 }, n{ 0 }, sum{ 0 };
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
                //check if n is bigger than the count of entered numbers
                if (n > numVec.size())
                    throw runtime_error("You need to enter more numbers.\n");

                //calculate the sum of first N numbers
                for (size_t i = 0; i < n; i++)
                    sum += numVec[i];

                //print result
                cout << "\nThe sum of the first " << n << " numbers ( ";
                printNums(numVec, n);
                cout << ") is " << sum << ".\n\n";
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

