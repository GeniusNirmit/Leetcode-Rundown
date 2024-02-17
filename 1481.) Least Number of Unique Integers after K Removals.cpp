class Solution
{
public:
    bool static cmp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second < b.second;
    }
    int findLeastNumOfUniqueInts(vector<int> &a, int k)
    {
        int n = a.size();
        sort(a.begin(), a.end());
        unordered_map<int, int> mp;
        vector<pair<int, int>> sortedMp;

        for (int i = 0; i < n; i++)
            mp[a[i]]++;

        for (auto i : mp)
            sortedMp.push_back({i.first, i.second});
        sort(sortedMp.begin(), sortedMp.end(), cmp);

        int counter = sortedMp.size();
        int i = 0;
        while (k > 0)
        {
            if (k >= sortedMp[i].second)
                counter--;
            k -= sortedMp[i].second;
            i++;
        }
        return counter;
    }
};