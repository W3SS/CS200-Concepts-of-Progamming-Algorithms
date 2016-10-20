#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

struct Issue
{
    string name;
    bool isPro;
    int totalSupporters;
};

struct Candidate
{
    string name;
    Issue positions[10];
    int totalVotes;
};






string GetRandomTopic();
string GetRandomName();
string GetRandomState();

void CreateIssues( Issue issues[10] );
void CreateCandidates( Candidate candidates[3], Issue issues[10] );

int main()
{
    srand( time( NULL ) );

    Issue issues[10];
    CreateIssues( issues );

    Candidate candidates[3];
    CreateCandidates( candidates, issues );

    cout << "CANDIDATES" << endl;
    for ( int c = 0; c < 3; c++ )
    {
        cout << candidates[c].name << endl;
        for ( int i = 0; i < 10; i++ )
        {
            cout << "* ";
            if ( candidates[c].positions[i].isPro ) { cout << "PRO-"; }
            else { cout << "ANTI-"; }
            cout << candidates[c].positions[i].name << endl;
        }

        cout << endl;
    }

    return 0;
}











void CreateIssues( Issue issues[10] )
{
    for ( int i = 0; i < 10; i++ )
    {
        issues[i].name = GetRandomTopic();
        issues[i].totalSupporters = 0;
    }
}

void CreateCandidates( Candidate candidates[3], Issue issues[10] )
{
    for ( int c = 0; c < 3; c++ )
    {
        candidates[c].name = GetRandomName();
        candidates[c].totalVotes = 0;

        for ( int i = 0; i < 10; i++ )
        {
            candidates[c].positions[i].name = issues[i].name;
            candidates[c].positions[i].isPro = rand() % 2;

            if ( candidates[c].positions[i].isPro )
            {
                issues[i].totalSupporters++;
            }
        }
    }
}

string GetRandomTopic()
{
    string topicsA[10] = {
        "ROBOT",
        "TELEPORTATION",
        "JUPITER",
        "CYBORG",
        "TIME TRAVEL",
        "SPACESHIP",
        "WORMHOLE",
        "VIRTUAL REALITY",
        "3D PRINTER",
        "CYBER"
    };

    string topicsB[10] = {
        "COLONIES",
        "RIGHTS",
        "MARRIAGE",
        "CONTROL",
        "WAR",
        "RESTRICTION",
        "SUBSIDIES",
        "TAX BREAK",
        "TAX INCREASE",
        "INDUSTRIAL COMPLEX"
    };

    return topicsA[ rand() % 10 ] + " " + topicsB[ rand() % 10 ];
}

string GetRandomName()
{
    string namesA[15] = {
        "Janan", "Kalina", "Lei", "Sakke", "Denise",
        "Pradeep", "Takuya", "Salomao", "Sunan", "Angharad",
        "Teodor", "Paloma", "Varya", "Irenka", "Quan"
    };

    string namesB[15] = {
        "Katz", "Zietek", "Van Achthoven", "Chapman", "Szweda",
        "Leveque", "Liu", "Samuel", "Scotti", "Welch",
        "Pierno", "Shimizu", "Barnett", "Ruan", "Kwok"
    };

    return namesA[ rand() % 15 ] + " " + namesB[ rand() % 15 ];;
}

string GetRandomState()
{
    string states[50] = {
        "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia",
        "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachussets",
        "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana", "Nebraska", "Nevada", "New Hampshire", "New Jersey",
        "New Mexico", "New York", "North Carolina", "North Dakota", "Ohio", "Oklahoma", "Oregon", "Pennsylvania",
        "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah", "Vermont", "Virginia",
        "Washington", "West Virginia", "Wisconsin", "Wyoming"
    };

    return states[ rand() % 50 ];
}
