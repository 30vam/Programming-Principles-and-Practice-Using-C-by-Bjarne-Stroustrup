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
    string first_name;
    string friend_name;
    char friend_sex = 0;
    int age = 0;

    cout << "Enter the name of the person you want to write to, your friend\n";
    cin >> first_name;
    cout << "Dear " << first_name << ",\n" << "How are you ? I am fine.I miss you.\n";

    cout << "Enter the name of your friend\n";
    cin >> friend_name;
    cout << "Have you seen "<< friend_name << " lately?\n";

    cout << "Enter your friends sex: m for male and f for female.\n";
    cin >> friend_sex;
    if (friend_sex == 'm')
        cout << "If you see " << friend_name << "please ask him to call me.\n";
    if (friend_sex == 'f')
        cout << "If you see " << friend_name << "please ask her to call me.\n";

    cout << "Enter your friends age:\n";
    cin >> age;
    if (age <= 0 || age >= 110)
        simple_error("you're kidding!");

    cout << "I hear you just had a birthday and you are " << age << " years old.\n";

    if (age < 12)
        cout << "Next year you will be " << age + 1 << ".\n";
    if (age == 17)
        cout << "Next year you will be able to vote.\n";
    if (age > 70)
        cout << "I hope you are enjoying retirement!\n";

    cout << "\n\nYours sincerely,\n\nSina\n";
        
}



