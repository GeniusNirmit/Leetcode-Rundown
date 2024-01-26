class Solution
{
public:
    int maxLength(vector<string> &a)
    {
        int n = a.size();
        unordered_map<string, int> dp;
        vector<string> selectedStrings;
        return concateString(n, 0, selectedStrings, a, dp);
    }
    int concateString(int n, int ind, vector<string> &selectedStrings, vector<string> &a, unordered_map<string, int> &dp)
    {
        int size = selectedStrings.size();
        unordered_map<char, int> mp;

        if (ind >= n)
            return 0;

        string current = "";
        for (int i = 0; i < size; i++)
            current += selectedStrings[i];

        if (dp.find(current) != dp.end())
            return dp[current];

        selectedStrings.push_back(a[ind]);
        for (int i = 0; i < selectedStrings.size(); i++)
        {
            for (int j = 0; j < selectedStrings[i].length(); j++)
                mp[selectedStrings[i][j]]++;
        }

        bool flag = true;
        for (auto i : mp)
        {
            if (i.second > 1)
            {
                flag = false;
                break;
            }
        }

        int pickString = 0, notPickString = 0;
        if (flag)
            pickString = a[ind].size() + concateString(n, ind + 1, selectedStrings, a, dp);
        selectedStrings.pop_back();
        notPickString = concateString(n, ind + 1, selectedStrings, a, dp);

        return dp[current] = max(pickString, notPickString);
    }
};