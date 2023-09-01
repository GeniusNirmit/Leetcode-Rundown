class Solution
{
public:
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