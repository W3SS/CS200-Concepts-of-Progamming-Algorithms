#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string word = "WHY?!?!";
    ofstream output( "Program.cpp" );

    output << "#include <iostream>" << endl;
    output << "using namespace std;" << endl;
    output << "int main() {" << endl;

    for ( int i = 0; i < 100; i++ )
    {
        output << "cout << \"" << word << "\" << endl;" << endl;
    }

    output << "return 0;" << endl;
    output << "}" << endl;

    output.close();

    return 0;
}



