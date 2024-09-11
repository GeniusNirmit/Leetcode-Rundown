class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        return __builtin__popcount(start ^ goal);
    }
};