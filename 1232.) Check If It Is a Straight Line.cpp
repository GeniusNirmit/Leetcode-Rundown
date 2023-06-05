class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int delX = coordinates[1][0] - coordinates[0][0];
        int delY = coordinates[1][1] - coordinates[0][1];
        
        for(int i=1; i<coordinates.size(); i++)
        {
            int tempDelX = coordinates[i][0] - coordinates[0][0];
            int tempDelY = coordinates[i][1] - coordinates[0][1];
    
            if(delX*tempDelY != delY*tempDelX)
                return false;
        }
        return true;
    }
};