// GetDailyData.h
// Thomas Wise
// COSC 2030
// Project01
// 26 Oct 2018

#include "LongNumber.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

#ifndef GET_DAILY_DATA_H
# define GET_DAILY_DATA_H

void getDailyData(int day, longNumber& prevDCount, longNumber& sumD, longNumber& sumW, longNumber& countD, longNumber& countW, float& minD, float& minW, float& maxD, float& maxW, longNumber& highDiffVal, int highDiffDay);
void showDailySummary(int day, longNumber& sum, longNumber& count, float& min, float& max);
void showWeeklySummary(int week, longNumber& sum, longNumber& count, float& min, float& max, int highDiffDay);
#endif
