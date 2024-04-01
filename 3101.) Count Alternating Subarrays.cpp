class Solution
{
public:
    long long countAlternatingSubarrays(vector<int> &a)
    {
        int n = a.size();
        long long counter = 0;
        int currentCounter = 1;

        for (int i = 1; i < n; i++)
        {
            if (a[i] != a[i - 1])
            {
                counter += currentCounter;
                currentCounter++;
            }
            else
                currentCounter = 1;
        }

        return counter + n;
    }
};