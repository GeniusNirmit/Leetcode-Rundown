class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &a)
    {
        int n = a.size();
        int length = 1, maxLength = 1;

        for (int i = 1; i < n; i++)
        {
            if (a[i - 1] < a[i])
                length++;
            else
            {
                maxLength = max(maxLength, length);
                length = 1;
            }
        }
        maxLength = max(maxLength, length);

        length = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i - 1] > a[i])
                length++;
            else
            {
                maxLength = max(maxLength, length);
                length = 1;
            }
        }
        maxLength = max(maxLength, length);

        return maxLength;
    }
};