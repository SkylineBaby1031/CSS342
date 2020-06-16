#include "pch.h"
#ifndef TIMESPAN_H
#define TIMESPAN_H
#include <iostream>
#include "TimeSpan.h"
using namespace std;


TimeSpan::TimeSpan()
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}

TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
	int num = toSeconds(hours, minutes, seconds);
	this->hours = num / 3600;
	num = num % 3600;
	this->minutes = num / 60;
	this->seconds = num % 60;

}

TimeSpan::TimeSpan(double minutes, double seconds)
{
	this->hours = 0;
	int num = toSeconds(hours, minutes, seconds);
	this->minutes = num / 60;
	this->seconds = num % 60;
}

TimeSpan::~TimeSpan()
{
}

int TimeSpan::getHours() const
{
	return hours;
}

int TimeSpan::getMinutes() const
{
	return minutes;
}
int TimeSpan::getSeconds() const
{
	return seconds;
}

TimeSpan TimeSpan::operator+(const TimeSpan &num) const
{
	TimeSpan time = *this;
	time += num;
	return time;
}

TimeSpan& TimeSpan::operator+=(const TimeSpan &num)
{
	int a = toSeconds(hours, minutes, seconds);
	int b = toSeconds(num.hours, num.minutes, num.seconds);
	int number = a + b;
	hours = number / 3600;
	number = number % 3600;
	minutes = number / 60;
	seconds = number % 60;

	return *this;
}

TimeSpan TimeSpan::operator-(const TimeSpan &num) const
{
	TimeSpan time = *this;
	time -= num;
	return time;
}

TimeSpan& TimeSpan::operator-=(const TimeSpan &num)
{
	int a = toSeconds(hours, minutes, seconds);
	int b = toSeconds(num.hours, num.minutes, num.seconds);
	int number = a - b;
	hours = number / 3600;
	number = number % 3600;
	minutes = number / 60;
	seconds = number % 60;

	return *this;
}

TimeSpan TimeSpan::operator-() const
{
	TimeSpan temp;
	temp.hours = -hours;
	temp.minutes = -minutes;
	temp.seconds = -seconds;
	return temp;
}

bool TimeSpan::operator==(const TimeSpan &num) const
{
	return(toSeconds(hours,minutes,seconds) == toSeconds(num.hours, num.minutes, num.seconds));
}

bool TimeSpan::operator!=(const TimeSpan &num) const
{
	return(toSeconds(hours, minutes, seconds) != toSeconds(num.hours, num.minutes, num.seconds));
}

ostream& operator<<(ostream &outStream, const TimeSpan &num)
{
	outStream << "Hours: "<<num.hours << ", Minutes: " << num.minutes<<", Seconds: "<<num.seconds;
	return outStream;
}

istream& operator>>(istream &inStream, TimeSpan &num)
{
	inStream >> num.hours>> num.minutes>>num.seconds;
	num.toTime();
	return inStream;
}

bool TimeSpan::setTime(double hours, double minutes, double seconds)
{
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
	return true;
}
int TimeSpan::toSeconds(double hours, double minutes, double seconds) const
{
	double num = 0;
	num += (hours * 3600);
	num += (minutes * 60.0);
	num += seconds;
	num = round(num);
	return num;
}
void TimeSpan::toTime()
{
	int num = toSeconds(hours, minutes, seconds);
	hours = num / 3600;
	num = num % 3600;
	minutes = num / 60;
	seconds = num % 60;
	//cout << "Hours: " << a << ", Minutes: " << b << ", Seconds: " << c << endl;
}
#endif