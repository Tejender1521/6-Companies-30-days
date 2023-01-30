#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        sort(asteroids.begin(), asteroids.end());
        long long int mas = mass;
        for (auto it : asteroids)
        {
            if (it <= mas)
            {
                mas += it;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
