// ConsoleApplication1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include<iostream>

using namespace std;

#define mazesize 10


class mouse
{
private:
	int starti, startj;
	int endi, endj;
public:
	void setStart(int i, int j)
	{
		starti = i; startj = j;
	};
	void setEnd(int i, int j)
	{
		endi = i; endj = j;
	};
	void visit(int maze[mazesize][mazesize], int i, int j);
	void go(int maze[mazesize][mazesize])
	{
		visit(maze, starti, startj);
	};
};


void mouse::visit(int maze[mazesize][mazesize], int i, int j)
{
	maze[i][j] = 2;

	if (i == endi && j == endj)
	{
		cout << "Find Exit.\n";
		for (int m = 0; m<mazesize; m++)
		{
			for (int n = 0; n<mazesize; n++)
			{
				if (maze[m][n] == 1)
					cout << "█";
				else if (maze[m][n] == 2)
					cout << "◎";
				else
					cout << "  ";
			}
			cout << "\n";
		}
	}
	if (maze[i][j + 1] == 0)
		visit(maze, i, j + 1);
	if (maze[i + 1][j] == 0)
		visit(maze, i + 1, j);
	if (maze[i][j - 1] == 0)
		visit(maze, i, j - 1);
	if (maze[i - 1][j] == 0)
		visit(maze, i - 1, j);
	

	maze[i][j] = 0;

};

int main()
{
	int maze[mazesize][mazesize] = 
	{ { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 1, 0, 0, 1 },
	{ 1, 0, 1, 0, 1, 1, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 1, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
	cout << "Show maze.\n";

	for (int i = 0; i<mazesize; i++)
	{
		for (int j = 0; j<mazesize; j++)
		{
			if (maze[i][j] == 1)
				cout << "█";
			else
				cout << "  ";
		}
		cout << "\n";
	}
	cout << "\n";

	mouse A1;
	int a, b, c, d;
	cout << "Set Start point.row:";
	cin >> a;
	cout << "\t\tcolumn:";
	cin >> b;
	cout << "Set End point.\trow:";
	cin >> c;
	cout << "\t\tcolumn:";
	cin >> d;
	A1.setStart(a, b);
	A1.setEnd(c, d);
	A1.go(maze);


	system("pause");
	return 0;
}

