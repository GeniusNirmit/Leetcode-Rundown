class Solution
{
public:
    int minPairSum(vector<int> &a)
    {
        sort(a.begin(), a.end());
        int n = a.size();
        int minSum = a[0] + a[n - 1];

        int i = 0, j = n - 1;
        while (i < j)
        {
            minSum = max(minSum, a[i] + a[j]);
            i++;
            j--;
        }
        return minSum;
    }
};