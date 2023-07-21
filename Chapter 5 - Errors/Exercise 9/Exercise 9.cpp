// Exeercise 9
// Modify the program from exercise 8 to write an error if the result cannot be
// represented as an int

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
                for (size_t i = 0; i < n; i++) {
                    //the if throws as error if the result can't be represented with an int variable
                    if (numVec[i] >= 0 && sum + numVec[i] < sum)
                        throw runtime_error("The sum cannot be represented with an int type!");
                    if (numVec[i] < 0 && sum + numVec[i] > sum)
                        throw runtime_error("The sum cannot be represented with an int type!");
                    sum += numVec[i];
                }

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
