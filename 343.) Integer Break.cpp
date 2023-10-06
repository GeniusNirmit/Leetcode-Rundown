class Solution
{
public:
    int integerBreak(int n)
    {
        if (n <= 3)
            return n - 1;

        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        for (int i = 1; i <= n; i++)
        {
            int maxVal = i;
            for (int j = 2; j < i; j++)
                maxVal = max(maxVal, j * dp[i - j]);
            dp[i] = maxVal;
        }
        return dp[n];
    }
};