class Solution
{
    int findLongestSubstring(string s, int start, int end, int k)
    {
        if (end < k)
            return 0;

        int n = s.length();
        vector<int> mp(26, 0);

        for (int i = start; i < end; i++)
            mp[s[i] - 'a']++;

        for (int mid = start; mid < end; mid++)
        {
            if (mp[s[mid] - 'a'] < k)
            {
                int midNext = mid + 1;
                while (midNext < end && mp[s[midNext] - 'a'] < k)
                    midNext++;

                return max(findLongestSubstring(s, start, mid, k), findLongestSubstring(s, midNext, end, k));
            }
        }
        return end - start;
    }

public:
    int longestSubstring(string s, int k)
    {
        int n = s.length();

        return findLongestSubstring(s, 0, n, k);
    }
};