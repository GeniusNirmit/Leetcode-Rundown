class Solution {    
    int MOD = 1e9 + 7;
    
    int countPaths(vector<vector<int>>& grid, int row, int col, int currentXor, int k, vector<vector<vector<int>>>& dp) {
        int m = grid.size(), n = grid[0].size();

        currentXor ^= grid[row][col];
        
        if(row == m - 1 && col == n - 1) {
            if(currentXor == k) {
                return 1;
            } else {
                return 0;
            }
        }

        if(dp[row][col][currentXor] != -1) {
            return dp[row][col][currentXor];
        }

        int paths = 0;

        if(row + 1 < m) {
            paths += countPaths(grid, row + 1, col, currentXor, k, dp);
            paths %= MOD;
        }

        if(col + 1 < n) {
            paths += countPaths(grid, row, col + 1, currentXor, k, dp);
            paths %= MOD;
        }

        return dp[row][col][currentXor] = paths;
    }
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(16, -1)));
        return countPaths(grid, 0, 0, 0, k, dp);
    }
};