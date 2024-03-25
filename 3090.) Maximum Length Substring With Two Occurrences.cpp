class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int n = s.length();
        int maxLength = 0;
        unordered_map<char, int> mp;

        int l = 0, h = 0;
        while (h < n)
        {
            mp[s[h]]++;

            while (mp[s[h]] > 2)
            {
                mp[s[l]]--;
                l++;
            }

            maxLength = max(maxLength, h - l + 1);
            h++;
        }

        return maxLength;
    }
};