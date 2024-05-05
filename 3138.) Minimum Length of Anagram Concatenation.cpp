class Solution
{
public:
    int minAnagramLength(string s)
    {
        int n = s.length();
        vector<int> mp(26, 0);

        for (int i = 0; i < n; i++)
            mp[s[i] - 'a']++;

        int gcd = mp[0];
        for (int i = 0; i < 26; i++)
            gcd = __gcd(gcd, mp[i]);

        return n / gcd;
    }
};