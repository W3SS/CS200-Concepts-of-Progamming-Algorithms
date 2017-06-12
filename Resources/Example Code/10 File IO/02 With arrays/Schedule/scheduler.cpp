#include <iostream>
#include <fstream>
using namespace std;

const int DAYS_OF_WEEK = 7;
const int HOURS_OF_DAY = 24;

int main()
{
	string days[ DAYS_OF_WEEK ] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	
	string times[ HOURS_OF_DAY ] = { "12:00 am", "1:00 am", "2:00 am", "3:00 am", "4:00 am", "5:00 am", "6:00 am", "7:00 am", "8:00 am", 
		"9:00 am", "10:00 am", "11:00 am", "12:00 pm", "1:00 pm", "2:00 pm", "3:00 pm", "4:00 pm", "5:00 pm", "6:00 pm", "7:00 pm",
		"8:00 pm", "9:00 pm", "10:00 pm", "11:00 pm" };
	
	string schedule[ DAYS_OF_WEEK ][ HOURS_OF_DAY ];
	
	while ( true )
	{
		cout << "Add item to schedule" << endl;
		cout << "Which day of the week? " << endl;
		
		for ( int d = 0; d < DAYS_OF_WEEK; d++ )
		{
			cout << d << ". " << days[d] << endl;
		}
		cout << "7. Save and quit" << endl;
		
		int dayOfWeek;
		cout << ">> ";
		cin >> dayOfWeek;
		
		if ( dayOfWeek == 7 )
		{
			break;
		}
		
		cout << "What time of day? (Hours 0 through 23)" << endl;
		int hour;
		cout << ">> ";
		cin >> hour;
		cin.ignore();
		
		cout << "What is the event?" << endl;
		string event;
		getline( cin, event );
		
		schedule[ dayOfWeek ][ hour ] = event;
		
		cout << endl << endl;	
	}
	
	ofstream output( "schedule.csv" );
	
	for ( int d = 0; d < DAYS_OF_WEEK; d++ )
	{
		output << "," << days[ d ];
	}
	
	output << endl;
	
	for ( int h = 0; h < HOURS_OF_DAY; h++ )
	{
		output << times[ h ];
		
		for ( int d = 0; d < DAYS_OF_WEEK; d++ )
		{
			output << "," << schedule[ d ][ h ];
		}
		
		output << endl;
	}
	
	output.close();
	
	return 0;
}
