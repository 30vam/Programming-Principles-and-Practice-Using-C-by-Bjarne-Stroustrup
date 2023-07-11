// 4.exercise.13.cpp
//
// Create a program to find all the prime numbers between 1 and 100. There is
// a classic method for doing this, called "Sieve of Eratosthenes". If you
// don't know that method, get on the web and look it up. Write your program
// using this method.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> markedNums{};
vector<int> primeNums{};

//mark all the proper multiples of the starting num and add them to a vector.
void markMultiples(int startingNum, int max) {
    for (int i = startingNum + startingNum; i <= max; i += startingNum) //we dont want to mark the prime number itself
        markedNums.push_back(i);
}

//check if number is marked
bool isMarked(int num) {
    for (int markedNum : markedNums)
    {
        if (num == markedNum)
            return true;
    }

    return false;
}

//print nums in a vector
void printVec(vector<int> vec){
    int vecSize = vec.size();

    for (int i = 0; i < vecSize; i++)
    {
        if (i == vecSize - 1)
            cout << vec[i] << ".\n";
        else
            cout << vec[i] << ", ";
    }
}

int main()
{
    int max{ 100 };
    int startingNum{ 2 }; //we start marking numbers that are devisible by this number.

    cout << "This program uses the Sieve of Eratosthenes algorithm to find prime numbers smaller than the number you enter.\nEnter a number: ";
    cin >> max;

    while (startingNum < max)
    {
        primeNums.push_back(startingNum); //add the unmarked number to prime numbers
        markMultiples(startingNum, max);
        
        do { startingNum++; } while (isMarked(startingNum));//finds the next unmarked number and assigns startingNum to it
    }
   
    printVec(primeNums); //print the prime nums
}


