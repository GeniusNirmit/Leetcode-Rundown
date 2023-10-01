class Solution
{
public:
    long long maximumTripletValue(vector<int> &a)
    {
        int n = a.size();
        long long maxVal = INT_MIN;
        vector<int> maxLeft(n), maxRight(n);
        maxLeft[0] = a[0];
        maxRight[n - 1] = a[n - 1];

        for (int i = 1; i < n; i++)
            maxLeft[i] = max(maxLeft[i - 1], a[i]);

        for (int i = n - 2; i >= 0; i--)
            maxRight[i] = max(maxRight[i + 1], a[i]);

        for (int i = 1; i < n - 1; i++)
        {
            long long val = (long long)(maxLeft[i - 1] - a[i]) * maxRight[i + 1];
            if (maxVal < val)
                maxVal = val;
        }

        if (maxVal < 0)
            return 0;
        return maxVal;
    }
};