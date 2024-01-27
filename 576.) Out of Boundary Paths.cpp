class Solution
{
    long long MOD = 1e9 + 7;

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return moveBall(m, n, startRow, startColumn, maxMove, dp);
    }
    int moveBall(int &m, int &n, int row, int col, int maxMove, vector<vector<vector<int>>> &dp)
    {
        if (row < 0 || row > m - 1 || col < 0 || col > n - 1)
            return 1;
        if (maxMove == 0)
            return 0;
        if (dp[row][col][maxMove] != -1)
            return dp[row][col][maxMove];

        int up = moveBall(m, n, row - 1, col, maxMove - 1, dp);
        int down = moveBall(m, n, row + 1, col, maxMove - 1, dp);
        int left = moveBall(m, n, row, col - 1, maxMove - 1, dp);
        int right = moveBall(m, n, row, col + 1, maxMove - 1, dp);

        return dp[row][col][maxMove] = (up % MOD + down % MOD + left % MOD + right % MOD) % MOD;
    }
};