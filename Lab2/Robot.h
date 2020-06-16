
#include <iostream>
#include  "Board.h"
//#ifndef ADD_H
//#define ADD_H
#include<vector>
#include <string>

using namespace std;
class Robot {
public:
	Robot();
	Robot(int MaxStepsDir, int x, int y, int end_x, int end_y);
	~Robot();
	void FindPath(Board board);
	void FindPathHelper(Board b, int** matrix, bool** visit, string curr, int steps, int total, int dir, int r, int c);

	
private:
	int MaxStepsDir;
	int x;
	int y;
	int end_x;
	int end_y;
	string * ans;
    int * count;
};

//#endif
