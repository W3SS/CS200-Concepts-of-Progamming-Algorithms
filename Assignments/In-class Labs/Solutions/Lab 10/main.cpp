#include <iostream>
using namespace std;

#include "Question.hpp"

int main()
{
    Question questions[4];
    int score = 0;
    int totalScore = 4;

    questions[0].SetQuestion( "What is 2+2?", "4" );
    questions[1].SetQuestion( "What is 2+3?", "5" );
    questions[2].SetQuestion( "What is 2+4?", "6" );
    questions[3].SetQuestion( "What is 2+5?", "7" );

    for ( int i = 0; i < 4; i++ )
    {
        if ( questions[i].AskQuestion() )
        {
            score++;
        }

        cout << endl << endl;
    }

    cout << "Your final score: " << score << " of " << totalScore << endl;

    return 0;
}
