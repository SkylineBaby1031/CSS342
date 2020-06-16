
#include "Robot.h"
#include "Board.h"
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	// Test case 1
	vector<int> temp1;
	Board B1(4, 6, temp1);
	Robot R1(0, 1, 2, 3, 5);
	R1.FindPath(B1);

	// Test case 2
	vector<int> temp2;
	temp2.push_back(1);
	temp2.push_back(2);
	temp2.push_back(2);
	temp2.push_back(4);
	temp2.push_back(3);
	temp2.push_back(3);
	temp2.push_back(3);
	temp2.push_back(4);
	temp2.push_back(4);
	temp2.push_back(2);
	temp2.push_back(4);
	temp2.push_back(4);

	Board B2(5, 5, temp2);
	Robot R2(3, 1, 4, 4, 1);
	R2.FindPath(B2);

	// Test case 3
	vector<int> temp3;
	temp3.push_back(1);
	temp3.push_back(1);
	temp3.push_back(3);
	temp3.push_back(1);
	temp3.push_back(4);
	temp3.push_back(1);
	temp3.push_back(1);
	temp3.push_back(2);
	temp3.push_back(1);
	temp3.push_back(6);
	temp3.push_back(2);
	temp3.push_back(4);
	temp3.push_back(3);
	temp3.push_back(3);
	temp3.push_back(3);
	temp3.push_back(5);
	temp3.push_back(4);
	temp3.push_back(3);
	temp3.push_back(4);
	temp3.push_back(5);
	temp3.push_back(6);
	temp3.push_back(2);
	temp3.push_back(6);
	temp3.push_back(3);
	temp3.push_back(6);
	temp3.push_back(4);
	temp3.push_back(6);
	temp3.push_back(5);
	temp3.push_back(6);
	temp3.push_back(6);

	Board B3(7, 7, temp3);
	Robot R3(3, 6, 1, 2, 6);
	R3.FindPath(B3);


	return 0;
}