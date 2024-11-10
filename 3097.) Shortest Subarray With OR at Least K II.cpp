class Solution
{
    void orOperation(vector<int> &bitCounter, int num, bool flag)
    {
        for (int i = 0; i < 32; i++)
        {
            if ((num >> i) & 1)
            {
                if (flag)
                    bitCounter[i]++;
                else
                    bitCounter[i]--;
            }
        }
    }

    int bitsToNumber(vector<int> &bitCounter)
    {
        int num = 0;

        for (int i = 0; i < 32; i++)
        {
            if (bitCounter[i] != 0)
                num |= 1 << i;
        }

        return num;
    }

public:
    int minimumSubarrayLength(vector<int> &a, int k)
    {
        int n = a.size();
        int minLength = n + 1;

        int l = 0, h = 0;
        vector<int> bitCounter(32, 0);

        while (h < n)
        {
            orOperation(bitCounter, a[h], true);

            while (l <= h && bitsToNumber(bitCounter) >= k)
            {
                minLength = min(minLength, h - l + 1);

                orOperation(bitCounter, a[l], false);
                l++;
            }

            h++;
        }

        if (minLength == n + 1)
            return -1;
        return minLength;
    }
};