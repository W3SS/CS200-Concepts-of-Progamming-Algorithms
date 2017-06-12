#ifndef _UTILS
#define _UTILS

void DisplayMainMenu( const string choices[], int choiceCount )
{
    cout << "-------------------------" << endl;
    cout << "GROCERY MANAGEMENT SYSTEM" << endl;
    cout << "-------------------------" << endl;
    for ( int i = 0; i < choiceCount; i++)
    {
        cout << choices[i] << endl;
    }
}

int GetNumberInput( int minVal, int maxVal )
{
    cout << ">> ";
    int choice;
    cin >> choice;

    while ( choice < minVal || choice > maxVal )
    {
        cout << "Invalid input, try again." << endl;
        cout << ">> ";
        cin >> choice;
    }
    return choice;
}

void ClearScreen()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    system( "cls" );
    #else
    system( "clear" );
    #endif
}

#endif
