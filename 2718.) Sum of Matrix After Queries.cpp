class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<bool> visitedRow(n, false);
        vector<bool> visitedCol(n, false);
        long long sum = 0;
        int row = n, col = n;
        for(int i=queries.size()-1; i>=0; i--)
        {
            if(queries[i][0] == 0)
            {
                if(!visitedRow[queries[i][1]])
                {
                    visitedRow[queries[i][1]] = true;
                    sum += (col*queries[i][2]);
                    row--;
                }
            }
            else
            {
                if(!visitedCol[queries[i][1]])
                {
                    visitedCol[queries[i][1]] = true;
                    sum += (row*queries[i][2]);
                    col--;
                }
            }
        }
        return sum;
    }
};