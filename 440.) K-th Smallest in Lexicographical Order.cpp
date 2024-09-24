class Solution
{
public:
    int countNumbersWithPrefix(int n, int prefix)
    {
        long long pre1 = prefix, pre2 = prefix + 1;
        int counter = 0;

        while (pre1 <= n)
        {
            counter += min((long long)(n + 1), pre2) - pre1;
            pre1 *= 10;
            pre2 *= 10;
        }

        return counter;
    }
    int findKthNumber(int n, int k)
    {
        int current = 1;
        k--;

        while (k > 0)
        {
            int counter = countNumbersWithPrefix(n, current);
            if (counter <= k)
            {
                current++;
                k -= counter;
            }
            else
            {
                current *= 10;
                k--;
            }
        }

        return current;
    }
};