#include "MyTime.h"
#include<iomanip>
#include<iostream>
using namespace std;
Time::Time()
{
	hour = 0;
	minute = 0;
}
Time::Time(int h, int m)
{
	hour = h;
	minute = m;
	normalizeTime();
}
void Time::setTime(int h, int m)
{
	hour = h;
	minute = m;
	normalizeTime();
}
void Time::normalizeTime()
{
	if (minute >= 60)
	{
		while (minute >= 60)
		{
		hour += minute % 60;
		minute %= 60;
		}
	}
	if (hour >= 24)
	{
		while(hour>=24)
		hour %= 24;
	}
}
void Time::output()
{
	cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << endl;
}
int Time::getHour()
{
	return hour;
}
int Time::getMinute()
{
	return minute;
}
int Time::getTotalMinutes()
{
	return hour * 60 + minute;
}
