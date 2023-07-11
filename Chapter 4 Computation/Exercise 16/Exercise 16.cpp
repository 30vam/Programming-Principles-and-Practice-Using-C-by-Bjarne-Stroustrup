// 4.exercise.16.cpp
//
// In the drill, you wrote a program that, given a series of numbers, found the
// max and min of that series. The number that appears the most times in
// a sequence is called the mode. Create a program that finds the mode of a set
// of positive integers.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> repeats{};
vector<int> repeatCount{};

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

void getMode(vector<int> vec) {
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
    vector<int> nums{};
    int a;
    int maxRepeat{ 1 };
    int mode{ 0 };
    int modeCounter = 0;

    cout << "Enter a series of numbers to find the modes (Enter any other character for results): ";

    while (cin >> a) //get user input until a string in entered.
        nums.push_back(a);
    
    sort(nums.begin(), nums.end());
    getMode(nums);

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
    printVec(nums, "\nUser's Sequence: "); //print the user's number sequence
    printVec(repeats, "Unique numbers: ");
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

    return 0;
}
