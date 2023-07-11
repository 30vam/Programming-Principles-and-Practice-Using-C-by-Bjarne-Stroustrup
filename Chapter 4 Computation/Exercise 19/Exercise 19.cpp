// 4.exercise.19.cpp
//
// Write a program where you first enter a set of name-and-value pairs, such as
// Joe 17 and Barbara 22. For each pair, add the name to a vector called names
// and the numbers to a vector called scores (in corresponding positions, so
// that if names[7]=="Joe" the scores[7]==17). Terminate input with NoName 0.
// Check that each name is unique and terminate with an error message if a name
// is entered twice. Write out all the (name, score) pairs (one per line).

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

	return 0;
}


