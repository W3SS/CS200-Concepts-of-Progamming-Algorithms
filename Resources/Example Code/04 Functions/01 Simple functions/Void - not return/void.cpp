#include <iostream>
#include <string>
using namespace std;

void GetUsername()
{
    string username;
    cout << "Enter your username: ";
    cin >> username;

    if ( username == "helloworld123" )
    {
        cout << "Welcome, Leono." << endl;
    }
    else if ( username == "potatoes39" )
    {
        cout << "Welcome, Delfeno." << endl;
    }
    else
    {
        cout << "Unknown username" << endl;
    }
}

int main()
{
    GetUsername();

    return 0;
}
