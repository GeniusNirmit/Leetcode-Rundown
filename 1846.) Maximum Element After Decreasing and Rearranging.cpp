class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &a)
    {
        int n = a.size();
        int counter = 1;
        sort(a.begin(), a.end());

        for (int i = 1; i < n; i++)
        {
            if (a[i] >= counter + 1)
                counter++;
        }
        return counter;
    }
};