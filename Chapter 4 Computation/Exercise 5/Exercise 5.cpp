/*5. Write a program that performs as a very simple calculator.Your calculator
should be able to handle the four basic math operations — add, subtract,
multiply, and divide — on two input values.Your program should prompt
the user to enter three arguments : two double values and a character to
represent an operation.If the entry arguments are 35.6, 24.1, and '+', the
program output should be The sum of 35.6 and 24.1 is 59.7.In Chapter 6
we look at a much more sophisticated simple calculator.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const vector<char> operators{'-', '+', '*', '/'};

void printOperations() {
    for (char operation : operators)
        cout << operation << "\n";
}

int main()
{
    double a{ 0 };
    double b{ 0 };
    char operation = ' ';
    double result = 0;

    cout << "Enter 2 numbers, and one of the following operations:\n";
    printOperations();

    cin >> a >> b >> operation;

    switch (operation)
    {
    case '-':
        result = a - b;
        break;
    case '+':
        result = a + b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    default:
        cout << "Enter a valid operator.\n";
        break;
    }

    cout << a << operation << b << "=" << result << endl;

    return 0;
}


