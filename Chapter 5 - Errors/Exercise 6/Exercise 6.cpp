// Exercise 6.cpp :
// 
// Write a program that converts from Celsius to Fahrenheit and from Fahrenheit
//to Celsius(formula in §4.3.3).Use estimation(§5.8) to see if your
//results are plausible.

//I just expanded the last exercise

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const double kelvinDiff{ 273.15 };
const vector<string> unitVec{"c", "celsius", "k", "kelvin", "f", "fahrenheit"};
const string badUnitError{"\nThis temp unit isn't available! Use Celsius, Kelvin or Fahrenheit.\n"};
const string belowAbsZero{ "\nThis temp is below absolute zero ( -273.15C or 0K)..\n" };
const string badInput{ "\nInput format should be: [Temp][Temp Unit] e.g. : 30C or 20 K.\n" };

double convertCelsiusTo(double temp, char outputUnit) // converts Celsius to other units
{
    double result{ 0 };

    switch (outputUnit) //different fomulars for kelvin and fahrenheit to Celsius
    {
    case 'c':
        result = temp;
        break;
    case 'k':
        result = temp + kelvinDiff;
        break;
    case 'f':
        result = (temp * 1.8) + 32;
        break;
    default: // in case the unit is undefined
        throw runtime_error(badUnitError);
        break;
    }

    return result;
}

double toCelsius(double temp, char inputUnit) // converts temps to Celsius
{
    double c{ 0 };

    switch (inputUnit) //different fomulars for kelvin and fahrenheit to Celsius
    {
    case 'c':
        c = temp;
        break;
    case 'k':
        c = temp - kelvinDiff;
        break;
    case 'f':
        c = (temp - 32) * (5.0/9.0);
        break;
    default: // in case the unit is undefined
        throw runtime_error(badUnitError);
        break;
    }
    
    if (c < -kelvinDiff) //throw an error if the temp is below Absolute Zero
        throw runtime_error(belowAbsZero);
    else 
        return c;
}

bool isUnitLegal(string unit) {
    for (string u : unitVec)
    {
        if (unit == u)
            return true;
    }

    throw runtime_error(badUnitError); //if the unit isn't legal
    return false;
}

//converts unit from char to string: K to Kelvin, F to Fahrenheit, etc.
string charToString(char unitChar) {
    string result{ "" };

    switch (unitChar){
    case 'c':
        result = " Celsius ";
        break;
    case 'k':
        result = " Kelvin ";
        break;
    case 'f':
        result = " Fahrenheit ";
        break;
    default: // in case the unit is undefined
        throw runtime_error(badUnitError);
        break;
    }

    return result;
}

int main()
{
    double temp{ 0 }; // declare input variable
    double output{ 0 };
    double celsius{ 0 };
    string outputUnit{ "c" };
    string inputUnit{ "c" };

    while (true)
    {
        try
        {
            cout << "            ************************* UNIT CONVERSION *****************************\n\n";
            cout << "Insert temperature in Celsius, Kelvin or Fahrenheit (e.g. 30 C or 20Fahrenheit) : ";

            if (cin >> temp >> inputUnit)
            {
                transform(inputUnit.begin(), inputUnit.end(), inputUnit.begin(), ::tolower); //change unit string to lower characters
                //Check if the user entered a correct string as unit or not
                isUnitLegal(inputUnit);

                celsius = toCelsius(temp, inputUnit[0]);

                cout << "Now insert your desired unit to convert to (Celsius, Kelvin or Fahrenheit): ";
                //check if input is correct
                if (cin >> outputUnit) {
                    transform(outputUnit.begin(), outputUnit.end(), outputUnit.begin(), ::tolower); //change unit string to lower characters
                    isUnitLegal(outputUnit);

                    output = convertCelsiusTo(celsius, outputUnit[0]);

                    // print out temperature
                    cout << "\n\t\t\t" << temp << charToString(inputUnit[0]) << "= " << output << charToString(outputUnit[0]) << endl << endl; }
                else //throw an error if a number is entered instead of unit
                    throw runtime_error(badInput);
                
            }
            //if intput isn't in the form of number >> string then ignore input and throw an error
            else
                throw runtime_error(badInput);
        }
        catch (runtime_error& e) {
            cerr << "\nRuntime Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        catch (exception& e) {
            cerr << "\nException: " << e.what() << endl;
        }
        catch (...) {
            cerr << "\nUnknown error..\n";
        }
    }

    return 0;
}
