// 4.exercise.17.cpp
//
// Write a program that finds the min, max and the mode of a sequence of
// strings.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<string> repeats{};
vector<int> repeatCount{};

void printVec(vector<string> vec, string text) {
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (vec.size() == 1)
            cout << text << " { " << vec[i] << " }.\n";
        else if (i == 0)
            cout << text << " { " << vec[i] << ", ";
        else if (i == vec.size() - 1)
            cout << vec[i] << " }.\n";
        else
            cout << vec[i] << ", ";
    }
}

void printVec(vector<int> vec, string text) {
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (vec.size() == 1)
            cout << text << " { " << vec[i] << " }.\n";
        else if (i == 0)
            cout << text << " { " << vec[i] << ", ";
        else if (i == vec.size() - 1)
            cout << vec[i] << " }.\n";
        else
            cout << vec[i] << ", ";
    }
}

void getMode(vector<string> vec) {
    int currentNumCount{ 1 };

    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] == vec[i - 1]) //add one to counter and add the num to repeats vector if the numbers are repeated
            currentNumCount++;
        //if the number repeat ends, add them to the result vectors
        else {
            repeats.push_back(vec[i - 1]); // i-1, because the repeat ended at the last number and we want the number that was repeated
            repeatCount.push_back(currentNumCount);
            currentNumCount = 1;
        }

        //if its the last number of the sequence (because it need special treatment):
        if (i == vec.size() - 1)
        {
            repeats.push_back(vec[i]);
            repeatCount.push_back(currentNumCount);
        }
    }
}

int main()
{
    vector<string> strings{};
    string a;
    int maxRepeat{ 1 };
    string mode{ "" };
    int modeCounter = 0;

    cout << "Enter a series of words to to sort in alphabetical order and find repeated words (Press Ctrl+Z to proceed):\n";

    while (cin >> a) //get user input until a string in entered.
        strings.push_back(a);

    sort(strings.begin(), strings.end());
    getMode(strings);

    //find the biggest number in each vector for results
    for (int i = 0; i < repeatCount.size(); i++)
    {
        int idx = repeatCount[i];

        if (idx >= maxRepeat)
        {
            maxRepeat = idx;
            mode = repeats[i];
        }
    }

    //show the results
    printVec(strings, "\nUser's Sequence: "); //print the user's number sequence
    printVec(repeats, "Repeated words: ");
    printVec(repeatCount, "Repeatition (in order): ");

    cout << "\nMode(s): ";
    for (int i = 0; i < repeatCount.size(); i++) //this loop is to check for multiple modes
    {
        if (repeatCount[i] == maxRepeat)
        {
            cout << repeats[i] << " | ";
            modeCounter++;
        }
    }

    cout << "\nNumber of modes found: " << modeCounter << endl;
    cout << "Repeatition of each mode: " << maxRepeat << endl;
    cout << "First word: " << strings[0] << endl;
    cout << "Last word: " << strings[strings.size() - 1] << endl;

    return 0;
}
