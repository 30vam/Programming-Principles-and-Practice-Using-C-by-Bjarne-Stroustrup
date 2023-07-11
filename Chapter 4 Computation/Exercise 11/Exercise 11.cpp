/*11. Create a program to find all the prime numbers between 1 and 100. One
way to do this is to write a function that will check if a number is prime
(i.e., see if the number can be divided by a prime number smaller than
    itself) using a vector of primes in order(so that if the vector is called
        primes, primes[0] == 2, primes[1] == 3, primes[2] == 5, etc.).Then write a
    loop that goes from 1 to 100, checks each number to see if it is a prime,
    and stores each prime found in a vector.Write another loop that lists the
    primes you found.You might check your result by comparing your vector
    of prime numbers with primes.Consider 2 the first prime.*/

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


