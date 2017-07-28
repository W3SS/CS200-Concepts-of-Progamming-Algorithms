#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Image.hpp"

void RemoveRed( const string& filename )
{
    cout << "Running Remove Red..." << endl;
    Image image;
    image.ReadFile( filename + ".ppm" );

    image.Filter_RemoveRed();

    image.WriteFile( "output/removered_" + filename + ".ppm" );
}

void RemoveGreen( const string& filename )
{
    cout << "Running Remove Green..." << endl;
    Image image;
    image.ReadFile( filename + ".ppm" );

    image.Filter_RemoveGreen();

    image.WriteFile( "output/removegreen_" + filename + ".ppm" );
}

void RemoveBlue( const string& filename )
{
    cout << "Running Remove Blue..." << endl;
    Image image;
    image.ReadFile( filename + ".ppm" );

    image.Filter_RemoveBlue();

    image.WriteFile( "output/removeblue_" + filename + ".ppm" );
}

void Brighten( const string& filename )
{
    cout << "Running Brighten..." << endl;
    Image image;
    image.ReadFile( filename + ".ppm" );

    image.Filter_Brighten();

    image.WriteFile( "output/brighten_" + filename + ".ppm" );
}

void Darken( const string& filename )
{
    cout << "Running Darken..." << endl;
    Image image;
    image.ReadFile( filename + ".ppm" );

    image.Filter_Darken();

    image.WriteFile( "output/darken_" + filename + ".ppm" );
}

void Shift( const string& filename )
{
    cout << "Running Shift..." << endl;
    Image image;
    image.ReadFile( filename + ".ppm" );

    image.Filter_ShiftColors();

    image.WriteFile( "output/shift_" + filename + ".ppm" );
}

void Custom( const string& filename )
{
    cout << "Running Custom..." << endl;
    Image image;
    image.ReadFile( filename + ".ppm" );

    image.Filter_Custom();

    image.WriteFile( "output/custom_" + filename + ".ppm" );
}

int main()
{
	string filename;
    cout << "FILTER ME" << endl;
    cout << "Enter name of file to filter (don't include .ppm): ";
    getline( cin, filename );

    cout << endl;

    RemoveRed( filename );
    RemoveGreen( filename );
    RemoveBlue( filename );
    Brighten( filename );
    Darken( filename );
    Shift( filename );
    Custom( filename );

    return 0;
}
