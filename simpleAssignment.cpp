//COMSC-210 | Lab 1 | Eric-Giulio Hedes
#include <iostream>
#include <iomanip>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    //Set up a random seed generator to generate different questions
    srand(time(0));

    //Set up the maximum variable
    const int MAXIMUM = 100;
    //Set up the amount & correct question variables
    int amount = 0, correctQuestions = 0;
    //
    double num1, num2, question, answer;

    //From there the program actually starts.
    //Ask the user to enter an amount of math questions that they will be asked. Going above the maximum and below 0 will ask the user to try again.
    cout << "Enter an amount for mathematical questions (Maximum is " << MAXIMUM  << "): ";
    //Use a while(true) loop to define the validation loop and ask random math questions.
    while (true)
    {
        //Ask the user to enter the amount of math questions
        cin >> amount;
        cin.ignore(1000, 10);

        //If the amount is bigger than 0 or smaller than the maximum, initiate the math problem loop.
        if (amount > 0 && amount < MAXIMUM)
        {
            //The math problem loop in question uses a nested/for-loop in order for it to function
            for (int i = amount; i > 0; i--)
            {
                //Initialize the number variables
                num1 = rand() % 10 + 1;
                num2 = rand() % 10 + 1;
                //Initialize the question variable by adding the two number variables altogether
                question = num1 + num2;
                //Print & ask the user to solve the math problem
                cout << num1 << " + " << num2 << " = ";
                cin >> answer;
                cin.ignore(1000, 10);
                //If the user gets the question correct...
                if (answer == question)
                {
                    //Then print out a correct message and add up the amount of correct questions
                    cout << "Correct!" << endl;
                    correctQuestions++;
                }
                else //Otherwise tell them the correct answer.
                    cout << "Wrong; correct answer is: " << question << endl;
            }
            //If all of the questions are done, then congratulate the user and print out the results.
            cout << "Congratulations! You've made it!" << endl << endl << "RESULTS" << endl;
            cout << "----------------------------------" << endl;
            //Print both correct & wrong answers
            cout << "Correct Answers: " << correctQuestions << endl;
            cout << "Wrong Answers: " << amount - correctQuestions << endl;
            //Break the while(loop).
            break;
        }
        else //If the amount is bigger than the maximum or lower than 1...
        {
            //It spews an error message then asks the user to try again.
            cout << "ERROR: The amount of questions either exceeded " << MAXIMUM << " or were less than 1." << endl;
            cout << "Try again: ";
        }
    }

    //return 0;
}