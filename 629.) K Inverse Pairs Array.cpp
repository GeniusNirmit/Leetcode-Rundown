class Solution
{
    long long MOD = 1e9 + 7;

public:
    int kInversePairs(int n, int k)
    {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                int counter = 0;
                for (int l = 0; l < min(i, j + 1); l++)
                {
                    counter += dp[i - 1][j - l];
                    counter %= MOD;
                }
                dp[i][j] = counter;
            }
        }

        return dp[n][k];
    }
};