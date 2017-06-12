#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string word;
    ofstream output( "Webpage.html" );

    output << "<html>" << endl;
    output << "<head><title>My Page</title></head>" << endl;
    output << "<body>" << endl;
    output << "<h1>This is a page</h1>" << endl;
    output << "<p>Hello, how are you doing?</p>" << endl;
    output << "<input type='button' value='Alright'/>" << endl;
    output << "<input type='button' value='Not great'/>" << endl;
    output << "<input type='button' value='Bad'/>" << endl;
    output << "</body>" << endl;
    output << "</html>" << endl;

    output.close();

    return 0;
}


