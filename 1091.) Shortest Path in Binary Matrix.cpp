class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0].size() == 0 || grid[0][0] == 1 || grid[grid.size() - 1][grid[0].size() - 1] == 1)
            return -1;

        vector<int> delRow{-1,-1,-1,1,1,1,0,0};
        vector<int> delCol{0,-1,1,0,-1,1,-1,1};
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<pair<int, int>, int>> q;

        q.push({{0,0}, 1});
        visited[0][0] = true;

        while(!q.empty())
        {
            auto current = q.front();
            int currentRow = current.first.first;
            int currentCol = current.first.second;
            int currentDist = current.second;
            q.pop();
                    
            if(currentRow == grid.size() - 1 && currentCol == grid[0].size() - 1)
                return currentDist;

            for(int i=0; i<8; i++)
            {
                int tempRow = currentRow + delRow[i];
                int tempCol = currentCol + delCol[i];

                if(tempRow >= 0  && tempRow < grid.size() && tempCol >= 0 && tempCol < grid[0].size() && grid[tempRow][tempCol] == 0 && !visited[tempRow][tempCol])
                {
                    q.push({{tempRow, tempCol}, currentDist + 1});
                    visited[tempRow][tempCol] = true;
                }
            }
        }

        return -1;
    }
};