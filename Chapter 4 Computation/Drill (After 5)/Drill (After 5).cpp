#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const double cmToMetersRatio = 100;
const double inToMetersRatio = 39.37;
const double ftToMetersRatio = 3.28;
const double equalTolerence = 0.01; //The value used to determine if 2 numbers are almost equal
const vector<string> legalUnits = { "cm", "m", "in", "ft" };

//check if unit is legal or not:
bool isUnitLegal(string unit){
    for (string legalUnit: legalUnits)
    {
        if (unit == legalUnit)
            return true;
    }

    return false;
}

//function for printing legal units:
void printUnits() {
    for (string unit : legalUnits)
        cout << unit << endl;
}

//function for printing doubles in a vector;
void printDoubles(vector<double> vec) {
    for (double num: vec)
        cout << num << endl;
}

//function for converting values to meters:
double convertToMeters(double value, string unit) {
    double meters = 0;

    if (unit == "cm")
        meters = value/cmToMetersRatio;
    else if (unit == "m")
        meters = value;
    else if (unit == "in")
        meters = value/inToMetersRatio;
    else if (unit == "ft")
        meters = value/ftToMetersRatio;

    return meters;
}

int main()
{
    //intro
    cout << "Please enter a value and one the acceptable units:\n";
    printUnits();
    cout << '\n';

    //Variables:
    double a = 0;
    string unit = "";
    double meters = 0;

    double smallestNum = a;
    double largestNum = a;
    double sum = 0;
    double count = 0;

    vector<double> metersVec;

    //Loop while input is int:
    while (cin >> a >> unit)
    {
        //check if the unit is legal
        if (!isUnitLegal(unit))
        {
            cout << "Enter an acceptable unit: cm, m, in, ft.\n";
            break;
        }

        meters = convertToMeters(a, unit);
        //on 1st loop, assign the value to largest and smallest num variables
        if (count == 0)
        {
            largestNum = meters;
            smallestNum = meters;
        }
        else if (meters > largestNum)
            largestNum = meters;

        else if (meters < smallestNum)
            smallestNum = meters;

        metersVec.push_back(meters); //add the value in meters to the vector
        sum += meters; //increase the sum of values in meters
        count++; //update the number of entered values
    }
    sort(metersVec.begin(), metersVec.end()); //sort the values in increasing order

    //print out all the results after the loop ends
    cout << "Smallest value: " << smallestNum << " meters\n";
    cout << "Largest value: " << largestNum << " meters\n";
    cout << "Number of values: " << count << " meters\n";
    cout << "Total sum: " << sum << " meters\n";
    cout << "Values sorted (converted to meters):\n";
    printDoubles(metersVec);
    cout << '\n';

    return 0;
}

