
#include "pch.h"

#ifndef TIMESPAN_H
#define TIMESPAN_H
#include <string>
#include <iostream>
#include "TimeSpan.h"
using namespace std;

int main()
{
	//Test for ==
	if (TimeSpan(1.5, 4, -10) == TimeSpan(1, 33, 50))
	{
		cout << "Operator == test passed." << endl;
	}
	else
	{
		cout << "Operator == test failed." << endl;
	}

	//Test for !=
	if (TimeSpan(1.5, 4, -10) != TimeSpan(1, 33, 50))
	{
		cout << "Operator != test failed." << endl;
	}
	else
	{
		cout << "Operator != test passed." << endl;
	}

	
	TimeSpan duration1(1, 2, 3);
	cout << "duration1 =" << duration1<<endl;
	TimeSpan duration2(1.5, 4, -10);
	cout << "duration2 =" << duration2<<endl;
	TimeSpan duration3(7, 3);
	cout << "duration3 =" << duration3<<endl;
	TimeSpan duration4;
	cout << "duration4 =" << duration4<<endl;
	TimeSpan duration5(2, -7, 3.2);
	cout << "duration5 =" << duration5 << endl;
	TimeSpan duration6(3, 5, 6.8);
	cout << "duration6 =" << duration6 << endl;

	//Test for input and output
	cout << "Please input time: " << endl;
	TimeSpan duration7;
	cin >> duration7 ;
	cout << duration7 << endl;
	cout << "The hours of input is: "<< duration7.getHours() << endl;
	cout << "The minutes of input is: "<<duration7.getMinutes() << endl;
	cout << "The seconds of input is: "<<duration7.getSeconds() << endl;


	//Test operator +
	TimeSpan duration8;
	duration8 = duration6 + duration5;
	if (duration8 == TimeSpan(5,-2,10))
	{
		cout << "Operator + test passed." << endl;
	}
	else
	{
		cout << "Operator + test failed." << endl;
	}

	//Test operator +=
	duration6 += duration5;
	if (duration6 == TimeSpan(5, -2, 10))
	{
		cout << "Operator += test passed." << endl;
	}
	else
	{
		cout << "Operator += test failed." << endl;
	}
	
	//Test operator -
	TimeSpan duration9;
	duration9 = duration2 - duration1;
	if (duration9 == TimeSpan(0.5, 1, 47))
	{
		cout << "Operator - test passed." << endl;
	}
	else
	{
		cout << "Operator - test failed." << endl;
	}

	//Test operator -=
	duration2 -= duration1;
	if (duration2 == TimeSpan(0.5, 1, 47))
	{
		cout << "Operator -= test passed." << endl;
	}
	else
	{
		cout << "Operator -= test failed." << endl;
	}

	//Test for -()
	TimeSpan duration10 = TimeSpan(-1, -2, -3);
	if (duration10 == -duration1)
	{
		cout << "Operator Negation- test passed." << endl;
	}
	else
	{
		cout << "Operator Negation- test failed." << endl;
	}

	//Test for setTime()
	duration10.setTime(5, 3, 2);
	cout << "Set D10: 5, 3 2," << endl;
	cout << "D10=" << duration10 << endl;
}

#endif