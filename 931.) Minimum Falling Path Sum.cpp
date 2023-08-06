class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int minValue = INT_MAX;

        for (int i = 0; i < n; i++)
            dp[0][i] = matrix[0][i];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int left = INT_MAX, right = INT_MAX, center;
                if (j != 0)
                    left = dp[i - 1][j - 1];
                center = dp[i - 1][j];
                if (j != n - 1)
                    right = dp[i - 1][j + 1];

                dp[i][j] = matrix[i][j] + min({left, center, right});
            }
        }

        for (int i = 0; i < n; i++)
            minValue = min(minValue, dp[n - 1][i]);

        return minValue;
    }
};