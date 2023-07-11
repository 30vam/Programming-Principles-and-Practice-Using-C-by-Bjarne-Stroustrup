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

void printVec(vector<int> vec) {
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (vec.size() == 1)
            cout << "Your Sequence is: { " << vec[i] << " }.\n";
        else if (i == 0)
            cout << "Your Sequence is: { " << vec[i] << ", ";
        else if (i == vec.size() - 1)
            cout << vec[i] << " }.\n";
        else
            cout << vec[i] << ", ";
    }
}



int main()
{
    vector<int> nums{};
    int a;

    cout << "Enter a series of numbers. Enter anything else to end the series: ";

    while (cin >> a) //get user input until a string in entered.
        nums.push_back(a);

    int mode{ 0 };
    int count{ 1 };
    int currentNumCount{ 1 };

    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1]) //add one to counter if the numbers are repeated
            currentNumCount++;
        else if (i != 0)
            currentNumCount = 1;

        if (currentNumCount > count) {
            mode = nums[i];
            count = currentNumCount;
        }
            
    }

    printVec(nums); //print the number sequence

    //show the results
    if (count == 1)
        cout << "This sequence doesn't have a mode.\n";
    else
        cout << "The mode is " << mode << " and it's repeated " << count << " times.\n";

    return 0;
}
