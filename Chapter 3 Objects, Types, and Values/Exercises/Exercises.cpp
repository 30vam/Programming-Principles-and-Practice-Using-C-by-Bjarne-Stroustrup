#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
inline void keep_window_open() { char ch; cin >> ch; }


int main()
{
    //2
    /*double miles;
    double kilometers;

    cout << "Enter the distance in miles:\n";
    cin >> miles;
    cout << miles << " equals " << miles * 1.609 << " Kilometers";*/

    //3
    /*int double = 0;
    double _double;
    double #saf;
    int This;
    int normalInt;
    string 6ixty;*/

    //4
    /*int val1 = 0;
    int val2 = 0;
    int smallerNum = 0;
    int largerNum = 0;

    cout << "Enter 2 numbers:\n";
    cin >> val1 >> val2;

    //comparison
    if (val1 == val2)
        cout << "the numbers are equal.\n";
    else if (val1 > val2)
    {
        smallerNum = val2;
        largerNum = val1;
        cout << "Smaller number: " << val2 << endl;
        cout << "Larger number: " << val1 << endl;
    }
    else
    {
        smallerNum = val1;
        largerNum = val2;
        cout << "Smaller number: " << val1 << endl;
        cout << "Larger number: " << val2 << endl;
    }
    //Sum
    cout << "Sum: " << val1 + val2 << endl;
    //Difference
    cout << "Difference: " << largerNum - smallerNum << endl;
    //Product
    cout << "Product: " << val1 * val2 << endl;
    //ratio
    cout << "Ratio: " << val1 / val2 << endl;*/

    //5
    /*double val1 = 0;
    double val2 = 0;
    double smallerNum = 0;
    double largerNum = 0;

    cout << "Enter 2 floating point numbers:\n";
    cin >> val1 >> val2;

    //comparison
    if (val1 == val2)
        cout << "the numbers are equal.\n";
    else if (val1 > val2)
    {
        smallerNum = val2;
        largerNum = val1;
        cout << "Smaller number: " << val2 << endl;
        cout << "Larger number: " << val1 << endl;
    }
    else
    {
        smallerNum = val1;
        largerNum = val2;
        cout << "Smaller number: " << val1 << endl;
        cout << "Larger number: " << val2 << endl;
    }
    //Sum
    cout << "Sum: " << val1 + val2 << endl;
    //Difference
    cout << "Difference: " << largerNum - smallerNum << endl;
    //Product
    cout << "Product: " << val1 * val2 << endl;
    //ratio
    cout << "Ratio: " << val1 / val2 << endl;*/

    //6
    /*int num1, num2, num3;
    int smallest, middle, largest;

    cout << "Enter 3 integers:\n";
    cin >> num1 >> num2 >> num3;

    if (num1 < num2)
    {
        smallest = num1;
        largest = num2;
    }

    else
    {
        smallest = num2;
        largest = num1;
    }

    ////if third number is the smallest
    if (num3 < smallest)
    {
        middle = smallest;
        smallest = num3;
        
    }

    //if third number is middle
    else if (num3 >= smallest && num3 <= largest)
    {
        middle = num3;
    }

    //if third number is the largest
    else if (num3 > largest)
    {
        middle = largest;
        largest = num3;
    }

    cout << smallest << ", " << middle << ", " << largest << endl;*/

    //7
    //sorts words in alphabetical order
    /*string word1, word2, word3;
    string smallest, middle, largest;

    cout << "Enter 3 integers:\n";
    cin >> word1 >> word2 >> word3;

    if (word1 < word2)
    {
        smallest = word1;
        largest = word2;
    }

    else
    {
        smallest = word2;
        largest = word1;
    }

    //if third number is the smallest
    if (word3 < smallest)
    {
        middle = smallest;
        smallest = word3;
        
    }

    //if third number is middle
    else if (word3 >= smallest && word3 <= largest)
    {
        middle = word3;
    }

    //if third number is the largest
    else if (word3 > largest)
    {
        middle = largest;
        largest = word3;
    }

    cout << smallest << ", " << middle << ", " << largest << endl;*/

    //8
    /*int number;
    cout << "Enter a number for the program to determine if it's odd or even:\n";
    cin >> number;

    if (number % 2 == 0)
        cout << number << " is even." << endl;
    else
        cout << number << " is odd." << endl;*/
    
    //9

    /*cout << "Enter a number from 0 to 4 as a string, e.g. 'zero' (followed by 'Enter')\n";
    string val;
    cin >> val;

    int digit = -1;
    if ("zero" == val)
    {
        digit = 0;
    }
    else if ("one" == val)
    {
        digit = 1;
    }
    else if ("two" == val)
    {
        digit = 2;
    }
    else if ("three" == val)
    {
        digit = 3;
    }
    else if ("four" == val)
    {
        digit = 4;
    }

    if (-1 != digit)
    {
        cout << "The spelled-out number " << val << " corresponds to " << digit << ".\n";
    }
    else
    {
        cout << "not a number I know\n";
    }*/

    //10
    /*double operand1, operand2, resault = 0;
    string operation;

    cout << "Please enter the operation, and the 2 operands in order:\n";
    cin >> operation >> operand1 >> operand2;

    if (operation == "+" || operation == "plus")
    resault = operand1 + operand2;

    else if (operation == "-" || operation == "minus")
        resault = operand1 - operand2;

    else if (operation == "*" || operation == "mul")
        resault = operand1 * operand2;

    else if (operation == "/" || operation == "div")
        resault = operand1 / operand2;

    cout << operand1 << operation << operand2 << " = " << resault;*/

    //11
    /*int pennies, nickels, dimes, quarters, halfDollars, oneDollars;
    double sum_cents = 0, sum_dollars = 0;

    cout << "How many pennies do you have?\n";
    cin >> pennies;

    cout << "How many nickels do you have?\n";
    cin >> nickels;

    cout << "How many dimes do you have?\n";
    cin >> dimes;

    cout << "How many quarters do you have?\n";
    cin >> quarters;

    cout << "How many half-dollars do you have?\n";
    cin >> halfDollars;

    cout << "How many one-dollars do you have?\n";
    cin >> oneDollars;

    sum_cents = oneDollars * 100 + halfDollars * 50 + quarters * 25 + dimes * 10 + nickels * 5 + pennies;
    sum_dollars = sum_cents / 100;

    cout << "You have " << pennies << " pennies.\n";
    cout << "You have " << nickels << " nickels.\n";
    cout << "You have " << dimes << " dimes.\n";
    cout << "You have " << quarters << " quarters.\n";
    cout << "You have " << halfDollars << " half-dollars.\n";
    cout << "You have " << oneDollars << " one-dollars.\n";

    cout << "The value of all of your coins is " << sum_cents << " cents, which also equals to " << sum_dollars << " dollars.";*/
}

