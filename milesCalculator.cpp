// Jeremy Jefferson


#include <iostream>
using namespace std;
void goodbye();
int calcTotal(int daysRan);
void getInput(int &goal);
void welcome();
int main()
{
    int goal = 0;
    int daysRan = 0;

    welcome();
    getInput(goal);

    if (goal < 1)
    {
        cout << "No miles were tracked this week." << endl
             << endl
             << "Keep riding!" << endl;
        exit(EXIT_SUCCESS);
    }
    int ranInWeek = calcTotal(daysRan);
    cout << endl
         << "You rode " << ranInWeek << " Miles this week." << endl;
    if (goal > ranInWeek)
    {
        cout << "Uh oh! You missed your goal by " << goal - ranInWeek << " Miles" << endl;
    }
    else if (goal == ranInWeek)
    {
        cout << "Good job! You met your goal!" << endl;
    }
    else if (goal < ranInWeek)
    {
        cout << "Congratulations you exceeded your goal by " << ranInWeek - goal << " Miles" << endl;
    }
    goodbye();
    return 0;
}

// function to get input from user that asks how many days the user wanted to ride this week;

void getInput(int &goal)
{
    int milesExpected;
    cout << endl
         << "How many miles do you want to ride this week? ";
    cin >> milesExpected;
    goal = milesExpected;
}

// make another function called calcTotal()
int calcTotal(int daysRan)
{
    // use for loop to prompt for the number of miles ridden each week in for a day
    // if user enters 0 print error message and ask for the same day
    int i;
    int ranInWeek = 0;

    for (i = 1; i <= 7; i++)
    {
        int ranInDay;
        cout << endl
             << "Enter miles ridden on day " << i << ": ";
        cin >> ranInDay;
        while (ranInDay < 0)
        {
            cout << "Miles must be 0 or greater!" << endl
                 << "please try again ";
            cout << "Enter miles ridden on day " << i << ": ";
            cin >> ranInDay;
        }
        ranInWeek += ranInDay;
    }

    return ranInWeek;
}

// welcome message and goodbye function
void welcome()
{
    cout << "Welcome to my Miles Tracker program." << endl;
}
void goodbye()
{
    cout << "Thank you for using my program! " << endl;
}