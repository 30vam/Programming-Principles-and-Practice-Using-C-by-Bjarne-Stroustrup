// Exercise 2.cpp :
/* Absolute zero is the lowest temperature that can be reached; it is –273.15°C,
or 0K.The above program, even when corrected, will produce erroneous
results when given a temperature below this.Place a check in the
main program that will produce an error if a temperature is given below
–273.15°C.*/

//This program is the same as exercise 2

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const double kelvinDiff{ 273.15 };

double ctok(double c) // converts Celsius to Kelvin
{
    double k = c + kelvinDiff;
    return k;
}

//Error classes
class BelowAbszero {};
class BadInput {};

int main()
{
    try
    {
        double c{ 0 }; // declare input variable
        cout << "Insert a temperature in Celsius to know the Kelvin equivalent: ";

        if (cin >> c)
        {
            double k = ctok(c); // convert temperature

            if (k < 0) //check for temps below absolute zero
                throw BelowAbszero();

            cout << k << '/n'; // print out temperature
        }
        else
            throw BadInput();

        return 0;
    }
    catch (BelowAbszero) {
        cerr << "This temp is below absolute zero(-273.15 C)..\n";
    }

    catch (BadInput) {
        cerr << "Please enter a number.\n";
    }
}


