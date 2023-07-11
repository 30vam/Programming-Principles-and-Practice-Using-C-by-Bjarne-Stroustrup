/*4. Write a program to play a numbers guessing game.The user thinks of a number between 1 and 100
and your program asks questions to figure out what the number is(e.g., “Is the number you are
    thinking of less than 50 ? ”).Your program should be able to identify the number after asking no
    more than seven questions.Hint: Use the < and <= operators and the if - else    ct.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int min = 0;
    int max = 1000;
    int questionNum = (max - min)/2;
    char userAnswer;

    std::cout << "Guess a number between " << min << " & " << max << " and then press Enter: \n";

    while (true)
    {   
        if (cin.get() == '\n')//if the user goes to the next line continue:
        {
            while (max - min > 1) //keep asking until there's only 1 number left to guess (the answer)
            {
                cout << "Is your number bigger than " << questionNum << " ? (y / n) ";
                cin >> userAnswer;

                if (userAnswer == 'y') //if the number is bigger than the guess:
                {
                    min = questionNum + 1; // +1 because it asks if the numbers is BIGGER, not bigger or equal
                    if (max - min == 1) //when only min and max are left to chose:
                        questionNum = max;
                    else
                        questionNum += (max - min) / 2;
                }
                else if (userAnswer == 'n')//if the number is smaller than the guess:
                {
                    max = questionNum;
                    if (max - min == 1) //when only min and max are left to chose:
                        questionNum = min;
                    else
                        questionNum -= (max - min) / 2;
                }
                //test
                cout << "max: " << max << " min: " << min << endl;
                
            }
            cout << "Your chosen number was: " << questionNum << endl;
            
        }
    }
}


