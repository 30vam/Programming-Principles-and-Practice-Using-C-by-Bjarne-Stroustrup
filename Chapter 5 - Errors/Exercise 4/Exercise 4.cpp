// Exercise 4.cpp :
// Do exercise 3 again, but this time handle the error inside ctok().

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const double kelvinDiff{ 273.15 };
//Error classes
class BelowAbszero {};
class BadInput {};

double ctok(double c) // converts Celsius to Kelvin
{
    if (c < -kelvinDiff)
        throw BelowAbszero();
    else {
        double k = c + kelvinDiff;
        return k;
    }
}

int main()
{
    try
    {
        double c{ 0 }; // declare input variable
        cout << "Insert a temperature in Celsius to know the Kelvin equivalent: ";

        if (cin >> c)
        {
            double k = ctok(c); // convert temperature

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
