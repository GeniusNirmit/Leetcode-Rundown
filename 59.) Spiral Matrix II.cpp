class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0;
        int right= n - 1;
        int top = 0;
        int bottom = n - 1;
        vector<vector<int>> matrix(n, vector<int> (n));
        int i, element = 1;
        while(left<=right && top<=bottom) 
        {
            for(i=left;i<=right;i++)
            {
                matrix[top][i] = element;
                element++;
            }
            top++;
            
            for(i=top;i<=bottom;i++)
            {
                matrix[i][right] = element;
                element++;
            }
            right--;
                        
            for(i=right;i>=left;i--)
            {
                matrix[bottom][i] = element;
                element++;
            }
            bottom--;
            
            for(i=bottom;i>=top;i--)
            {
                matrix[i][left] = element;
                element++;
            }
            left++;
        }
        return matrix;
    }
};