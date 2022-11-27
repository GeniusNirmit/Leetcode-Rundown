class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> v;
        int r=0, c=0;
        int m=mat.size(), n=mat[0].size();
        for(int i=0; i<m*n; i++)
        {
            v.push_back(mat[r][c]);
            if((r+c) % 2 == 0)
            {
                if(c == n-1)
                    r++;
                else if(r == 0)
                    c++;
                else
                {
                    c++;
                    r--;
                }
            }
            else
            {
                if(r == m-1)
                    c++;
                else if(c == 0)
                    r++;
                else
                {
                    r++;
                    c--;
                }
            }
        }
        return v;
    }
};