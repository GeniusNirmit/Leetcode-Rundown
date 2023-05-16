class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        queue<pair<pair< int, int>, int>> q;
        int freshCounter = 0, visitedFreshCounter = 0, minTime = 0;

        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({ {i, j}, 0});
                    visited[i][j] = 2;
                }

                if(grid[i][j] == 1)
                    freshCounter++;
            }
        }

        vector<int> delRow{ 0, 1, 0, -1};
        vector<int> delCol{ 1, 0, -1, 0};

        while(!q.empty())
        {
           int row = q.front().first.first;
           int col = q.front().first.second;
           int time = q.front().second; 

           minTime = max(minTime, time);
           q.pop();

           for(int i=0; i<4; i++)
           {
               int tempRow = row + delRow[i];
               int tempCol = col + delCol[i];

               if(tempRow >= 0 && tempRow < grid.size() && tempCol >= 0 && tempCol < grid[0].size() && grid[tempRow][tempCol] == 1 && visited[tempRow][tempCol] == 0)
               {
                   q.push({ {tempRow, tempCol}, time + 1});
                   visited[tempRow][tempCol] = 2;
                   visitedFreshCounter++;
               }
           }
        }

        if(visitedFreshCounter != freshCounter)
            return -1;
        return minTime;
    }
};