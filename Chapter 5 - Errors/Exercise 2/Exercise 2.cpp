// Exercise 2.cpp :
// The following program takes in a temperature value in Celsius and converts
//it to Kelvin.This code has many errors in it.Find the errors, list
//em, and correct the code.

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


