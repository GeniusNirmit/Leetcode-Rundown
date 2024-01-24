class Solution
{
    static bool cmp(int &a, int &b)
    {
        return a > b;
    }

public:
    int minimumPushes(string word)
    {
        int n = word.length();
        int counter = 0;
        vector<int> mp(26, 0);

        for (int i = 0; i < n; i++)
            mp[word[i] - 'a']++;

        sort(mp.begin(), mp.end(), cmp);

        for (int i = 0; i < 8; i++)
            counter += mp[i];

        for (int i = 8; i < 16; i++)
            counter += mp[i] * 2;

        for (int i = 16; i < 24; i++)
            counter += mp[i] * 3;

        for (int i = 24; i < 26; i++)
            counter += mp[i] * 4;

        return counter;
    }
};