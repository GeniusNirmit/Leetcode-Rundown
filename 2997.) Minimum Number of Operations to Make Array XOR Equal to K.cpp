class Solution
{
public:
    int minOperations(vector<int> &a, int k)
    {
        int n = a.size(), Xor = k, counter = 0;

        for (int i = 0; i < n; i++)
            Xor ^= a[i];

        while (Xor)
        {
            counter += Xor & 1;
            Xor >>= 1;
        }

        return counter;
    }
};