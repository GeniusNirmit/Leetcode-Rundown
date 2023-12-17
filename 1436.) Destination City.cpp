class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        int n = paths.size();
        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[paths[i][0]]++;
            mp[paths[i][1]]--;
        }

        string destination;
        for (auto i : mp)
        {
            if (i.second < 0)
            {
                destination = i.first;
                break;
            }
        }
        return destination;
    }
};