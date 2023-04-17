class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> indPair(2, 0);
        for(int i=0; i<mat.size(); i++)
        {
            int counter = 0;
            for(int j=0; j<mat[0].size(); j++)
            {
                if(mat[i][j] == 1)
                    counter++;
            }
            if(indPair[1] < counter)
            {
                indPair[0] = i;
                indPair[1] = counter;
            }
        }
        return indPair;
    }
};