// Approach - 1

class Solution
{
    int traverse(vector<vector<int>> &grid, int n, int row, int col, vector<vector<int>> &dp)
    {
        if (row == n - 1)
            return grid[row][col];

        if (dp[row][col] != -1)
            return dp[row][col];

        int minVal = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (i != col)
                minVal = min(minVal, traverse(grid, n, row + 1, i, dp));
        }

        minVal += grid[row][col];
        return dp[row][col] = minVal;
    }

public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int minVal = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            dp[n - 1][i] = grid[n - 1][i];

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                int currentMin = INT_MAX;
                for (int k = 0; k < n; k++)
                {
                    if (j != k)
                        currentMin = min(currentMin, dp[i + 1][k]);
                }
                dp[i][j] = grid[i][j] + currentMin;
            }
        }

        for (int i = 0; i < n; i++)
            minVal = min(minVal, dp[0][i]);

        return minVal;
    }
};