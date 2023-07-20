// Exercise 4.cpp :
// Add to the program so that it can also convert from Kelvin to Celsius.

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

double ktoc(double k) // converts Kelvin to Celsius
{
    if (k < 0)
        throw BelowAbszero();
    else {
        double c = k - kelvinDiff;
        return c;
    }
}

int main()
{
    try
    {
        double temp{ 0 }; // declare input variable
        char tempUnit{ 'c' };

        cout << "Insert a temperature in Celsius or Kelvin to know its equivalent (e.g. 30 C or 20 K): ";

        if (cin >> temp >> tempUnit)
        {
            double result{ 0 };
            string resultUnit{ " Celsius " };

            switch (tempUnit)
            {
            case 'c':
            case 'C':
                result = ctok(temp); // convert temperature
                resultUnit = " Kelvin ";
                break;
            case 'k':
            case 'K':
                result = ktoc(temp); // convert temperature
                resultUnit = " Celsius ";
                break;
            default:
                break;
            }

            cout << temp << char(toupper(tempUnit)) << " = " << result << resultUnit << endl; // print out temperature
            return 0;
        }
        else
            throw BadInput();
    }
    catch (BelowAbszero) {
        cerr << "This temp is below absolute zero(-273.15 C or 0 K)..\n";
    }
    catch (BadInput) {
        cerr << "Input format should be: [Temp][Temp Unit] for example 30C or 20K.\n";
    }
}
