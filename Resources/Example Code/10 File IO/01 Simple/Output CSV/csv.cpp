#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string word;
    ofstream output( "WordList.csv" );

    // Header
    output << "ENGLISH,ESPERANTO" << endl;

    // Content
    output << "Red,Rugha" << endl;
    output << "Orange,Orangha" << endl;
    output << "Yello,Flava" << endl;
    output << "Green,Verda" << endl;
    output << "Blue,Blua" << endl;
    output << "Purple,Purpura" << endl;

    output.close();

    return 0;
}

