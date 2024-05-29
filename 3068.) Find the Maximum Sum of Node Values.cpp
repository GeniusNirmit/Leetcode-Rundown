class Solution
{
    long long maxSumOfNodes(int ind, int isEven, vector<int> &a, int k, vector<vector<long long>> &dp)
    {
        int n = a.size();
        if (ind == n && isEven)
            return 0;

        if (ind == n && !isEven)
            return INT_MIN;

        if (dp[ind][isEven] != -1)
            return dp[ind][isEven];

        long long noXorDone = a[ind] + maxSumOfNodes(ind + 1, isEven, a, k, dp);
        long long xorDone = (a[ind] ^ k) + maxSumOfNodes(ind + 1, isEven ^ 1, a, k, dp);

        return dp[ind][isEven] = max(xorDone, noXorDone);
    }

public:
    long long maximumValueSum(vector<int> &a, int k, vector<vector<int>> &edges)
    {
        int n = a.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return maxSumOfNodes(0, 1, a, k, dp);
    }
};