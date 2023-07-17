// Drill.cpp : 
// 
// Below are 25 code fragments. Each is meant to be inserted into this
// "scaffolding" (see the book, I'm not going to cipy that twice).
//
// Each has zero or more errors. Your task is to find and remove all errors in
// each program. When you have removed those bugs, the resulting program will
// compile, run, and write "Success!" Even if you think you have spotted an
// error, you still need to enter the (original, unimproved) program fragment
// and test it; you may have guessed wrong about what the error is, or there
// may be more errors in a fragment tha you spotted. Also, one purpose of this
// drill is to give you a feel for how your compiler reacts to different kind
// of errors. (...) Do not fix problems by simply deleting a segment; repair
// them by changing, adding, or deleting a few characters.

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
    try {
        //#1
        cout << "1.Success!\n"; 
        //#2
        cout << "2.Success!\n";
        //#3
        cout << "3.Success" << "!\n";
        //#4
        cout << "4.Success!" << '\n';
        //#5
        int res5 = 7; vector<int> v5(10); v5[5] = res5; cout << "5.Success!\n";
        //#6
        vector<int> v6(10); v6[5] = 7; if (v6[5] == 7) cout << "6.Success!\n";
        //#7
        bool cond7 = true;  if (cond7) cout << "7.Success!\n"; else cout << "Fail!\n";
        //#8
        bool c8 = true; if (c8) cout << "8.Success!\n"; else cout << "Fail!\n";
        //#9
        string s9 = "ape"; bool c9 = "fool"<s9; if (!c9) cout << "9.Success!\n";
        //#10
        string s10 = "ape"; if (s10 != "fool") cout << "10.Success!\n";
        //#11
        string s11 = "ape"; if (s11 != "fool") cout << "11.Success!\n";
        //#12
        string s12 = "ape"; if (s12 != "fool") cout << "12.Success!\n";
        //#13
        vector<char> v13(5); for (int i = 0; i < v13.size(); ++i); cout << "13.Success!\n";
        //#14
        vector<char> v14(5); for (int i = 0; i <= v14.size(); ++i); cout << "14.Success!\n";
        //#15
        string s15 = "15.Success!\n"; for (int i = 0; i < s15.size(); ++i) cout << s15[i];
        //#16
        if (true) cout << "16.Success!\n"; else cout << "Fail!\n";
        //#17
        int x17 = 2000; int c17 = x17; if (c17 == 2000) cout << "17.Success!\n";
        //#18
        string s18 = "18.Success!\n"; for (int i = 0; i < s18.size(); ++i) cout << s18[i];
        //#19
        vector<int> v19(5); for (int i = 0; i <= v19.size(); ++i); cout << "19.Success!\n";
        //#20
        int i20 = 0; int j20 = 9; while (i20 < 10) ++i20; if (j20 < i20) cout << "20.Success!\n";
        //#21
        int x21 = 2; double d21 = 5 / (x21+2); if (d21 != 2 * x21 + 0.5) cout << "21.Success!\n";
        //#22
        string s22 = "22.Success!\n"; for (int i = 0; i <= s22.size(); ++i) cout << s22[i];
        //#23
        int i23 = 0; int j23 = 0; while (i23 < 10) ++i23; if (j23 < i23) cout << "23.Success!\n";
        //#24
        int x24 = 4; double d24 = 5 / (x24-2); if (d24 = 2 * x24 + 0.5) cout << "24.Success!\n";
        //#25
        cout << "25.Success!\n";
        keep_window_open();
        return 0;
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;
    }
}

