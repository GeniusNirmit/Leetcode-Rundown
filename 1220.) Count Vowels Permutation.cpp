class Solution
{
public:
    long long MOD = 1e9 + 7;
    int countVowelPermutation(int n)
    {
        if (n == 1)
            return 5;

        vector<vector<int>> mp{{1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {0}};
        vector<vector<int>> dp(n + 1, vector<int>(5, -1));

        int permutations = 0;
        for (int i = 0; i < 5; i++)
            permutations = (permutations + (long long)permutation(n - 1, 1, i, mp, dp) % MOD) % MOD;
        return permutations;
    }
    int permutation(int n, int level, int ind, vector<vector<int>> &mp, vector<vector<int>> &dp)
    {
        if (level == n)
            return mp[ind].size();
        if (dp[level][ind] != -1)
            return dp[level][ind];

        int permutations = 0;
        for (int i = 0; i < mp[ind].size(); i++)
            permutations = (permutations + (long long)permutation(n, level + 1, mp[ind][i], mp, dp) % MOD) % MOD;
        return dp[level][ind] = permutations;
    }
};