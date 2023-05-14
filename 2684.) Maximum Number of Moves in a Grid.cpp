class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int maximumMoves = 0;
        for(int i=0; i<grid.size(); i++)
            maximumMoves = max(maximumMoves, dfs(i, 0, grid, 0));
        return maximumMoves - 1;
    }
    int dfs(int row, int col,vector<vector<int>>& grid, int prev)
    {
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] <= prev)
            return 0;
        int maxValue = 0;
        prev = grid[row][col];
        grid[row][col] = 0;

        maxValue = max(maxValue, dfs(row-1, col+1, grid, prev));
        
        maxValue = max(maxValue, dfs(row, col+1, grid, prev));
    
        maxValue = max(maxValue, dfs(row+1, col+1, grid, prev));
        return maxValue + 1;
    }
};