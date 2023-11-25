class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &a)
    {
        int ind = 0;
        unordered_map<int, vector<int>> mp;
        vector<int> diagonalOrder;

        for (int i = a.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < a[i].size(); j++)
                mp[i + j].push_back(a[i][j]);
        }

        while (mp.find(ind) != mp.end())
        {
            for (auto i : mp[ind])
                diagonalOrder.push_back(i);
            ind++;
        }
        return diagonalOrder;
    }
};