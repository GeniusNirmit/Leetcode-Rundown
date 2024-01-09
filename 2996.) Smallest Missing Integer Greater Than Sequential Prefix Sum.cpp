class Solution
{
public:
    int missingInteger(vector<int> &a)
    {
        int n = a.size();
        unordered_set<int> st(a.begin(), a.end());

        if (n == 1)
            return a[0] + 1;

        int prefixCounter = 1, prefixSum = a[0];

        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1] + 1)
            {
                prefixCounter++;
                prefixSum += a[i];
            }
            else
                break;
        }

        while (true)
        {
            if (st.find(prefixSum) == st.end())
                return prefixSum;
            prefixSum++;
        }

        return 0;
    }
};