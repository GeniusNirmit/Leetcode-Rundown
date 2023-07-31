// Tabulation

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m == 1 && n == 1)
            return 1;
        vector<vector<int>> dp(m, vector<int>(n, 1));
        dp[0][0] = 0;

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Memoization

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return traverse(0, 0, m - 1, n - 1, dp);
    }
    int traverse(int row, int col, int m, int n, vector<vector<int>> &dp)
    {
        if (row == m && col == n)
            return dp[row][col] = 1;
        if (row > m)
            return 0;
        if (col > n)
            return 0;
        if (dp[row][col] != -1)
            return dp[row][col];

        return dp[row][col] = traverse(row + 1, col, m, n, dp) + traverse(row, col + 1, m, n, dp);
    }
};