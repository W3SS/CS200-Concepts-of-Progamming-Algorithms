    #include <iostream>
    using namespace std;

    void PassByValue( int number )
    {
        number = 5;
    }

    void PassByReference( int & number )
    {
        number = 7;
    }

    int main()
    {
        int num = 10;

        cout << "1. Num: " << num << endl;

        PassByValue( num );
        cout << "2. Num: " << num << endl;

        PassByReference( num );
        cout << "3. Num: " << num << endl;

        return 0;
    }

