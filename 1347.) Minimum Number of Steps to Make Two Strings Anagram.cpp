class Solution
{
public:
    int minSteps(string s, string t)
    {
        int n = s.length();
        int counter = 0;
        vector<int> mp1(26, 0), mp2(26, 0);

        for (int i = 0; i < n; i++)
        {
            mp1[s[i] - 'a']++;
            mp2[t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (mp1[i] != 0 && mp1[i] > mp2[i])
                counter += (mp1[i] - mp2[i]);
        }
        return counter;
    }
};