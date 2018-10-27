// GetDailyData.cpp
// Thomas Wise
// COSC 2030
// Project01
// 26 Oct 2018

#include "GetDailyData.h"

// This takes user input to manipulate all of the data and display it to the user.
void getDailyData(int day, longNumber& prevDCount, longNumber& sumD, longNumber& sumW, longNumber& countD, longNumber& countW, float& minD, float& minW, float& maxD, float& maxW, longNumber& highDiffVal, int highDiffDay)
{
	bool done = false;
	char command;
	float input;
	string trash;
	int week = day / 7;
	cout << "Please enter blood sugar levels for day " << (day + 1) << "(d for daily summary, w for weekly summary, n to go to next day):" << endl;
	while (!done) // Loops until user enters n or N
	{
		while (!done && !(cin >> input))
		{
			// This whole section deals with non-numeric entries, so displaying values and going
			// to the next day will be here.
			cin.clear();
			cin >> command;
			if (command == 'D' || command == 'd')
			{
				showDailySummary(day, sumD, countD, minD, maxD);
				cout << "Please enter blood sugar levels for day " << (day + 1) << "(d for daily summary, w for weekly summary, n to go to next day):" << endl;
			}
			else if (command == 'W' || command == 'w')
			{
				showWeeklySummary(week, sumW, countW, minW, maxW, highDiffDay);
				cout << "Please enter blood sugar levels for day " << (day + 1) << "(d for daily summary, w for weekly summary, n to go to next day):" << endl;
			}
			else if (command == 'N' || command == 'n')
			{
				showDailySummary(day, sumD, countD, minD, maxD);
				done = true;
				trash = "";
				getline(cin, trash); // Empties cin so nothing entered after n can affect the next day's values.
				//
				// Handles the highest delta day part
				if (day != 0 && day != 7)
				{
					if ((countD - prevDCount) > highDiffVal)
					{
						highDiffDay = day % 7;
					}
				}
			}
		}
		// Handles max and min values
		if (!done)
		{
			if (input > 0)
			{
				sumD = sumD + input;
				sumW = sumW + input;
				countD = countD + 1;
				countW = countW + 1;
				if (input < minD)
				{
					minD = input;
				}
				else if (input > maxD)
				{
					maxD = input;
				}
				if (input < minW)
				{
					minW = input;
				}
				else if (input > maxW)
				{
					maxW = input;
				}
			}
		}
	}
}

// Shows user the daily summary so far.
void showDailySummary(int day, longNumber& sum, longNumber& count, float& min, float& max)
{
	cout << endl << endl;
	cout << "Daily Data for day " << (day + 1) << ":" << endl;
	cout << "Sum: " << sum << endl;
	cout << "Count: " << count << endl;
	cout << "Min: " << min << endl;
	cout << "Max: " << max << endl << endl;
}

// Shows the user the weekly summary so far.
void showWeeklySummary(int week, longNumber& sum, longNumber& count, float& min, float& max, int highDiffDay)
{
	cout << endl << endl;
	cout << "Weekly Data for week " << (week + 1) << ":" << endl;
	cout << "Sum: " << sum << endl;
	cout << "Count: " << count << endl;
	cout << "Min: " << min << endl;
	cout << "Max: " << max << endl;
	cout << "Day with greatest difference: " << highDiffDay << endl << endl;
}