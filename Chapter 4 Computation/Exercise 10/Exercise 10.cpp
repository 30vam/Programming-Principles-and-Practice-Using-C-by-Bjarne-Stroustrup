// 4.exercise.10.cpp
//
// Write a program that plays the game "Rock, Paper, Scissors". 
// Use a switch-statement to solve this exercise. Also, the machine should
// give random answers (i.e., select the next rock, paper or scissors
// randomly). Real randomness is too hard to provide just now, so just build
// a vector with a sequence of values to be used as "the next value". If you
// build the vector into the program, it will always play the same game, so
// maybe you should let the user enter some values. Try variations to make it
// less easy for the user to guess which move the machine will make next.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int maxRounds{ 5 };
int playerScore{ 0 };
int computerScore{ 0 };
const vector<char> choices{'r', 'p', 's'};

//computer's random choice:
char computerChoice() {
int choiceCount = choices.size();
	int choice = rand() % (choiceCount); // selects a random number between 0-2

	return choices[choice];
}

//convert letter to words:
string letterToWord(char choice) {
	switch (choice)
	{
	case 'r':
		return "rock";
		break;
	case 'p':
		return "paper";
		break;
	case 's':
		return "scissors";
		break;
	}
}

//check if player's choice is legal
bool isChoiceLegal(char playerChoice) {
	for (char choice: choices)
	{
		if (choice == playerChoice)
			return 1;
	}

	return 0;
}

//switch cases for determining the winner..
string gameResult(char playerChoice, char computerChoice) {
	string result{""};

	switch (playerChoice) {
	case 'r':
		switch (computerChoice)
		{
		case 'p':
			result = "LOSE..."; computerScore++;
			break;
		case 's':
			result = "WIN!"; playerScore++;
			break;
		case 'r':
			result = "TIE";
			break;
		}
		break;
	case 'p':
		switch (computerChoice)
		{
		case 'r':
			result = "WIN!"; playerScore++;
			break;
		case 's':
			result = "LOSE..."; computerScore++;
			break;
		case 'p':
			result = "TIE";
			break;
		}
		break;
	case 's':
		switch (computerChoice)
		{
		case 'r':
			result = "LOSE..."; computerScore++;
			break;
		case 'p':
			result = "WIN!"; playerScore++;
			break;
		case 's':
			result = "TIE";
			break;
		}
		break;
	default:
		result = "ERROR";
		break;
	}

	return result;
}

//keep asking the user a question until a number is entered.
void askUser(string question) {
	int desiredRounds;
	cout << question;

	if (cin >> desiredRounds)
		maxRounds = desiredRounds;
	else //if another type of value besides int is entered:
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "ERROR: Please enter an integar number.\n";
		askUser(question);
	}
}

int main()
{
	string userInput{ "" };
	char playerChoice{ ' ' };
	int currentRound{ 1 };

	askUser("How many rounds of Rock, Paper and Scissors do you want to play?\n");

	while (currentRound <= maxRounds)
	{
		cout << "\t******  ROUND  " << currentRound << "  ******\n\nChoose Rock, paper or scissors (r for rock, p for paper and s for scissors): ";
		cin >> userInput;
		playerChoice = tolower(userInput[0]);

		if (!isChoiceLegal(playerChoice)) //the lower version of the input's 1st letter is considered the choice
			cout << "Please enter a valid choice.\n\n";
		else
		{
			char aiChoice = computerChoice();
			cout << gameResult(playerChoice, aiChoice);
			cout << "\nComputer chose " << letterToWord(aiChoice) << "\n\n";

			currentRound++;
		}
	}

	cout << "**************** FINAL RESULT ******************";
	cout << "\nYour wins: " << playerScore << "\tComputer wins: " << computerScore << "\n";
	if (computerScore > playerScore)
		cout << "You lost this time, how about another round?\n\n\n";
	else if (computerScore == playerScore)
		cout << "Close game..! It's a tie actually.\n\n\n";
	else
		cout << "Congratz, you won the game!\n\n\n";

	return 0;
}

