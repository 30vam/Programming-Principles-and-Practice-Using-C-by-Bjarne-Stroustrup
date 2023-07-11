/*6. Make a vector holding the ten string values "zero", "one", . . . "nine".
Use that in a program that converts a digit to its corresponding
spelled - out value; e.g., the input 7 gives the output seven.Have the same
program, using the same input loop, convert spelled-out numbers into
their digit form; e.g., the input seven gives the output 7.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const vector<string> spelledDigits{"zero", "one", "two", "three",
"four", "five", "six",
"seven", "eight", "nine"};

//function that checks if the word entered exists in spelledDigits vector.
int convertWord(string word) {

	for (int i = 0; i < spelledDigits.size(); i++)
	{
		if (spelledDigits[i] == word)
			return i;
	}
	cout << "Enter a valid number to conver (0-9).\n"; //only prints if numbers arent in the range.
	return 0;
}

int main()
{
	int number{ 0 };
	string word{ "" };

    cout << "Write a number between 0-9 for conversion:\n";

	while (true)
	{
		if (cin >> number)
		{
			if (number >= 0 && number <= 9)
				cout << spelledDigits[number] << endl;
			else
				cout << "only 1 digit numbers are allowed\n";
		}

		else
		{
			cin.clear(); // The cheat. clear() return us to the begining of the input
			cin >> word;
			cout << convertWord(word) << endl;
		}
	}
}


