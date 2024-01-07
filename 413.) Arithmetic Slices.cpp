class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &a)
    {
        int n = a.size();
        int counter = 0, totalSlices = 0;

        for (int i = 2; i < n; i++)
        {
            if (a[i - 2] - a[i - 1] == a[i - 1] - a[i])
            {
                counter++;
                totalSlices += counter;
            }
            else
                counter = 0;
        }

        return totalSlices;
    }
};