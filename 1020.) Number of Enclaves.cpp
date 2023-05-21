class Solution {
public:
    void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<int>>&grid) {
        visited[row][col] = true;

        vector<int> delRow = {1,0,-1,0};
        vector<int> delCol = {0,-1,0,1};

        for(int i=0; i<4; i++)
        {
            int tempRow = row + delRow[i];
            int tempCol = col + delCol[i];

            if(tempRow >= 0 && tempRow < grid.size() && tempCol >= 0 && tempCol < grid[0].size() && !visited[tempRow][tempCol] && grid[tempRow][tempCol]==1)
                dfs(tempRow, tempCol, visited, grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int counter = 0;

        for(int i=0; i<grid[0].size(); i++)
        {
            if(!visited[0][i] && grid[0][i] == 1)
                dfs(0, i, visited, grid);
            if(!visited[grid.size() - 1][i] && grid[grid.size() - 1][i] == 1)
                dfs(grid.size() - 1, i, visited, grid);
        }

        for(int i=0; i<grid.size(); i++)
        {
            if(!visited[i][0] && grid[i][0] == 1)
                dfs(i, 0, visited, grid);
            if(!visited[i][grid[0].size() - 1] && grid[i][grid[0].size()-1] == 1)
                dfs(i, grid[0].size()-1, visited, grid);
        }

        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size() ; j++)
            {
                if(!visited[i][j] && grid[i][j] == 1)
                    counter++;
            }
        }
        return counter;
    }
};