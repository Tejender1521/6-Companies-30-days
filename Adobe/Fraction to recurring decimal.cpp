#include<bits/stdc++.h>

using namespace std;
class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
        {
            return "0";
        }
        std::string result;
        if (numerator < 0 ^ denominator < 0)
        {
            result += "-";
        }
        long long numer = numerator;
        long long denom = denominator;
        numer = std::abs(numer);
        denom = std::abs(denom);
        result += std::to_string(numer / denom);
        long long remainder = numer % denom;
        if (remainder == 0)
        {
            return result;
        }
        result += ".";
        remainder *= 10;
        std::map<long long, int> seenRemainders;
        while (remainder)
        {
            if (seenRemainders.find(remainder) != seenRemainders.end())
            {
                result.insert(seenRemainders[remainder], "(");
                result += ")";
                break;
            }
            seenRemainders[remainder] = result.size();
            result += std::to_string(remainder / denom);
            remainder = (remainder % denom) * 10;
        }
        return result;
    }
};