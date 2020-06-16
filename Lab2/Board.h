
#include <iostream>
#include<vector>
using namespace std;
#ifndef ADD_H
#define ADD_H
class Board
{
public:
	Board();
	Board(int row, int col, vector<int> li);// : list{ std::move(li) };
	~Board();

	int getRow() const;
	int getCol() const;
	vector<int> getList() const;

private:
	int row;
	int col;
	vector<int> list;
};
#endif

