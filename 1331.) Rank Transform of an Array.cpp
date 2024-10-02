class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &a)
    {
        int n = a.size();
        set<int> st(a.begin(), a.end());
        unordered_map<int, int> mp;
        vector<int> rank(n);
        int rankInd = 1;

        for (auto i : st)
        {
            mp[i] = rankInd;
            rankInd++;
        }

        for (int i = 0; i < n; i++)
            rank[i] = mp[a[i]];

        return rank;
    }
};