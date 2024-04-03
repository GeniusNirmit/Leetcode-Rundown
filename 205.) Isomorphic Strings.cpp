class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int n = s.length();
        vector<char> mp1(128, 0);
        vector<char> mp2(128, 0);

        for (int i = 0; i < n; i++)
        {
            if (mp1[s[i]] != 0 && mp1[s[i]] != t[i])
                return false;
            if (mp2[t[i]] != 0 && mp2[t[i]] != s[i])
                return false;

            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        return true;
    }
};