class Solution
{
public:
    int sumIndicesWithKSetBits(vector<int> &a, int k)
    {
        int n = a.size();
        vector<int> bits = countBits(n);
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (bits[i] == k)
                sum += a[i];
        }

        return sum;
    }
    vector<int> countBits(int n)
    {
        if (n == 0)
            return {0};
        vector<int> bits(n + 1, 0);

        bits[1] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
                bits[i] = bits[i / 2];
            else
                bits[i] = 1 + bits[i - 1];
        }
        return bits;
    }
};