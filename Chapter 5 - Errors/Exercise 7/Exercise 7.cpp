// 5.exercise.07.cpp
//
// Quadratic equations are of the form
//
//      a·x² + b·x + c = 0
//
// To solve these, one uses the quadratic formula:
//
//      x = (-b ± sqrt(b² - 4ac)) / 2a
//
// There is a problem, though: if b² - 4ac is less than zero, then it will
// fail. Write a program that calculate x for a quadratic equation. Create
// a function that prints out the roots of a quadratic equation, given a, b, c.
// When the program detects an equation with no real roots, have it print out
// a message. How do you know that your results are plausible? Can you check
// that they are correct?

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const string invalidEquationError{ "Sorry, but this is not a  valid quadratic equation: " };
const string noAnswerError{"This equation doesn't have a real answer: "};
const string badInputError{ "Please enter a, b and c as numbers only.\n" };

string doubleToString(double input) {
    ostringstream stream;
    stream << input;
    string result = stream.str();

    return result;
}

void solveEquation(double a, double b, double c) {

    double x1{ 0.0 };
    double x2{ 0.0 };

    string equation{ doubleToString(a) + "x^2 + " + doubleToString(b) + "x + " + doubleToString(c) + " = 0 " };
    double delta = (b * b) - (4 * a * c);
    double sqrtDelta = sqrt(delta); // this is important, because otherwise sqrt() will turn the delta to int, and not double.

    //prints different forms of the equation.
    if (b == 0)
        equation = doubleToString(a) + "x^2 + " + doubleToString(c) + " = 0 ";
    else if (c == 0)
        equation = doubleToString(a) + "x^2 + " + doubleToString(b) + "x = 0 ";

    if (a == 0) //invalid equations not allowed
    {
        equation = doubleToString(b) + "x + " + doubleToString(c) + " = 0 ";
        throw runtime_error(invalidEquationError + equation + "\n");
    }
    //if the equation is valid find the answers:
    else {
        if (delta < 0)
            throw runtime_error(noAnswerError + equation + "\n");
        else if (delta == 0) {
            x1 = ((-1) * b) / (2 * a);
            cout << equation << ", x = " << x1 << endl << endl;
        }
        else {
            x1 = (-b + sqrtDelta) / (2 * a);
            x2 = (-b - sqrtDelta) / (2 * a);
            cout << equation << ", x1 = " << x1 << " and x2 = " << x2 << endl << endl;
        }
    }
}

double getInput() {
    double input{ 0 };

    if (cin >> input)
        return input;
    else
        throw runtime_error(badInputError);
}

int main()
{
    double a{ 0.0 };
    double b{ 0.0 };
    double c{ 0.0 };


    while (true)
    {
        cout << "******************** Quadratic Equation Solver *********************\n\n";
        cout << "Enter a, b and c to solve the quadratic equation (ax^2 + bx + c = 0)\n" << "a = ";

        try
        {
            a = getInput();
            cout << "b = ";
            b = getInput();
            cout << "c = ";
            c = getInput();

            solveEquation(a, b, c);
        }
        catch (runtime_error& e)
        {
            cerr << "Runtime Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    }

    return 0;

}


