class Solution
{
public:
    bool canArrange(vector<int> &a, int k)
    {
        int n = a.size();
        vector<int> remainders(k, 0);

        for (int i = 0; i < n; i++)
            remainders[(((a[i] % k) + k) % k)]++;

        if (remainders[0] % 2 == 1)
            return false;

        for (int i = 1; i <= k / 2; i++)
        {
            if (remainders[i] != remainders[k - i])
                return false;
        }

        return true;
    }
};