// Jeremy Jefferson

// This program will gather the users grade and assignment and exam and calculate their total grade


#include <iostream>
#include <iomanip>

const double ASSIGNMENTS = .60;
const double EXAMS = .20;


using namespace std;
void welcomeMessage();
int readInt(string prompt);
void readScore(string prompt, double &num);
double assignAverage(int numAssigns);
void getInput(double &midtermScore, double &finalExamScore);
double calcFinalScore(double assignAvg, double midterm, double final);
void calcLetterGrade(double finalScore, char &letter);
int main ()
{
    welcomeMessage();
    
    double midterm = 0; double finalScore = 0; double assignAvg = 0; double final = 0;
    int numAssigns = readInt("Enter the number of assignments (0 to 10): ");
    char letterGrade;
    // grab average assignment score
    assignAvg = assignAverage(numAssigns);

    // grab midterm and final exam scores
    getInput(midterm, finalScore);
    // grab average test scores
    finalScore = calcFinalScore(assignAvg, midterm, final);
    
    // call function to print final letter 
    calcLetterGrade(finalScore, letterGrade);
    cout << "Your Final Letter Grade is: " << letterGrade << endl;
    cout << "Your final Numerical Score is: " << setprecision(2) << finalScore << endl;
    cout << endl << "Thank you for using my Grade Calculator!" << endl;
}

void welcomeMessage()
{
    cout << "Hello and welcome to my program" << endl;
     cout<<"Please enter the following information and I will calculate your" << endl;
   cout<<"Final Numerical Grade and Letter Grade for you!" << endl;
   cout<<"The number of assignments must be between 0 and 10. " << endl;
   cout<<"All scores entered must be between 0 and 4."<< endl;
}

// create function to read the number of Assignments from the user
// Get input , Validate Input , Return the number of assignments

int readInt(string prompt) {
    double tempVar;
    cout << prompt << endl;
    cin >> tempVar;
    // checks to make sure that assignment input is between (0 - 10)
    while (tempVar > 10 || tempVar < 0) {
        cout << prompt << endl;
        cin >> tempVar;
    }
    return tempVar;
}

// create function to read all scores from user
// any time we read a score to the user use this func
// get input, validate, return the user score.

void readScore(string prompt, double &num) {
    cout << prompt;
    cin >> num;
    // cout << num << endl;


    while (num > 4 || num < 0){
        cout << prompt << endl;
        cin >> num;
    }
}

// Use a forLoop to read the score from user.
// the for loop should execute < num of assignments.
// call readInt func for assignment
// call readscore func withing for loop.
// then calculate and return the average

double assignAverage(int numAssigns) {
    // Declare variables
    double scoreTotal = 0;
    //readInt("Enter the number of assignments (0 to 10): ");
    
    // for loop to loop back to readScore()
    for (int i = 1; numAssigns >= i; i++){
        double scoreAssigned;
        readScore("Enter score " + to_string(i) + ": ", scoreAssigned);
        scoreTotal += scoreAssigned;
    }
    // Calculate average from readInt()
    return scoreTotal / numAssigns;
}

// function that is going to call readScore()
// it is going to ask for the two exam scores
void getInput(double &midtermScore, double &finalExamScore) {
    readScore("Enter your midterm exam score: ", midtermScore);
    readScore("Enter your final exam score: ", finalExamScore);
}


double calcFinalScore(double assignAvg, double midterm, double final) {
    return (assignAvg * 0.6) + (midterm * 0.2) + (final * 0.2);
}

void calcLetterGrade(double finalScore, char &letter) {
    if (finalScore >= 3.3) {
        letter = 'A';
    }
    else if (finalScore >= 2.8) {
        letter = 'B';
    }
    else if(finalScore >= 2.0) {
        letter = 'C';
    }
    else if (finalScore >= 1.2) {
        letter = 'D';
    }
    else {
        letter = 'F';
    }
}



