class Solution
{
public:
    vector<int> xorQueries(vector<int> &a, vector<vector<int>> &queries)
    {
        int n = a.size();
        int m = queries.size();
        vector<int> xors(n + 1);
        vector<int> queryRes(m);
        xors[0] = 1;

        for (int i = 1; i < n + 1; i++)
            xors[i] = a[i - 1] ^ xors[i - 1];

        for (int i = 0; i < m; i++)
            queryRes[i] = xors[queries[i][0]] ^ xors[queries[i][1] + 1];

        return queryRes;
    }
};