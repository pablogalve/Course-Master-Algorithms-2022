#include<bits/stdc++.h>
using namespace std;

void printGrid(vector<vector<int>> &grid)
{
	for(int i = 0; i < grid.size(); ++i)
	{
		for(int j = 0; j < grid[i].size(); ++j)
		{
			cout << grid[i][j] << " ";
		}				
		cout << endl;
	}
}

void updateRows(vector<vector<int>> &grid)
{
	for(int i = 0; i < grid.size(); ++i)
	{
		if(grid[i][0] == 0)
		{
			for(int j = 0; j < grid[i].size(); ++j)
			{
				grid[i][j] = !(grid[i][j] & 1);
			}
		}		
	}
}

void updateColumns(vector<vector<int>> &grid)
{
	for(int j = 0; j < grid[0].size(); ++j)
	{
		int zeroCount = 0;
		int oneCount = 0;
		for(int i = 0; i < grid.size(); ++i)
		{
			if(grid[i][j] == 0) zeroCount++;
			else oneCount++;
		}
		if(zeroCount > oneCount)
		{	
			for(int i = 0; i < grid.size(); ++i)
			{		
				grid[i][j] = !(grid[i][j] & 1);
			}
		}
	}
}

int countScore(vector<vector<int>> &grid)
{
	int ret = 0;
	for(int i = 0; i < grid.size(); ++i)
	{	
		int num = 0;
		for(int j = 0; j < grid[i].size(); ++j)
		{
			if(grid[i][j] & 1)
				num += pow(2, grid[i].size() - 1 - j);
		}
		ret += num;
	}
	return ret;
}

int matrixScore(vector<vector<int>> grid) {
    //cout << "BEFORE" << endl;
	//printGrid(grid);

	updateRows(grid);
	updateColumns(grid);

	//cout << endl << "AFTER" << endl;
	//printGrid(grid);

    return countScore(grid);
}