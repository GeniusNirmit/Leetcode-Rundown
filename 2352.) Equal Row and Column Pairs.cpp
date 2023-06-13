class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> rowMap;
        int counter = 0;
        for(int i=0; i<grid.size(); i++)
        {
            string currentRow;
            for(int j=0; j<grid[0].size(); j++)
            {
                currentRow += to_string(grid[i][j]);
                currentRow += ",";
            }
            rowMap[currentRow]++;
        }

        for(int i=0; i<grid[0].size(); i++)
        {
            string currentCol;
            for(int j=0; j<grid.size(); j++)
            {
                currentCol += to_string(grid[j][i]);
                currentCol += ",";
            }
            if(rowMap[currentCol])
                counter += rowMap[currentCol];
        }

        return counter;
    }
};