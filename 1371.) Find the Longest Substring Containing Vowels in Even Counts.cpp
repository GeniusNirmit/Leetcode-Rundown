class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        int n = s.length();
        int maxLen = 0, mask = 0;
        unordered_map<char, int> vowels;
        unordered_map<int, int> indexes;

        vowels['a'] = 1;
        vowels['e'] = 2;
        vowels['i'] = 4;
        vowels['o'] = 8;
        vowels['u'] = 16;

        indexes[0] = -1;

        for (int i = 0; i < n; i++)
        {
            if (vowels.find(s[i]) != vowels.end())
                mask ^= vowels[s[i]];

            if (!mask || indexes.find(mask) != indexes.end())
                maxLen = max(maxLen, i - indexes[mask]);
            else
                indexes[mask] = i;
        }

        return maxLen;
    }
};