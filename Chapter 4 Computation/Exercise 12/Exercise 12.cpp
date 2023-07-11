// 4.exercise.12.cpp
//
// Modify the program described in the previous exercise to take an input value
// max and then find all the prime numbers from 1 to max.

//literally the same program

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> primes{ 2 }; //starting the vec with 2 as the first prime.

bool isPrime(int num, vector<int> primeVec) {
    int i{ 0 }; //starts from 0 because it goes through every index of vector

    while (i < primeVec.size()) //in this method, we only check if the number is devidable by smaller PRIME numbers, no need to check for all the smaller numbers.
    {
        if (num % primeVec[i] == 0)
            return false;
        i++;
    }

    return true;
}

void printVector(vector<int> vec) {
    for (int prime : vec)
        cout << prime << endl;
}

int main()
{

    int max{ 100 };

    cout << "This program helps you find all the prime numbers smaller than the number you enter.\nEnter a number: ";
    cin >> max;

    for (int i = 3; i < max; i++) //add primes between 1 and max to the vector
    {
        if (isPrime(i, primes))
            primes.push_back(i);
    }

    printVector(primes);
}


