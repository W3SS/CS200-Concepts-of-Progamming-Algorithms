#include <iostream>
#include <string>
using namespace std;

    struct Timestamp
    {
        int h, m, s;
    };

class ChatLine
{
    public:
    void Set( string u, string msg, int h, int m, int s )
    {
        username = u;
        message = msg;
        time.h = h;
        time.m = m;
        time.s = s;
    }

    void Display()
    {
        cout << "(" << time.h << ":" << time.m << ":" << time.s << ") "
            << username << ": " << message << endl;
    }

    private:
    string username;
    string message;
    Timestamp time;
};

int main()
{
    ChatLine lines[10];

    for ( int i = 0; i < 10; i++ )
    {
        string username = "Bob";
        if ( i % 2 == 0 )
        {
            username = "Lol";
        }
        lines[i].Set( username, "This is a sample", 6, i, 0 );
    }

    for ( int i = 0; i < 10; i++ )
    {
        lines[i].Display();
    }

    return 0;
}




