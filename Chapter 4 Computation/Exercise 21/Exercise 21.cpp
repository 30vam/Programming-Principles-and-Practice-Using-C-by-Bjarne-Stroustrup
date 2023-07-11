// 4.exercise.21.cpp
//
// Modify the program from exercise 19 so that when you enter an integer, the
// program will output all the names with that score or score not found.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool repeatedName(string name, vector<string> names) {
	for (string n : names)
	{
		if (n == name)
			return true;
	}

	return false;
}

int main()
{
	cout << "Enter pairs of names and numbers, there should be a space between the name\nand the number, for example Joe 17. (Type NoName 0 to Terminate)\n";
	string name;
	int num;
	vector<string> names;
	vector<int> numbers;

	//get the pairs from user
	while ((cin >> name >> num) && name != "NoName" && num != 0)
	{
		if (repeatedName(name, names))
		{
			cout << "Error: You can't enter the same name twice.\n";
			return 1; //error
		}
		else
		{
			names.push_back(name);
			numbers.push_back(num);
		}
	}

	//print all names and values
	cout << "\n\n*********  PAIRS  ***********\n";
	for (size_t i = 0; i < names.size(); i++)
		cout << names[i] << " : " << numbers[i] << endl;

	//returns the corresponding number for an entered name
	cout << "\nEnter a score to see who it belongs to: ";
	bool scoreFound{ false };

	while (cin >> num)
	{
		scoreFound = false;

		for (size_t i = 0; i < numbers.size(); i++)
		{
			if (num == numbers[i]) {
				scoreFound = true;
				cout << "The score " << num << " belongs to: " << names[i] << endl;
			}
		}

		if (!scoreFound)
			cout << "Please enter a valid score." << endl;
	}



	return 0;
}
