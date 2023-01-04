#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        int min_x = INT_MAX, min_y = INT_MAX;
        int max_x = INT_MIN, max_y = INT_MIN;

        int total_area = 0;

        for (const auto &rectangle : rectangles)
        {
            min_x = min(min_x, rectangle[0]);
            min_y = min(min_y, rectangle[1]);
            max_x = max(max_x, rectangle[2]);
            max_y = max(max_y, rectangle[3]);

            total_area += (rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);
        }

        int width = max_x - min_x;
        int height = max_y - min_y;
        int region_area = width * height;

        return total_area == region_area;
    }
};