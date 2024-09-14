class Solution
{
public:
    int longestSubarray(vector<int> &a)
    {
        int n = a.size();
        int maxVal = 0, currentLen = 0, maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] > maxVal)
            {
                maxVal = a[i];
                currentLen = 0;
                maxLen = 0;
            }

            if (a[i] == maxVal)
                currentLen++;
            else
                currentLen = 0;

            maxLen = max(maxLen, currentLen);
        }

        return maxLen;
    }
};