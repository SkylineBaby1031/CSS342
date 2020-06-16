#pragma once
#include <iostream>
using namespace std;
class TimeSpan
{
	friend ostream& operator<<(ostream &outStream, const TimeSpan &rat);
	friend istream& operator>>(istream &inStream, TimeSpan &rat);
public:
	// Constructors - Destructor
	TimeSpan();
	TimeSpan(double hours, double minutes, double seconds);
	TimeSpan(double minutes, double seconds);
	~TimeSpan();

	// Getters - Setters
	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;
	bool setTime(double hours, double minutes, double seconds);

	// Op Overloads

	TimeSpan operator-(const TimeSpan &rat) const;
	TimeSpan& operator-=(const TimeSpan &rat);

	TimeSpan operator+(const TimeSpan &rat) const;
	TimeSpan& operator+=(const TimeSpan &rat);

	TimeSpan operator-() const;

	bool operator==(const TimeSpan &rat) const;
	bool operator!=(const TimeSpan &rat) const;
private:
	int hours;
	int minutes;
	int seconds;
	int toSeconds(double hours, double minutes, double seconds) const;
	void toTime();
};

