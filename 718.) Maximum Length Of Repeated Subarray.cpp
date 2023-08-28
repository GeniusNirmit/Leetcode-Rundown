class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();

        vector<int> prev(n + 1, 0);

        int maxSize = 0;
        for (int i = 1; i <= n; i++)
        {
            vector<int> current(n + 1, 0);
            for (int j = 1; j <= m; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    current[j] = 1 + prev[j - 1];
                    maxSize = max(maxSize, current[j]);
                }
                else
                    current[j] = 0;
            }
            prev = current;
        }

        return maxSize;
    }
};