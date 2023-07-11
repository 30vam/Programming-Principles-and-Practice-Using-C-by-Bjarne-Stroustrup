/*7. Modify the “mini calculator” from exercise 5 to accept (just) single-digit
numbers written as either digits or spelled out.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const vector<string> spelledDigits{ "zero", "one", "two", "three",
"four", "five", "six",
"seven", "eight", "nine" };

const vector<char> operators{ '-', '+', '*', '/' };

//lists out all the available operations:
void printOperations() {
	for (char operation : operators)
		cout << operation << "\n";
}

//calculator function:
double calculate(double a, double b, char operation) {
	double result = 0;

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
	return result;
}

//converts ciphers to number:
int getNumber() {
	int number = 0;
	string word = "";
	int result{-1};

	if (cin >> number)
		result = number;
	else
	{
		if ()
		// Clear cin state to be able to re-read
		cin.clear();
		//It's not an integer so we read it as string
		cin >> word;
		// cheat, cheat, cheat. size_t is an integer unsigned type for "sizes",
		// so I use it here as gcc with -Wall warnings about comparing signed
		// and unsigned integer expressions if I define i as int.
		for (size_t i = 0; i < spelledDigits.size(); ++i)
			if (spelledDigits[i] == word) result = i;
		if (result == -1) {
			// Clear error and discard the rest of the input
			cout << "The name <" << word << "> do not correspond to any single digit number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Try again:\n";
		}
			
	}

	return result;
			
}

int main()
{
	int a{ 0 };
	int b{ 0 };
	char operation{' '};

	cout << "Enter 2 numbers, and one of the following operations: (0-9 only)\n";
	printOperations();

	while (true)
	{
		a = getNumber();
		cin >> operation;
		b = getNumber();
		
		
		cout << a << " " << operation << " " << b << " = " << calculate(a, b, operation) << endl;
	}

	return 0;
}


