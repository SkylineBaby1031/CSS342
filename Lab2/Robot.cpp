
#include "Robot.h"
#include "Board.h"
#include <string>
#include <iostream>
//#ifndef ADD_H
//#define ADD_H
using namespace std;

Robot::Robot()
{
	this->MaxStepsDir = 0;
	this->x = 0;
	this->y = 0;
	this->x = 0;
	this->y = 0;
}

Robot::Robot(int MaxStepsDir, int x, int y, int end_x, int end_y)
{
	this->MaxStepsDir = MaxStepsDir;
	this->x = x;
	this->y = y;
	this->end_x = end_x ;
	this->end_y = end_y;
}

Robot::~Robot()
{
}

void Robot::FindPath(Board board) {
	int** matrix = new int*[board.getRow()];
	bool** visit = new bool*[board.getRow()];
	for(int i = 0; i < board.getRow(); i++) {
		matrix[i] = new int[board.getCol()];
		visit[i] = new bool[board.getCol()];
	}

	for(int i = 0; i < board.getRow(); i++) {
		for(int j = 0; j < board.getCol(); j++) {
			matrix[i][j] = 0;
			visit[i][j] = false;
		}
	}

	visit[x][y] = true;

	if(board.getList().size() >= 2) {
		for (int i = 0; i < board.getList().size() - 1; i += 2) {
			matrix[board.getList()[i]][board.getList()[i + 1]] = -1;
		}
	}

	matrix[end_x][end_y] = 1;

	int max = board.getRow() * board.getCol() + 1;
	ans = new string[max];
	count = new int[max];
	for(int i = 0 ; i < max ; i ++) {
		count[i] = 0;
	}

	for (int i = 0; i < max; i++) {
		ans[i] = "";
	}
	FindPathHelper(board, matrix, visit, "", 0, 0, 0, x, y);

	for (int i = 0; i < max; i++)
	{
		// Check the first non-empty string, whcih is the shortest path we saved before
		if (ans[i].compare("") != 0)
		{
			cout << ans[i];
			cout << "\nNumber of Nodes: ";
			cout << count[i] << "\n";
			break;
		}
	}

}


void Robot::FindPathHelper(Board b, int** matrix, bool** visit, string curr, int steps, int total, int dir, int r, int c)
{

	if (matrix[r][c] == 1) {
		ans[total] = ans[total] + "\n" + curr;
		count[total]++;
		return;
	}


	// East x + 1, y   By 1
	if (r + 1 < b.getRow() && matrix[r + 1][c] != -1 && !visit[r + 1][c])
	{
		if (MaxStepsDir != 0)
		{
			if (dir == 1)
			{
				if (steps < MaxStepsDir)
				{
					visit[r + 1][c] = true;
					FindPathHelper(b, matrix, visit, curr + "E", steps + 1, total + 1, 1, r + 1, c);
					visit[r + 1][c] = false;
				} // else can't keep going
			}
			else
			{
				visit[r + 1][c] = true;
				FindPathHelper(b, matrix, visit, curr + "E", 1, total + 1, 1, r + 1, c);
				visit[r + 1][c] = false;
			}
		}
		else
		{
			//cout << "Going east\n";
			visit[r + 1][c] = true;
			FindPathHelper(b, matrix, visit, curr + "E", 0, total + 1, 1, r + 1, c);
			visit[r + 1][c] = false;
		}
	}


	// South x, y - 1   By 2
	if (c - 1 >= 0 && matrix[r][c - 1] != -1 && !visit[r][c - 1])
	{
		if (MaxStepsDir != 0)
		{
			if (dir == 2)
			{
				if (steps < MaxStepsDir)
				{
					visit[r][c - 1] = true;
					FindPathHelper(b, matrix, visit, curr + "S", steps + 1, total + 1, 2, r, c - 1);
					visit[r][c - 1] = false;
				} // else can't keep going
			}
			else
			{
				visit[r][c - 1] = true;
				FindPathHelper(b, matrix, visit, curr + "S", 1, total + 1, 2, r, c - 1);
				visit[r][c - 1] = false;
			}
		}
		else
		{
			//cout << "Going South\n";
			visit[r][c - 1] = true;
			FindPathHelper(b, matrix, visit, curr + "S", 0, total + 1, 2, r, c - 1);
			visit[r][c - 1] = false;
				}
			}

	// West x - 1, y     By 3
	if (r - 1 >= 0 && matrix[r - 1][c] != -1 && !visit[r - 1][c])
	{
		if (MaxStepsDir != 0)
		{
			if (dir == 3)
			{
				if (steps < MaxStepsDir)
				{
					visit[r - 1][c] = true;
					FindPathHelper(b, matrix, visit, curr + "W", steps + 1, total + 1, 3, r - 1, c);
					visit[r - 1][c] = false;
				} // else can't keep going
			}
			else
			{
				visit[r - 1][c] = true;
				FindPathHelper(b, matrix, visit, curr + "W", 1, total + 1, 3, r - 1, c);
				visit[r - 1][c] = false;
			}
		}
		else
		{
			//cout << "Going west\n";
			visit[r - 1][c] = true;
			FindPathHelper(b, matrix, visit, curr + "W", 0, total + 1, 3, r - 1, c);
			visit[r - 1][c] = false;
		}
	}
	// North x, y + 1     By 4
	if (c + 1 < b.getCol() && matrix[r][c + 1] != -1 && !visit[r][c + 1])
	{
		if (MaxStepsDir != 0)
		{
			if (dir == 4)
			{
				if (steps < MaxStepsDir)
				{
					visit[r][c + 1] = true;
					FindPathHelper(b, matrix, visit, curr + "N", steps + 1, total + 1, 4, r, c + 1);
					visit[r][c + 1] = false;
				} // else can't keep going
			}
			else
			{
				visit[r][c + 1] = true;
				FindPathHelper(b, matrix, visit, curr + "N", 1, total + 1, 4, r, c + 1);
				visit[r][c + 1] = false;
			}
		}
		else
		{
			//cout << "Going North\n";
			visit[r][c + 1] = true;
			FindPathHelper(b, matrix, visit, curr + "N", 0, total + 1, 4, r, c + 1);
			visit[r][c + 1] = false;
		}
	}
}

