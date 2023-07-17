// Try This Page 153.cpp : To see what an uncaught exception error looks like, run a small program that
//uses error() without catching any exceptions.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void error(string s)
{
    throw runtime_error(s);
}

void error(string s1, string s2)
{
    throw runtime_error(s1 + s2);
}

int main()
{
    int x;
    cin >> x;

    if (x == 1)
        cout << "ok";
    else
        error("no");
}

