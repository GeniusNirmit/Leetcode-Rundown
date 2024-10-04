class Solution
{
public:
    int minSubarray(vector<int> &a, int p)
    {
        int n = a.size();
        int sum = 0;
        int currentSum = 0;
        int minLength = n;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
            sum = (sum + a[i]) % p;

        int target = sum % p;

        if (target == 0)
            return 0;
        mp[0] = -1;

        for (int i = 0; i < n; i++)
        {
            currentSum = (currentSum + a[i]) % p;
            int currentTarget = (currentSum - target + p) % p;

            if (mp.find(currentTarget) != mp.end())
                minLength = min(minLength, i - mp[currentTarget]);

            mp[currentSum] = i;
        }

        if (minLength == n)
            return -1;
        return minLength;
    }
};