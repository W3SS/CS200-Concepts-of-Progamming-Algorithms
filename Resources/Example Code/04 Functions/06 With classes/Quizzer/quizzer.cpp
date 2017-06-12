// This uses pointers and structs
// just because it's easiest that way...

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct QuizItem
{
    string question;
    string answers[4];
    int correctAnswer;
};

int GetChoice( int minVal, int maxVal );
void CreateQuiz( const string& filename );
void RunQuiz( const string& filename );
void AskQuestion( const QuizItem& item );

int main()
{
    bool done = false;

    while ( !done )
    {
        cout << endl << "QUIZZER" << endl;
        cout << "1. Create Quiz" << endl;
        cout << "2. Run Quiz" << endl;
        cout << "3. Quit" << endl;

        int choice = GetChoice( 1, 3 );

        switch( choice )
        {
            case 1:
            {
                string filename;
                cout << "Quiz Filename: ";
                cin >> filename;
                CreateQuiz( filename );
            break;
            }

            case 2:
            {
                string filename;
                cout << "Quiz Filename: ";
                cin >> filename;
                RunQuiz( filename );
            break;
            }

            case 3:
                done = true;
            break;
        }
    }

    return 0;
}

int GetChoice( int minVal, int maxVal )
{
    int value;
    cout << ">> ";
    cin >> value;
    while ( value < minVal || value > maxVal )
    {
        cout << "Invalid choice." << endl;
        cout << ">> ";
        cin >> value;
    }
    return value;
}

void CreateQuiz( const string& filename )
{
    ofstream outfile( filename.c_str() );
    bool done = false;
    while ( !done )
    {
        cout << endl << "CREATE QUIZ" << endl;
        cout << "1. Add Question" << endl;
        cout << "2. Save and quit" << endl;

        int choice = GetChoice( 1, 2 );
        if ( choice == 1 )
        {
            string question;
            string answers[4];
            int correctAnswer;

            cin.ignore();
            cout << "Question: ";
            getline( cin, question );

            cout << "Answer 1: ";
            getline( cin, answers[0] );

            cout << "Answer 2: ";
            getline( cin, answers[1] );

            cout << "Answer 3: ";
            getline( cin, answers[2] );

            cout << "Answer 4: ";
            getline( cin, answers[3] );

            cout << "Correct answer: ";
            correctAnswer = GetChoice( 1, 4 );

            // Output
            outfile << "BEGIN"
                << " QUESTION " << question
                << " ANSWER1 " << answers[0]
                << " ANSWER2 " << answers[1]
                << " ANSWER3 " << answers[2]
                << " ANSWER4 " << answers[3]
                << " CORRECT " << correctAnswer
                << " END" << endl;
        }
        else if ( choice == 2 )
        {
            done = true;
        }
    }
    outfile.close();
}

void RunQuiz( const string& filename )
{
    ifstream infile( filename.c_str() );

    if ( infile.fail() )
    {
        cout << "Could not find file \"" << filename << "\"!" << endl;
        infile.close();
        return;
    }

    string buffer;

    QuizItem item;
    string * current;

    while ( infile >> buffer )
    {
        if ( buffer == "QUESTION" )
        {
            current = &item.question;
        }
        else if ( buffer == "ANSWER1" )
        {
            current = &item.answers[0];
        }
        else if ( buffer == "ANSWER2" )
        {
            current = &item.answers[1];
        }
        else if ( buffer == "ANSWER3" )
        {
            current = &item.answers[2];
        }
        else if ( buffer == "ANSWER4" )
        {
            current = &item.answers[3];
        }
        else if ( buffer == "CORRECT" )
        {
            infile >> item.correctAnswer;
        }
        else if ( buffer == "BEGIN" )
        {
            item.question = "";
            for ( int i = 0; i < 4; i++ )
            {
                item.answers[i] = "";
            }
            item.correctAnswer = -1;
            current = &item.question;
        }
        else if ( buffer == "END" )
        {
            AskQuestion( item );
        }
        else
        {
            // Append text
            if ( *current != "" )
            {
                (*current) += " ";
            }
            (*current) += buffer;
        }
    }

    infile.close();
}

void AskQuestion( const QuizItem& item )
{
    cout << "----------------------" << endl;
    cout << item.question << endl;
    for ( int i = 0; i < 4; i++ )
    {
        cout << (i+1) << ". " << item.answers[i] << endl;
    }
    int choice = GetChoice( 1, 4 );

    if ( choice == item.correctAnswer )
    {
        cout << "CORRECT!" << endl;
    }
    else
    {
        cout << "Incorrect!" << endl;
    }
}
