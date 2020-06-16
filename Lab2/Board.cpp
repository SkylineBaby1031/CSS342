
#include "Board.h"
#include <iostream>
#include<vector>
using namespace std;


Board::Board()
{
	this->row = 0;
	this->col = 0;
}
Board::Board(int row, int col, vector<int> li) 
{
	this->row = row;
	this->col = col;
	this->list = li;
}
Board::~Board()
{
}

int Board::getRow() const
{
	return row;
}

int Board::getCol() const
{
	return col;
}

vector<int> Board::getList() const
{
	return list;
}