class Solution
{
public:
    bool dfs(int m, int n, vector<vector<int>> &grid1, vector<vector<int>> &grid2, vector<vector<bool>> &visited, int row, int col)
    {
        if (row < 0 || row == m || col < 0 || col == n || visited[row][col] || grid2[row][col] == 0)
            return true;

        visited[row][col] = true;
        bool flag = true;

        if (grid1[row][col] == 0)
            flag = false;

        flag &= dfs(m, n, grid1, grid2, visited, row + 1, col);
        flag &= dfs(m, n, grid1, grid2, visited, row, col + 1);
        flag &= dfs(m, n, grid1, grid2, visited, row - 1, col);
        flag &= dfs(m, n, grid1, grid2, visited, row, col - 1);

        return flag;
    }
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int m = grid1.size(), n = grid1[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int counter = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid2[i][j] && !visited[i][j] && dfs(m, n, grid1, grid2, visited, i, j))
                    counter++;
            }
        }

        return counter;
    }
};