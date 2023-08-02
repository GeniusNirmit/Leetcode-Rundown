// Tabulation

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int i = 1; i < n; i++)
            dp[0][i] = dp[0][i - 1] + grid[0][i];

        vector<int> prev = dp[0];
        for (int i = 1; i < m; i++)
        {
            vector<int> current = dp[i];
            for (int j = 1; j < n; j++)
            {
                current[j] = grid[i][j] + min(prev[j], current[j - 1]);
            }
            prev = current;
        }
        return prev[n - 1];
    }
};

// Memoization

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findPath(grid, dp, m, n, 0, 0);
    }
    int findPath(vector<vector<int>> &grid, vector<vector<int>> &dp, int m, int n, int row, int col)
    {
        if (row == m - 1 && col == n - 1)
            return grid[row][col];
        if (row >= m || col >= n)
            return INT_MAX;
        if (dp[row][col] != -1)
            return dp[row][col];

        return dp[row][col] = grid[row][col] + min(findPath(grid, dp, m, n, row + 1, col), findPath(grid, dp, m, n, row, col + 1));
    }
};