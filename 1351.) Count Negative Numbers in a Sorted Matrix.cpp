// Approach-1

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int counter = 0;
        for(int i=0;i<grid.size();i++)
        {
            int l = 0, h = grid[0].size()-1, mid;
            int temp = -1;
            while(l <= h)
            {
                mid = (l+h)/2;
                if(grid[i][mid] < 0)
                {
                    temp = mid;
                    h = mid-1;
                }
                else
                    l = mid+1;
            }
            if(temp != -1) 
                counter = counter + grid[0].size() - temp;
        }
        return counter;
    }
};

// Approach-2

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int counter = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]<0)
                    counter++;
            }
        }
        return counter;
    }
};