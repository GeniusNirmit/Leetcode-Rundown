class Solution
{
    int subarrayWithAtmostKDistinct(vector<int> &a, int k)
    {
        int n = a.size();
        unordered_map<int, int> mp;
        int counter = 0;
        int l = 0, r = 0;

        while (r < n)
        {
            mp[a[r]]++;
            while (l <= r && mp.size() > k)
            {
                mp[a[l]]--;
                if (mp[a[l]] == 0)
                    mp.erase(a[l]);
                l++;
            }
            r++;
            counter += r - l + 1;
        }
        return counter;
    }

public:
    int subarraysWithKDistinct(vector<int> &a, int k)
    {
        return subarrayWithAtmostKDistinct(a, k) - subarrayWithAtmostKDistinct(a, k - 1);
    }
};