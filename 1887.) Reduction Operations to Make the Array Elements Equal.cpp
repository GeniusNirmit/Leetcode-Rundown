class Solution
{
public:
    int reductionOperations(vector<int> &a)
    {
        int n = a.size();
        int counter = 0;
        sort(a.begin(), a.end());
        int minVal = a[0];

        int ind = 0;
        while (ind < n && a[ind] == minVal)
            ind++;

        int prev = a[ind - 1];
        for (int i = ind; i < n; i++)
        {
            if (a[i] != prev)
            {
                counter += (n - i);
                prev = a[i];
            }
        }
        return counter;
    }
};