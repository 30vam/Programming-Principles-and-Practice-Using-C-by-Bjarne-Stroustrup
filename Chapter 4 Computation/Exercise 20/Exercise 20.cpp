// 4.exercise.20.cpp
//
// Modify the program from exercise 19 so that when you enter a name, the
// program will output the corresponding score or 'name not found'.

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
	cout << "\nEnter a name to see its corresponing value: ";
	bool nameFound{ false };

	while (cin >> name)
	{
		nameFound = false;

		for (size_t i = 0; i < names.size(); i++)
		{
			if (name == names[i]) {
				nameFound = true;
				cout << "Value of the name " << name << " is: " << numbers[i] << endl;
			}
		}

		if (!nameFound)
			cout << "Please enter a valid name." << endl;
	}

	return 0;
}


