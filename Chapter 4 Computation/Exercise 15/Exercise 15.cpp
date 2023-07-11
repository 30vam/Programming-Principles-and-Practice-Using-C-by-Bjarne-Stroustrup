// 4.exercise.15.cpp
//
// Write a program that takes an input value n and then finds the first
// n primes.

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
    int n{ 1 };
    int max{ 100 };


    cout << "Starting from 2, how many prime numbers do you want to find? ";
    cin >> n;

    for (int i = 3; primes.size() < n; i++) //add primes to the vector until we find n primes
    {
        if (isPrime(i, primes))
            primes.push_back(i);
    }

    printVector(primes);
}
