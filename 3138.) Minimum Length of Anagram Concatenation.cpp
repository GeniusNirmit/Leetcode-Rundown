class Solution
{
    bool isAnagram(string &s, int len)
    {
        int n = s.length();
        vector<int> mp(26, 0);

        for (int i = 0; i < len; i++)
            mp[s[i] - 'a']++;

        for (int i = len; i < n; i += len)
        {
            vector<int> currentMp(26, 0);
            for (int j = i; j < i + len; j++)
                currentMp[s[j] - 'a']++;
            if (mp != currentMp)
                return false;
        }
        return true;
    }

public:
    int minAnagramLength(string s)
    {
        int n = s.length();

        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0 && isAnagram(s, i))
                return i;
        }
        return n;
    }
};