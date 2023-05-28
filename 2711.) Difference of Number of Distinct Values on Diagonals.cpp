class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        vector<vector<int>> answer(grid.size(), vector<int>(grid[0].size(), 0));
        
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                answer[i][j] = findAnswer(grid, i, j);
            }
        }
        
        return answer;
    }
    
    int findAnswer(vector<vector<int>>& grid, int row, int col) {
        unordered_set<int> topLeft;
        unordered_set<int> bottomRight;
        
        int tempRow = row + 1;
        int tempCol = col + 1;
        
        while(tempRow < grid.size() && tempCol < grid[0].size())
            bottomRight.insert(grid[tempRow++][tempCol++]);
    
        tempRow = row - 1;
        tempCol = col - 1;
        
        while(tempRow >= 0 && tempCol >= 0)
            topLeft.insert(grid[tempRow--][tempCol--]);
        
        int diff = topLeft.size() - bottomRight.size();
        return abs(diff);
    }
};