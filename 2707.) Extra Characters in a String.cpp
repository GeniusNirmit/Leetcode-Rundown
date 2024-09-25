class Solution
{
public:
    int findExtraChars(string &s, int ind, unordered_map<string, int> mp, vector<int> &dp)
    {
        int n = s.length();
        if (ind >= n)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];

        int extraChars = n;
        string temp = "";

        for (int i = ind; i < n; i++)
        {
            temp += s[i];

            if (mp.find(temp) != mp.end())
                extraChars = min(extraChars, findExtraChars(s, i + 1, mp, dp));
        }

        extraChars = min(extraChars, findExtraChars(s, ind + 1, mp, dp) + 1);

        return dp[ind] = extraChars;
    }
    int minExtraChar(string s, vector<string> &dictionary)
    {
        int n = dictionary.size();
        unordered_map<string, int> mp;
        vector<int> dp(s.length(), -1);

        for (int i = 0; i < n; i++)
            mp[dictionary[i]]++;

        return findExtraChars(s, 0, mp, dp);
    }
};