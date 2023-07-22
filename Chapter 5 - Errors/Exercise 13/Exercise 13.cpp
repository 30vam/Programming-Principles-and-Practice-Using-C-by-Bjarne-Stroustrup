// 5.exercise.13.cpp
//
// The program is a bit tedious because the answer is hard-coded into the
// program. Make a version where the user can play repeatedly (without stopping
// and restarting the program) and each game has a new set of four digits. You
// can get four random digits by calling the random number generator
// randint(10) from std_lib_facilities.h four times. You will note that if you
// run that program repeatedly, it will pick the same sequence of four digits
// each time you start the program. To avoid that, ask the user to enter
// a number (any number) and call seed_rand(n), also from std_lib_facilities.h,
// where n is the number the user entered before calling randint(10). Such n is
// called a seed, and different seeds give different sequences of random
// numbers.

//Almost the same as previous program

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <time.h>
using namespace std;

const string digitsString{ "0123456789" };
string correctInput{ "" };

vector<int> generateNums(int rangeStart, int rangeEnd, int howMany)
{
	vector<int> guessedNums{};
	int randomNum{ 0 };
	bool isRepeated{ false };
	//initialize srand
	srand(time(0));
	int i = 0;

	while (i < howMany) {

		isRepeated = false;
		randomNum = (rand() % (rangeEnd - rangeStart)) + rangeStart;

		//check if number is repeated or not
		for (int num : guessedNums)
		{
			if (num == randomNum) {
				isRepeated = true;
				break;
			}
		}
		//add the random number to the vector if it isn't repeated
		if (isRepeated == false)
		{
			guessedNums.push_back(randomNum);
			i++;
		}
	}
	//test
	cout << "(the answer : ";
	for (int i : guessedNums)
		cout << i ;
	cout << " )(this is a test, remove later) " << endl;
	return guessedNums;
}

void cleanInput(string message) {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << message;
}

bool repeatedDigits(string number) {

	bool isRepeated = false;

	for (int i = 1; i < number.length(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (number[i] == number[j]) {
				isRepeated = true;
				break;
			}
		}
	}
	return isRepeated;
}

void getInput(int digitCount) {

	string userInput{ "" };
	correctInput = { "" }; //clear previous input?..
	cin >> userInput;

	//check if the input string is only numbers
	for (char c : userInput) { //letters of user input
		bool isLetter{ true };

		for (char digit : digitsString) {
			if (c == digit) //are user input characters one of these? 0123456789
				isLetter = false;
		}

		if (isLetter) {
			cleanInput("Your input has other characters in it! Just enter 4 unique digits: ");
			getInput(digitCount);
		}
	}

	//check if input has 4 chars
	if (userInput.length() != digitCount) {
		cleanInput("The number should be 4 unique digits. Try again: ");
		getInput(digitCount);
	}

	//check if digits aren't repeated..
	if (repeatedDigits(userInput)) {
		cleanInput("The number should only have UNIQUE digits e.g. 1122 isn't allowed. Try again: ");
		getInput(digitCount);
	}

	correctInput = userInput;
}

string intToString(vector<int> numVec) {
	ostringstream d;
	string guessedNums{ "" };

	for (int i = 0; i < 4; i++)
		d << numVec[i];

	guessedNums += d.str();
	return guessedNums;
}

int main()
{
	while (true)
	{
		//guess 4 random numbers
		int attempts{ 1 }, digitsCount{ 4 }, bullCount{ 0 }, cowCount{ 0 };
		vector<int> guessedNumsVec = generateNums(0, 9, digitsCount);
		string guessedNums{ "" };

		//convert int vector of the goal number into string for comparing (in the loops below 
		//we cant compare int == string so it has to be a string)
		guessedNums = intToString(guessedNumsVec);

		cout << "Guess the " << digitsCount << " digit number in my head:\ndigits shouldn't be repeated, bull means you guessed a right digit in its\n";
		cout << "correct position, and cow means you guessed a correct digit, just not in the right position.\n\n";

		while (bullCount != digitsCount)
		{
			getInput(digitsCount);

			for (int i = 0; i < digitsCount; i++)
			{
				for (int j = 0; j < digitsCount; j++)
				{
					//test cout << guessedNums[i] << ", " << userGuess[j] << ", " << i << ", " << j << endl;
					if (guessedNums[i] == correctInput[j] && i == j) //bull
						bullCount++;

					if (guessedNums[i] == correctInput[j] && i != j) //cow
						cowCount++;
				}
			}

			if (bullCount == digitsCount)
				cout << "\nCongratz, you guess the correct number!.. It was " << correctInput << "\n\n";
			else {
				cout << bullCount << " bull " << cowCount << " cow. Guess again ( attemp no.  " << attempts << " ): \n";
				bullCount = 0;
				cowCount = 0;
				attempts++;
			}
		}

	}
	
	return 0;
}


