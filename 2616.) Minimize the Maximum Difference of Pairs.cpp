class Solution
{
public:
    int minimizeMax(vector<int> &a, int p)
    {
        sort(a.begin(), a.end());
        int n = a.size();
        int start = 0, end = a[n - 1] - a[0];

        while (start < end)
        {
            int mid = (start + end) / 2;
            if (countPairs(a, mid) >= p)
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }
    int countPairs(vector<int> a, int min)
    {
        int ind = 0, counter = 0;
        while (ind < a.size() - 1)
        {
            if (a[ind + 1] - a[ind] <= min)
            {
                counter++;
                ind++;
            }
            ind++;
        }
        return counter;
    }
};