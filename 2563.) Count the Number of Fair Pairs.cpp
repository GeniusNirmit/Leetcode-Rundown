class Solution
{
public:
    long long countFairPairs(vector<int> &a, int lower, int upper)
    {
        int n = a.size();
        sort(a.begin(), a.end());
        return findFairPairs(a, upper + 1) - findFairPairs(a, lower);
    }
    long long findFairPairs(vector<int> &a, int target)
    {
        int n = a.size();
        long long l = 0, h = n - 1;
        long long counter = 0;

        while (l < h)
        {
            if (a[l] + a[h] < target)
            {
                counter += (h - l);
                l++;
            }
            else
                h--;
        }

        return counter;
    }
};