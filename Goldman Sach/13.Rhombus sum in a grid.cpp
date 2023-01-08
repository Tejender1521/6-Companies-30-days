#include<bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> getBiggestThree(vector<vector<int>> &grid)
    {

        int max1 = 0, max2 = 0, max3 = 0, i, j;
        int len, sum;

        for (i = 0; i < grid.size(); i++)
        {
            for (j = 0; j < grid[i].size(); j++)
            {
                sum = 0;
                len = 0;
                if (i == 0 || j == 0 || i == grid.size() - 1 || j == grid[i].size() - 1)
                {
                    sum = grid[i][j];
                    if (sum > max1)
                    {
                        max3 = max2;
                        max2 = max1;
                        max1 = sum;
                    }
                    else if (sum > max2 && sum != max1)
                    {
                        max3 = max2;
                        max2 = sum;
                    }
                    else if (sum > max3 && sum != max2 && sum != max1)
                    {
                        max3 = sum;
                    }
                }
                else
                {
                    while ((i - len - 1) >= 0 && (i + len + 1) < grid.size() && (j - len - 1) >= 0 && (j + len + 1) < grid[i].size())
                    {
                        sum = 0;
                        len++;
                        sum += grid[i + len][j];
                        sum += grid[i][j + len];
                        sum += grid[i - len][j];
                        sum += grid[i][j - len];

                        for (int k = 1; k < len; k++)
                        {
                            sum += grid[i + len - k][j + k];
                            sum += grid[i - k][j + len - k];
                            sum += grid[i - len + k][j - k];
                            sum += grid[i + k][j - len + k];
                        }

                        if (sum < grid[i][j])
                            sum = grid[i][j];

                        if (sum > max1)
                        {
                            max3 = max2;
                            max2 = max1;
                            max1 = sum;
                        }
                        else if (sum > max2 && sum != max1)
                        {
                            max3 = max2;
                            max2 = sum;
                        }
                        else if (sum > max3 && sum != max2 && sum != max1)
                        {
                            max3 = sum;
                        }
                    }
                }
            }
        }
        vector<int> ans;

        if (max1 != 0)
            ans.push_back(max1);
        if (max2 != 0)
            ans.push_back(max2);
        if (max3 != 0)
            ans.push_back(max3);

        return ans;
    }
};