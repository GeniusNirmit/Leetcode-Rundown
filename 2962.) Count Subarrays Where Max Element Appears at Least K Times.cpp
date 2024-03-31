class Solution
{
public:
    long long countSubarrays(vector<int> &a, int k)
    {
        int n = a.size();
        int maxElement = 0, elementCounter = 0;
        long long counter = 0;

        for (int i = 0; i < n; i++)
            maxElement = max(maxElement, a[i]);

        int l = 0, r = 0;
        while (r < n)
        {
            if (a[r] == maxElement)
                elementCounter++;
            while (l <= r && elementCounter >= k)
            {
                counter += n - r;
                if (a[l] == maxElement)
                    elementCounter--;
                l++;
            }
            r++;
        }

        return counter;
    }
};