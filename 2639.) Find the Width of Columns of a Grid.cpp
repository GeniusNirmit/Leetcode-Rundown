class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> maxWidths;
        for(int i=0; i<grid[0].size(); i++)
        {
            int maxLength = 0;
            for(int j=0; j<grid.size(); j++)
            {
                string temp = to_string(grid[j][i]);
                if(maxLength < temp.length())
                    maxLength = temp.length();
            }
            maxWidths.push_back(maxLength);
        }
        return maxWidths;
    }
};  