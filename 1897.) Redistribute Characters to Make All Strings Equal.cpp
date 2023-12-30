class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        int n = words.size();
        unordered_map<char, int> mp;

        for (int i = 0; i < n; i++)
        {
            int size = words[i].length();
            for (int j = 0; j < size; j++)
                mp[words[i][j]]++;
        }

        for (auto i : mp)
        {
            if (i.second % n != 0)
                return false;
        }
        return true;
    }
};