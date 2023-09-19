class Solution
{
public:
    int countWays(vector<int> &a)
    {
        int n = a.size();
        int ways = 0;

        sort(a.begin(), a.end());

        if (a[0] > 0)
            ways++;
        if (a[n - 1] < n)
            ways++;

        for (int i = 0; i < n - 1; i++)
        {
            if (i + 1 > a[i] && i + 1 < a[i + 1])
                ways++;
        }
        return ways;
    }
};