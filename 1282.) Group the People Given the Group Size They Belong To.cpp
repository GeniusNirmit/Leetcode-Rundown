class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> groupPeople;
        int n = groupSizes.size();

        for (int i = 0; i < n; i++)
            mp[groupSizes[i]].push_back(i);

        for (auto i : mp)
        {
            vector<int> group;
            int reqSize = i.first;
            int currSize = i.second.size();
            for (int j = 1; j <= currSize; j++)
            {
                group.push_back(i.second[j - 1]);
                if (j % reqSize == 0)
                {
                    groupPeople.push_back(group);
                    group.clear();
                }
            }
        }
        return groupPeople;
    }
};