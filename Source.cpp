#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define empty 0
#define N 9

bool isGridSafe(int grid[N][N], int row, int col, int num);
bool isEmptyLocation(int grid[N][N], int& row, int& col);

bool SolveSudoku(int grid[N][N])
{
	int row, col;
	if (!isEmptyLocation(grid, row, col))
		return true;
	for (int num = 1; num <= 9; num++)
	{
		if (isGridSafe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (SolveSudoku(grid))
				return true;
			grid[row][col] = empty;
		}
	}
	return false;
}

bool isEmptyLocation(int grid[N][N], int& row, int& col)
{
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (grid[row][col] == empty)
				return true;
	return false;
}

bool UsedInRow(int grid[N][N], int rrow, int number)
{
	for (int col = 0; col < N; col++)
		if (grid[rrow][col] == number)
			return true;
	return false;
}

bool UsedInCol(int grid[N][N], int coll, int number)
{
	for (int row = 0; row < N; row++)
		if (grid[row][coll] == number)
			return true;
		else
			return false;
}

bool UsedInBox(int grid[N][N], int boxBeginRow, int boxBeginCol, int number)
{
	bool state = false;
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[row + boxBeginRow][col + boxBeginCol] == number)
				state = true;
	return state;
}

bool isGridSafe(int grid[N][N], int prow, int pcol, int number)
{
	return !UsedInRow(grid, prow, number) && !UsedInCol(grid, pcol, number) &&
		!UsedInBox(grid, prow - prow % 3, pcol - pcol % 3, number);
}

void printResult(int finalgrid[N][N])
{
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
			std::cout << finalgrid[row][col] << "  ";
		std::cout << std::endl;
	}
}

int main()
{
	int grid[N][N] = {
					  {0, 0, 0, 0, 0, 0, 0, 0, 0},
					  {0, 0, 0, 0, 0, 3, 0, 8, 5},
					  {0, 0, 1, 0, 2, 0, 0, 0, 0},
					  {0, 0, 0, 5, 0, 7, 0, 0, 0},
					  {0, 0, 4, 0, 0, 0, 1, 0, 0},
					  {0, 9, 0, 0, 0, 0, 0, 0, 0},
					  {5, 0, 0, 0, 0, 0, 0, 7, 3},
					  {0, 0, 2, 0, 1, 0, 0, 0, 0},
					  {0, 0, 0, 0, 4, 0, 0, 0, 9}
	};

	if (SolveSudoku(grid) == true)
		printResult(grid);
	else
		std::cout << "Something went wrong!" << std::endl;
	return 0;
}
