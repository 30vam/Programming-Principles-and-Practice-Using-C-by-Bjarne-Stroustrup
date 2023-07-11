//Write a program that “bleeps” out words that you don’t like; that is, you read in words using cin 
//and print them again on cout.If a word is among a few you have defined, you write out BLEEP
//instead of that word.Start with one “disliked word” such as:
//string disliked = “Broccoli”;
//When that works, add a few more.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
inline void keep_window_open() { char ch; cin >> ch; }
// error function to be used (only) until error() is introduced in Chapter 5:
inline void simple_error(string s)	// write ``error: sТТ and exit program
{
    cerr << "error: " << s << '\n';
    keep_window_open();		// for some Windows environments
    exit(1);
}

int main()
{
    vector<string> words;
    vector<string> dislikedWords = { "broccoli", "bro", "a"};

    for (string word; cin >> word; )
    {
        words.push_back(word);
        bool isDisliked = false;

        for (string dislikedWord: dislikedWords)
        {
            if (word == dislikedWord)
                isDisliked = true;
        }

        if (isDisliked)
            cout << "BLEEP\n";
        else
            cout << word << '\n';
    }
    return 0;
}

