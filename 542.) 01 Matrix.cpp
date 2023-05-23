class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> updatedMatrix(mat.size(), vector<int>(mat[0].size(), 0));
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
        queue<pair< pair<int,int>, int>> q;

        for(int i=0; i<mat.size(); i++)
        {
            for(int j=0; j<mat[0].size(); j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({ {i, j}, 0 });
                    visited[i][j] = true;
                }
            }
        }

        vector<int> delRow = { 0, 1, 0, -1};
        vector<int> delCol = { 1, 0, -1, 0};

        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;
            q.pop();
            updatedMatrix[row][col] = distance;

            for(int i=0; i<4; i++)
            {
                int tempRow = delRow[i] + row;
                int tempCol = delCol[i] + col;

                if(tempRow < mat.size() && tempRow >= 0 && tempCol < mat[0].size() && tempCol >= 0 && visited[tempRow][tempCol] == 0)
                {
                    visited[tempRow][tempCol] = true;
                    q.push({ {tempRow, tempCol}, distance + 1});
                }
            }
        }
        return updatedMatrix;
    }
};