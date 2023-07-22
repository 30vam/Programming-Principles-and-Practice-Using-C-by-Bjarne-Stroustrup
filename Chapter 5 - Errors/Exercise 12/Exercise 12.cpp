// 5.exercise.12.cpp
//
// Implement a little guessing game called (for some obscure reason) "Bulls and
// Cows". The program has a vector of four different integers in the range 0 to
// 9 (e.g., 1234 but not 1122) and it is the user's task to discover those
// numbers by repeated guesses. Say the number to be guessed is 1234 andd the
// user guesses 1359; the response should be "1 bull and 1 cow" because the
// user got one digit (1) right and in the right position (a bull) and one
// digit (3) right but in the wrong position (a cow). The guessing continues
// until the user gets four bulls, that is, has the four digits correct and in
// the correct order.

//idk why, but the input check has problems rn and i hope i can figure out the why later and fix it
//this one is a little too messy

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
	for (int i : guessedNums)
		cout << "test " << i << " ";

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
	if (userInput.length () != digitCount) {
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

	return 0;
}


