class Solution
{
public:
    int countPairs(vector<int> &a, int dist)
    {
        int counter = 0;
        int n = a.size();
        int l = 0, h = 0;
        while (h < n)
        {
            while (a[h] - a[l] > dist)
                l++;
            counter += h - l;
            h++;
        }

        return counter;
    }
    int smallestDistancePair(vector<int> &a, int k)
    {
        int n = a.size();
        sort(a.begin(), a.end());
        int l = 0, h = a[n - 1] - a[0];

        while (l < h)
        {
            int mid = (l + h) / 2;
            int pairs = countPairs(a, mid);

            if (pairs >= k)
                h = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};