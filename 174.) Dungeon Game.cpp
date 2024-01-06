class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++)
            dp[i][n] = 1e9;
        for (int i = 0; i <= n; i++)
            dp[m][i] = 1e9;
        dp[m][n - 1] = 1;
        dp[m - 1][n] = 1;

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int currentHealth = min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j];

                if (currentHealth <= 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = currentHealth;
            }
        }
        return dp[0][0];
    }
};