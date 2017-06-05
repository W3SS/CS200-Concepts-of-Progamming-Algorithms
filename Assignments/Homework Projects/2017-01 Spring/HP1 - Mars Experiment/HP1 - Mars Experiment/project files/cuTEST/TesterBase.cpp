#include "TesterBase.hpp"
#include "Menu.hpp"

TesterBase::TesterBase()
{
	m_totalTestCount = 0;
//	m_tests.push_back( TestListItem( "RUN ALL TESTS", bind( &TesterBase::TestAll, this ), true ) );
}

void TesterBase::Start()
{
	MainMenu();
}

void TesterBase::MainMenu()
{
	vector<string> options;
	vector<TestListItem*> ptrTests;
    for ( list<TestListItem>::iterator it = m_tests.begin(); it != m_tests.end(); it++ )
    {
        options.push_back( it->name );
        ptrTests.push_back( &(*it) );
    }
	options.push_back( "Exit" );

    int exitOption = options.size();


	bool done = false;
	while ( !done )
	{
		Menu::ClearScreen();
		Menu::DisplayHeader( "cuTEST Main Menu" );
		Menu::DisplayNumericMenu( options );

		// 1. Test all (test 0)
		// 2. Test1 (test 1)
		// 3. Quit

		int choice = Menu::GetNumberChoice( 1, exitOption );

		if ( choice == exitOption )
		{
            // Quit
			done = true;
		}
		else
		{
            // Run test
            int adjustedIndex = choice - 1;
            ptrTests[adjustedIndex]->callFunction();
            Menu::Pause();
		}
	}
}

int TesterBase::TestAll()
{
	int resultTotal = 0;

    cout << endl << "RUN ALL TESTS" << endl;

    for ( list<TestListItem>::iterator it = m_tests.begin(); it != m_tests.end(); it++ )
    {
        if ( it->testAggregate == false )
        {
            int result = it->callFunction();
            resultTotal += result;
        }
    }

	cout << "FINAL RESULT: " << resultTotal << " out of " << m_totalTestCount << endl;
	return resultTotal;
}

void TesterBase::DisplayPrerequisites( const vector<string>& prereqs )
{
    cout << "PREREQUISITE FUNCTIONS: ";
    for ( unsigned int i = 0; i < prereqs.size(); i++ )
    {
        if ( i != 0 ) { cout << ", "; }
        cout << prereqs[i];
    }
    cout << endl;
}

void TesterBase::AddTest( const TestListItem& test )
{
	m_tests.push_back( test );
	m_totalTestCount++;
}

void TesterBase::ReportFailure( const string& test, const string& message )
{
    cout << endl << "TEST FAILED: " << test << "\n"
        << message << endl << endl;
}

void TesterBase::ReportFailure( const string& message )
{
    ReportFailure( m_subtest_name, message );
}

void TesterBase::DisplayTestHeader( const string& test )
{
    Menu::ClearScreen();
    Menu::DisplayHeader( test );
    m_subtest_name = test;
}

void TesterBase::DisplayTestHeader( const string& test,  const vector<string>& prereqs  )
{
    Menu::ClearScreen();
    Menu::DisplayHorizontalRule();
    cout << "TEST SET: " << test << endl;
    DisplayPrerequisites( prereqs );
    Menu::DisplayHorizontalRule();
    m_subtest_name = test;
}

void TesterBase::DisplayScore( int totalPasses, int totalTests )
{
    cout << endl;

    if ( totalPasses == totalTests )
    {
        cout << "(PASS) ";
    }
    else
    {
        cout << "(FAIL) ";
    }

    cout << totalPasses << " passed out of " << totalTests << " tests" << endl;
}

void TesterBase::DisplayScore()
{
    DisplayScore( m_subtest_totalPasses, m_subtest_totalTests );
}

void TesterBase::InitTest( const string& name, const vector<string>& prereqs )
{
    DisplayTestHeader( name, prereqs );
    m_subtest_totalTests = 0;
    m_subtest_totalPasses = 0;
}

void TesterBase::StartTest( const string& description )
{
    m_subtest_totalTests++;
    // Outputting this just clutters stuff up.
    //cout << "Test " << m_subtest_totalTests << ": " << description << endl;
}

void TesterBase::TestFail()
{
}

void TesterBase::TestPass()
{
    m_subtest_totalPasses++;
}

int TesterBase::TestResult()
{
    return ( m_subtest_totalPasses == m_subtest_totalTests );
}
