// Approach - 1

class Solution
{
public:
    int lengthOfLIS(vector<int> &a)
    {
        int n = a.size();
        vector<int> prev(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            vector<int> current(n + 1, 0);
            for (int j = i - 1; j >= -1; j--)
            {
                int len = prev[j + 1];

                if (j == -1 || a[i] > a[j])
                    len = max(len, 1 + prev[i + 1]);

                current[j + 1] = len;
            }
            prev = current;
        }
        return prev[0];
    }
};

// Approach - 2

class Solution
{
public:
    int lengthOfLIS(vector<int> &a)
    {
        int n = a.size();
        int longestLength = 1;
        vector<int> temp;
        temp.push_back(a[0]);

        for (int i = 1; i < n; i++)
        {
            if (a[i] > temp.back())
            {
                temp.push_back(a[i]);
                longestLength++;
            }
            else
            {
                int ind = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
                temp[ind] = a[i];
            }
        }

        return longestLength;
    }
};