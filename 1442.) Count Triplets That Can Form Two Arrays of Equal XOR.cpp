class Solution
{
public:
    int countTriplets(vector<int> &a)
    {
        int n = a.size();
        int counter = 0;
        vector<int> elementXor;
        elementXor.push_back(0);

        for (int i = 0; i < n; i++)
            elementXor.push_back(a[i]);

        for (int i = 1; i <= n; i++)
            elementXor[i] ^= elementXor[i - 1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (elementXor[i] == elementXor[j])
                    counter += j - i - 1;
            }
        }

        return counter;
    }
};