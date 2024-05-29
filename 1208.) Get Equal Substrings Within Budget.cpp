class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.length();
        vector<int> diff(n);

        for (int i = 0; i < n; i++)
            diff[i] = abs(s[i] - t[i]);

        int l = 0, r = 0, maxLength = 0, currentCost = 0;
        while (r < n && l <= r)
        {
            currentCost += diff[r];
            while (currentCost > maxCost)
            {
                currentCost -= diff[l];
                l++;
            }

            maxLength = max(maxLength, r - l + 1);
            r++;
        }

        return maxLength;
    }
};