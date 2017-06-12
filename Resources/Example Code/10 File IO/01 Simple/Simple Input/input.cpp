#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string word;
    ifstream infile( "input.txt" );

    string words[3];
    infile >> words[0];
    infile >> words[1];
    infile >> words[2];

    infile.close();

    cout << words[0] << endl
        << words[1] << endl
        << words[2] << endl;

    return 0;
}


