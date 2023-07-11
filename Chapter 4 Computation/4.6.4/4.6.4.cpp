// simple dictionary: list of sorted words
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
    for (string word; cin >> word;) //read whitespaced characters
        words.push_back(word); // put into vector

    cout << "Number of Words:" << words.size() << '\n';

    sort(words.begin(), words.end()); //sort the words

    for (int i = 0; i < words.size(); i++)
    {
        //is this a new word? when we sort the vector, similar words are in order so this works correctly
        if (i == 0 || words[i] != words[i-1])
            cout << words[i] << '\n';
    }
}


