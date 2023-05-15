class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    counter++;
                    dfs(i, j, visited, grid);
                }
            }
        }
        return counter;
    }
    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        visited[i][j] = true;

        if(i >= 0 && i < grid.size() && j + 1 >= 0 && j + 1 < grid[0].size() && grid[i][j+1] == '1' && !visited[i][j+1])
            dfs(i, j+1, visited, grid);

        if(i >= 0 && i < grid.size() && j - 1 >= 0 && j - 1 < grid[0].size() && grid[i][j-1] == '1' && !visited[i][j-1])
            dfs(i, j-1, visited, grid);

        if(i + 1 >= 0 && i + 1 < grid.size() && j >= 0 && j < grid[0].size() && grid[i+1][j] == '1' && !visited[i+1][j])
            dfs(i+1, j, visited, grid);

        if(i - 1 >= 0 && i - 1 < grid.size() && j >= 0 && j < grid[0].size() && grid[i-1][j] == '1' && !visited[i-1][j])
            dfs(i-1, j, visited, grid);
            
        return;
    }
};