class Solution
{
public:
    long long MOD = 1e9 + 7;
    int countOrders(int n)
    {
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
        dp[0][0] = 1;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                long long ways = 0;

                if (i > 0)
                {
                    ways += i * dp[i - 1][j];
                    ways %= MOD;
                }

                if (j > i)
                {
                    ways += (j - i) * dp[i][j - 1];
                    ways %= MOD;
                }

                dp[i][j] = ways;
            }
        }

        return dp[n][n];
    }
};