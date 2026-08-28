//COMSC-210 | Lab 1 | Eric-Giulio Hedes
#include <iostream>
#include <iomanip>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));

    const int MAXIMUM = 100;
    int amount = 0, correctQuestions = 0;
    double num1, num2, question, answer;

    cout << "Enter an amount for mathematical questions (Maximum is " << MAXIMUM  << "): ";
    while (true)
    {
        cin >> amount;
        cin.ignore(1000, 10);

        if (amount > 0 && amount < MAXIMUM)
        {
            for (int i = amount; i > 0; i--)
            {
                num1 = rand() % 10 + 1;
                num2 = rand() % 10 + 1;
                question = num1 + num2;
                cout << num1 << " + " << num2 << " = ";
                cin >> answer;
                cin.ignore(1000, 10);
                if (answer == question)
                {
                    cout << "Correct!" << endl;
                    correctQuestions++;
                }
                else cout << "Wrong; correct answer is: " << question << endl;
            }
            cout << "Congratulations! You've made it!" << endl << endl << "RESULTS" << endl;
            cout << "----------------------------------" << endl;
            cout << "Correct Answers: " << correctQuestions << endl;
            cout << "Wrong Answers: " << amount - correctQuestions << endl;
            break;
        }
        else
        {
            cout << "ERROR: The amount of questions either exceeded " << MAXIMUM << " or were less than 1." << endl;
            cout << "Try again: ";
        }
    }

    //return 0;
}