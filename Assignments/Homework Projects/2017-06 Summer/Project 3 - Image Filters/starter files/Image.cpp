#include "Image.hpp"

/// Set the pixelArray to nullptr
/**
This is a CONSTRUCTOR function. Constructor functions
are run immediately once a new Image variable object
is created. Therefore, this is a good place to
initialize member variables of our class.
*/
Image::Image()
{
}

/// Call the DeallocateArray function
/**
This is a DESTRUCTOR function. Destructor functions
are run immediately once an Image variable is destroyed,
such as when it goes out of scope. These are called
automatically, so it is a good place to free up
space and clean things up in the class.
*/
Image::~Image()
{
}

/// Create an input file stream and load in the image contents
void Image::ReadFile( const string& filename )
{
}

/// Create an output file stream and write out the image contents
void Image::WriteFile( const string& filename )
{
}

/// Print out information about the image. Use this for debug if you want.
void Image::PrintStats()
{
    cout << "Image: " << inputFilename << endl;
    cout << "Width: " << width << ", Height: " << height << endl;
    cout << "Color depth: " << colorDepth << endl;
    cout << "Pixel count: " << pixelCount << endl;
    cout << "Note: " << headerNote << endl << endl;
}

/// Use the pixelArray pointer to allocate a new dynamic array
void Image::AllocateArray( int size )
{
}

/// Free up space that was allocated via the pixelArray pointer
void Image::DeallocateArray()
{
}

/// Iterate through all pixels in the image and set the RED values to 0
void Image::Filter_RemoveRed()
{
}

/// Iterate through all pixels in the image and set the GREEN values to 0
void Image::Filter_RemoveGreen()
{
}

/// Iterate through all pixels in the image and set the BLUE values to 0
void Image::Filter_RemoveBlue()
{
}

/// Iterate through all pixels in the image and double the value of each R, G, B value
void Image::Filter_Brighten()
{
}

/// Iterate through all pixels in the image and halve the value of each R, G, B value
void Image::Filter_Darken()
{
}

/// Iterate through all pixels in the image and shift colors R -> G, G -> B, B -> R
void Image::Filter_ShiftColors()
{
}

/// Create your own custom filter
void Image::Filter_Custom()
{
}

