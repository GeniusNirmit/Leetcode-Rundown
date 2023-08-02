// Tabulation

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (obstacleGrid[i - 1][j - 1] == 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};

// Memoization

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1)
            return 0;
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        return findPaths(obstacleGrid, dp, obstacleGrid.size() - 1, obstacleGrid[0].size() - 1, 0, 0);
    }
    int findPaths(vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp, int m, int n, int row, int col)
    {
        if (row == m && col == n)
            return dp[row][col] = 1;
        if (row > m || col > n || obstacleGrid[row][col] == 1)
            return 0;
        if (dp[row][col] != -1)
            return dp[row][col];

        return dp[row][col] = findPaths(obstacleGrid, dp, m, n, row + 1, col) + findPaths(obstacleGrid, dp, m, n, row, col + 1);
    }
};