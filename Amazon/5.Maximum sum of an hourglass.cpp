#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int hourglass(vector<vector<int>> &grid, int i, int j)
    {
        return grid[i][j] + grid[i][j + 1] + grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
    }
    int maxSum(vector<vector<int>> &grid)
    {
        int sum = 0;
        for (int i = 0; i < grid.size() - 2; i++)
        {
            for (int j = 0; j < grid[0].size() - 2; j++)
            {
                sum = max(sum, hourglass(grid, i, j));
            }
        }
        return sum;
    }
};