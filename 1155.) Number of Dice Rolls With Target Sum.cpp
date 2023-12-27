class Solution
{
    int MOD = 1e9 + 7;

public:
    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= target; j++)
            {
                long long counter = 0;
                for (int x = 1; x <= k && x <= j; x++)
                {
                    counter = counter + dp[i - 1][j - x];
                    counter %= MOD;
                }
                dp[i][j] = counter;
            }
        }
        return dp[n][target];
    }
};