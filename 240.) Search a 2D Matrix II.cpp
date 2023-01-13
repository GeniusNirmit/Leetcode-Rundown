// Approach-1

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++)
        {
            if(target == matrix[i][0] || target == matrix[i][matrix[0].size()-1])
                return true;
            else
            {
                int l = 0, h = matrix[i].size()-1, mid;
                while(l<=h)
                {
                    mid = (l+h)/2;
                    if(target == matrix[i][mid])
                        return true;
                    else if(target > matrix[i][mid])
                        l = mid + 1;
                    else 
                        h = mid - 1;
                }
            }   
        }
        return false;
    }
};

// Approach-2

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[0].size()-1;
        while(i<matrix.size() && j>=0)
        {
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target)
                j--;
            else
                i++;
        }
        return false;
    }
};