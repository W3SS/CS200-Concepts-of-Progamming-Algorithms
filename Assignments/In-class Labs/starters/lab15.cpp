#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Room
{
};

class Building
{
};

int main()
{
    Building building( 5 );

    building.SetRoomTitle( 0, "Entryway" );
    building.SetRoomTitle( 1, "Living Room" );
    building.SetRoomTitle( 2, "Kitchen" );
    building.SetRoomTitle( 3, "Bedroom" );
    building.SetRoomTitle( 4, "Bathroom" );

    building.SetRoomDimensions( 0, 5, 10 );
    building.SetRoomDimensions( 1, 5, 10 );
    building.SetRoomDimensions( 2, 5, 10 );
    building.SetRoomDimensions( 3, 5, 10 );
    building.SetRoomDimensions( 4, 5, 10 );

    building.PrintBuildingInformation( "building.txt" );

    return 0;
}
