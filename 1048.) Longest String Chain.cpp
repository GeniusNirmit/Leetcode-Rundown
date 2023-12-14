class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), cmp);
        int n = words.size();
        vector<int> dp(n, 1);
        int longestChain = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (checkPossible(words[i], words[j]) && dp[i] < 1 + dp[j])
                    dp[i] = 1 + dp[j];
            }
            if (dp[i] > longestChain)
                longestChain = dp[i];
        }

        return longestChain;
    }
    static bool cmp(string &s1, string &s2)
    {
        return s1.length() < s2.length();
    }
    bool checkPossible(string &s1, string &s2)
    {
        if (s1.length() != s2.length() + 1)
            return false;

        int i = 0, j = 0;
        while (i < s1.length())
        {
            if (s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else
                i++;
        }
        if (i == s1.length() && j == s2.length())
            return true;
        return false;
    }
};