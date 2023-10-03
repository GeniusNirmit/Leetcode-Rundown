class Solution
{
public:
    int numIdenticalPairs(vector<int> &a)
    {
        int counter = 0;
        int n = a.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
            mp[a[i]]++;

        for (auto i : mp)
            counter += (i.second * (i.second - 1)) / 2;

        return counter;
    }
};