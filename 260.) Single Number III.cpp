class Solution
{
public:
    vector<int> singleNumber(vector<int> &a)
    {
        unsigned int xorNum = 0;
        int n = a.size();

        for (int i = 0; i < n; i++)
            xorNum ^= a[i];

        unsigned int diff = xorNum & -xorNum;
        int num1 = 0, num2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] & diff)
                num1 ^= a[i];
            else
                num2 ^= a[i];
        }

        return {num1, num2};
    }
};