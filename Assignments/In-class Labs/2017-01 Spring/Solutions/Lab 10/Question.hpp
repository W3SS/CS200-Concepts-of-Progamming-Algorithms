#ifndef QUESTION_HPP
#define QUESTION_HPP

#include <string>
#include <iostream>
using namespace std;

class Question
{
    public:
    void SetQuestion( const string& question, const string& answer );
    bool AskQuestion();

    private:
    string m_question;
    string m_answer;
};

#endif
