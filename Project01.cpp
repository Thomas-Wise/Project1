// Project01.cpp
// Thomas Wise
// COSC 2030
// Project01
// 26 Oct 2018

#include <iostream>
#include "LongNumber.h"
#include "GetDailyData.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int day;
	int week;
	longNumber sumD[14];
	longNumber countD[14];
	float minD[14];
	float maxD[14];
	longNumber sumW[2];
	longNumber countW[2];
	float minW[2];
	float maxW[2];
	longNumber highDiffVal[2];
	int highDiffDay[2];
	for (day = 0; day < 14; day++)
	{
		minD[day] = FLT_MAX;
		maxD[day] = 0;
	}

	for (week = 0; week < 2; week++)
	{
		minW[week] = FLT_MAX;
		maxW[week] = 0;
		highDiffVal[week] = 0;
		highDiffDay[week] = 0;
	}

	for (day = 0; day < 14; day++)
	{
		int prevD = 0;
		if (day != 0)
		{
			prevD = day - 1;
		}
		week = day / 7;
		getDailyData(day, countD[prevD], sumD[day], sumW[week], countD[day], countW[week], minD[day], minW[week], maxD[day], maxW[week], highDiffVal[week], highDiffDay[week]);
	}

	cout << "Final Results:" << endl;
	for (day = 0; day < 14; day++)
	{
		showDailySummary(day, sumD[day], countD[day], minD[day], maxD[day]);
	}
	cout << endl << endl;
	for (week = 0; week < 2; week++)
	{
		showWeeklySummary(week, sumW[week], countW[week], minW[week], maxW[week], highDiffDay[week]);
	}
}