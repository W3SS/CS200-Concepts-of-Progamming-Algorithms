#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string word;
    ifstream infile( "input.txt" );

    string word1, word2, word3;
    infile >> words1;
    infile >> words2;
    infile >> words3;

    infile.close();

    cout << words1 << endl
        << words2 << endl
        << words3 << endl;

    return 0;
}


