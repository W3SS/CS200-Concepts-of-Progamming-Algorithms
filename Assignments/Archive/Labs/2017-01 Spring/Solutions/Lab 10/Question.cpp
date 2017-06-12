#include "Question.hpp"

void Question::SetQuestion( const string& question, const string& answer )
{
    m_question = question;
    m_answer = answer;
}

bool Question::AskQuestion()
{
    cout << "QUESTION" << endl;
    cout << m_question << endl << endl;
    cout << "What is your answer? ";

    string answer;
    cin >> answer;

    return ( m_answer == answer );
}
