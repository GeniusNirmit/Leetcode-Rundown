class Solution
{
public:
    long long MOD = 1e9 + 7;

    int numFactoredBinaryTrees(vector<int> &a)
    {
        int n = a.size();
        int possibleTrees = 0;
        unordered_map<int, int> mp;
        vector<int> dp(n + 1, -1);

        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
            mp[a[i]] = i;

        for (int i = 0; i < n; i++)
            possibleTrees = (possibleTrees + generateTree(n, a, i, mp, dp)) % MOD;
        return possibleTrees;
    }
    int generateTree(int n, vector<int> &a, int ind, unordered_map<int, int> &mp, vector<int> &dp)
    {
        if (dp[ind] != -1)
            return dp[ind];

        int trees = 1;
        for (int i = 0; i < ind; i++)
        {
            if (a[ind] % a[i] == 0 && mp.find(a[ind] / a[i]) != mp.end())
                trees = (trees + (long long)generateTree(n, a, i, mp, dp) * generateTree(n, a, mp[a[ind] / a[i]], mp, dp) % MOD) % MOD;
        }
        return dp[ind] = trees;
    }
};