#include<bits/stdc++.h>

using namespace std;

class StockPrice
{
public:
    unordered_map<int, int> mp;

    multiset<int> s;

    int max_time = 0;

    StockPrice()
    {
    }

    void update(int timestamp, int price)
    {

        if (mp.count(timestamp))
        {
            auto it = s.find(mp[timestamp]);

            s.erase(it);
        }

        max_time = max(max_time, timestamp);

        mp[timestamp] = price;

        s.insert(price);
    }

    int current()
    {

        return mp[max_time];
    }

    int maximum()
    {

        return *s.rbegin();
    }

    int minimum()
    {

        return *s.begin();
    }
};
/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

