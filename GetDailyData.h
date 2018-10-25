// GetDailyData.h
// Thomas Wise
// COSC 2030
// Project01
// 24 Oct 2018

#include "LongNumber.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#ifndef GET_DAILY_DATA_H
# define GET_DAILY_DATA_H

void getDailyData(longNumber& sum, longNumber& count, float& min, float& max);
void showDailySummary(longNumber& sum, longNumber& count, float& min, float& max);
void showWeeklySummary(longNumber& sum, longNumber& count, float& min, float& max);
#endif
