// 5.exercise.10.cpp
//
// Write a program that writes out the first so many values of the Fibonacci
// series, that is, the series that starts with 1 1 2 3 5 8 13 21 34. The next
// number of the series is the sum of the two previous ones. Find the largest
// Fibonacci nomber that fits in an int(44 nums fit).

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

//error messages
string badInputError{ "Please enter a number." };
string fewNumsError{ "That's too low! Please enter a bigger number." };
class overflowError {};
int overflowLimit{0};

vector<int> generateFibonacci(int howMany) {
    vector<int> fibonacciVec;
    int newElement{ 2 };

    //if user asks for 2 numbers or less:
    if (howMany <= 0)
        throw runtime_error(fewNumsError);
    else if (howMany == 1)
        fibonacciVec = { 1 };
    else if (howMany == 2)
        fibonacciVec = { 1, 1 };
    //if user asks for more than 2 nums:
    else {
        fibonacciVec = { 1, 1 };
        int startingCount = fibonacciVec.size();

        for (int i = 1; i <= (howMany - startingCount); i++) 
        {
            newElement = fibonacciVec[i] + fibonacciVec[i - 1];
            // if the new element doesn't fit as an int print the series and end the program:
            if (newElement < fibonacciVec[i - 1]) {
                overflowLimit = i;

                //print fibonacci series
                for (int f : fibonacciVec)
                    cout << f << " | ";

                throw overflowError{};
            }
            else
                fibonacciVec.push_back(newElement);
        }
    }

    return fibonacciVec;
}

int main()
{
    while (true) {

        try
        {
            int count{ 3 };

            cout << "How many Fibonacci numbers do you want to generate? ";
            if (cin >> count)
            {
                vector<int> fibonacciVec = generateFibonacci(count);

                cout << "\nThe Fibonacci series is:\n\n";
                //print fibonacci series
                for (int f : fibonacciVec)
                    cout << f << " | ";
            }
            else
                throw runtime_error(badInputError);
        }
        catch (runtime_error& e)
        {
            cout << "Runtime Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        //if the last element doesnt fit in int:
        catch (overflowError) {
            cout << "\n\nThe next Fibonacci value could not be stored on an int.";
            cout << "\nOnly the first " << overflowLimit << " numbers were printed.\n";
        }
        
        cout << "\n\n-----------------------------------------------------------------\n\n";
    }
    
    return 0;
}
