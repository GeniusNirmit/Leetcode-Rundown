class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int sum = 0;
        for(int i=0;i<grid.size();i++)
            sort(grid[i].begin(),grid[i].end());
        for(int i=grid[0].size()-1;i>=0;i--)
        {
            int max = 0;
            for(int j=0;j<grid.size();j++)
            {
                if(max < grid[j][i])
                    max = grid[j][i];
            }
            sum += max; 
        }
        return sum;
    }
};