class Solution
{
public:
    int maxSubarrayLength(vector<int> &a, int k)
    {
        int n = a.size();

        int l = 0, r = 0;
        int maxLength = 0;
        unordered_map<int, int> mp;

        while (l <= r && r < n)
        {
            mp[a[r]]++;
            while (mp[a[r]] > k)
                mp[a[l++]]--;
            r++;
            maxLength = max(maxLength, r - l);
        }

        return maxLength;
    }
};