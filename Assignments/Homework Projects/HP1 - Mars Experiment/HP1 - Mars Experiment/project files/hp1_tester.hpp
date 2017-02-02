/*
DON'T MODIFY THIS FILE
*/

#ifndef _HP1_TESTER	// Don't allow duplicates
#define _HP1_TESTER	// Don't allow duplicates

#include <iostream>
#include <string>
using namespace std; 

#include "cuTEST/TesterBase.hpp"
#include "cuTEST/Menu.hpp"
#include "cuTEST/StringUtil.hpp"

#include "hp1_program.hpp"

class Tester : public TesterBase
{
public:
	Tester()
	{
		AddTest(TestListItem("AdjustFood()", bind(&Tester::TestAdjustFood, this)));
		AddTest(TestListItem("AdjustWaste()", bind(&Tester::TestAdjustOxygen, this)));
		AddTest(TestListItem("AdjustOxygen()", bind(&Tester::TestAdjustWaste, this)));
	}

private:
	int TestAdjustFood()
	{
		DisplayTestHeader("TestAdjustFood()");

		int totalTests = 0, totalSuccess = 0;

		int fcInputs[2] = { 100, 50 };	// food count
		int fgInputs[2] = { 5, 2 };		// food grown
		int tsInputs[2] = { 2, 5 };		// team size
		int d1Outputs[2] = { 101, 42 }; // day 1 output
		int d2Outputs[2] = { 102, 34 }; // day 2 output

		for (int i = 0; i < 2; i++)
		{
			Program program;
			program.SetFoodCount(fcInputs[i]);
			program.SetFoodGrown_PerDay(fgInputs[i]);
			program.SetTeamSize(tsInputs[i]);

			totalTests++;
			program.AdjustFood();
			if (program.GetFoodCount() != d1Outputs[i])
			{
				string message = "Incorrect calculation! \nVARIABLES\n(FoodCount: "
					+ StringUtil::ToString(fcInputs[i]) + ", FoodGrown_PerDay: "
					+ StringUtil::ToString(fgInputs[i]) + ", TeamSize: "
					+ StringUtil::ToString(tsInputs[i])
					+ ", Days: 1)\nEXPECTED OUTPUT: "
					+ StringUtil::ToString(d2Outputs[i]) + " \nACTUAL OUTPUT: "
					+ StringUtil::ToString(program.GetFoodCount());

				ReportFailure("TestAdjustFood()", message);
			}
			else
			{
				totalSuccess++;
			}

			totalTests++;
			program.AdjustFood();
			if (program.GetFoodCount() != d2Outputs[i])
			{
				string message = "Incorrect calculation! \nVARIABLES\n(FoodCount: "
					+ StringUtil::ToString(fcInputs[i]) + ", FoodGrown_PerDay: "
					+ StringUtil::ToString(fgInputs[i]) + ", TeamSize: "
					+ StringUtil::ToString(tsInputs[i])
					+ ", Days: 2)\nEXPECTED OUTPUT: "
					+ StringUtil::ToString(d2Outputs[i]) + "\nACTUAL OUTPUT: "
					+ StringUtil::ToString(program.GetFoodCount());

				ReportFailure("TestAdjustFood()", message);
			}
			else
			{
				totalSuccess++;
			}
		}

		DisplayScore(totalSuccess, totalTests);

		return (totalSuccess == totalTests);
	}

	int TestAdjustOxygen()
	{
		DisplayTestHeader("TestAdjustOxygen()");

		int totalTests = 0, totalSuccess = 0;

		int ocInputs[2] = { 100, 50 };	// oxygen count
		int tsInputs[2] = { 2, 5 };		// team size
		int d1Outputs[2] = { 101, 45 };	// day 1 output
		int d2Outputs[2] = { 102, 40 };	// day 2 output

		for (int i = 0; i < 2; i++)
		{
			Program program;
			program.SetOxygenCount(ocInputs[i]);
			program.SetTeamSize(tsInputs[i]);

			totalTests++;
			program.AdjustOxygen();
			if (program.GetOxygenCount() != d1Outputs[i])
			{
				string message = "Incorrect calculation! \nVARIABLES\n(OxygenCount: "
					+ StringUtil::ToString(ocInputs[i]) + ", TeamSize: "
					+ StringUtil::ToString(tsInputs[i])
					+ ", Days: 1)\nEXPECTED OUTPUT: "
					+ StringUtil::ToString(d2Outputs[i]) + " \nACTUAL OUTPUT: "
					+ StringUtil::ToString(program.GetOxygenCount());

				ReportFailure("TestAdjustOxygen()", message);
			}
			else
			{
				totalSuccess++;
			}

			totalTests++;
			program.AdjustOxygen();
			if (program.GetOxygenCount() != d2Outputs[i])
			{
				string message = "Incorrect calculation! \nVARIABLES\n(OxygenCount: "
					+ StringUtil::ToString(ocInputs[i]) + ", TeamSize: "
					+ StringUtil::ToString(tsInputs[i])
					+ ", Days: 2)\nEXPECTED OUTPUT: "
					+ StringUtil::ToString(d2Outputs[i]) + " \nACTUAL OUTPUT: "
					+ StringUtil::ToString(program.GetOxygenCount());

				ReportFailure("TestAdjustOxygen()", message);
			}
			else
			{
				totalSuccess++;
			}
		}

		DisplayScore(totalSuccess, totalTests);

		return (totalSuccess == totalTests);
	}

	int TestAdjustWaste()
	{
		DisplayTestHeader("TestAdjustWaste()");

		int totalTests = 0, totalSuccess = 0;

		int wcInputs[2]		= { 100, 50 };	// waste count
		int wclInputs[2]	= { 10, 5 };	// waste cleaned
		int tsInputs[2]		= { 5, 2 };		// team size
		int d1Outputs[2]	= { 65, 46 };	// day 1 output
		int d2Outputs[2]	= { 30, 42 };	// day 2 output

		for (int i = 0; i < 2; i++)
		{
			Program program;
			program.SetWasteCount(wcInputs[i]);
			program.SetCleanup_PerPersonPerDay(wclInputs[i]);
			program.SetTeamSize(tsInputs[i]);

			totalTests++;
			program.AdjustWaste();
			if (program.GetWasteCount() != d1Outputs[i])
			{
				string message = "Incorrect calculation! \nVARIABLES\n(WasteCount: "
					+ StringUtil::ToString(wcInputs[i]) + ", WasteCreated_PerPersonPerDay: "
					+ StringUtil::ToString(wclInputs[i]) + ", TeamSize: "
					+ StringUtil::ToString(tsInputs[i])
					+ ", Days: 1)\nEXPECTED OUTPUT: "
					+ StringUtil::ToString(d2Outputs[i]) + " \nACTUAL OUTPUT: "
					+ StringUtil::ToString(program.GetWasteCount());

				ReportFailure("TestAdjustWaste()", message);
			}
			else
			{
				totalSuccess++;
			}

			totalTests++;
			program.AdjustWaste();
			if (program.GetWasteCount() != d2Outputs[i])
			{
				string message = "Incorrect calculation! \nVARIABLES\n(WasteCount: "
					+ StringUtil::ToString(wcInputs[i]) + ", WasteCreated_PerPersonPerDay: "
					+ StringUtil::ToString(wclInputs[i]) + ", TeamSize: "
					+ StringUtil::ToString(tsInputs[i])
					+ ", Days: 2)\nEXPECTED OUTPUT: "
					+ StringUtil::ToString(d2Outputs[i]) + "\nACTUAL OUTPUT: "
					+ StringUtil::ToString(program.GetWasteCount());

				ReportFailure("TestAdjustWaste()", message);
			}
			else
			{
				totalSuccess++;
			}
		}

		DisplayScore(totalSuccess, totalTests);

		return (totalSuccess == totalTests);
	}
};

#endif