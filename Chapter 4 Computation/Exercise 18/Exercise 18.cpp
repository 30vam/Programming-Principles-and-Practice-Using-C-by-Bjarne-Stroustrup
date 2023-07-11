// 4.exercise.18.cpp
//
// Write a program to solve quadratic equations. A quadratic equation is of the
// form:    ax^2 + bx + c = 0
// If you don't know the quadratic formula for solving such an expression, do
// some research. Remenber, researching how to solve a problem is often
// necessary before a programmer can teach the computer how to solve it. Use
// doubles for the user input for a, b and c. Since there are two solutions to
// a quadratic equation, output both x1 and x2.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
    while (true)
    {
        double a{ 0.0 };
        double b{ 0.0 };
        double c{ 0.0 };
        double x1{ 0.0 };
        double x2{ 0.0 };

        cout << "Enter a, b and c to solve the quadratic equation (ax^2 + bx + c = 0)\n" << "a = ";
        cin >> a;
        cout << "b = ";
        cin >> b;
        cout << "c = ";
        cin >> c;

        string equation{ to_string(a) + "x^2 + " + to_string(b) + "x + " + to_string(c) + " = 0 " };
        double delta = (b * b) - (4 * a * c);
        double sqrtDelta = sqrt(delta); // this is important, because otherwise sqrt() will turn the delta to int, and not double.

        //prints different forms of the equation.
        if (b == 0)
            equation = to_string(a) + "x^2 + " + to_string(c) + " = 0 ";
        else if (c == 0)
            equation = to_string(a) + "x^2 + " + to_string(b) + "x = 0 ";

        if (a == 0) //invalid equations not allowed
        {
            equation = to_string(b) + "x + " + to_string(c) + " = 0 ";
            cout << "Sorry, but " << equation << " is not a valid quadratic equation.\n";
        }
        //if the equation is valid find the answers:
        else {
            if (delta < 0)
                cout << "Sorry but the equation " << equation << " doesn't have a real answer.\n";
            else if (delta == 0) {
                x1 = ((-1) * b) / (2 * a);
                cout << equation << ", x = " << x1 << endl;
            }
            else {
                x1 = (-b + sqrtDelta) / (2 * a);
                x2 = (-b - sqrtDelta) / (2 * a);
                cout << equation << ", x1 = " << x1 << " and x2 = " << x2 << endl;
                cout << delta;
            }
        }
        
    }
    
}


