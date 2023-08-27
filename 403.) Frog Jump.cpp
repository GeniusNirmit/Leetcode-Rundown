class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        int n = stones.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[stones[i]] = i;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return jumps(mp, stones, 0, 1, dp);
    }
    bool jumps(unordered_map<int, int> &mp, vector<int> &stones, int jump, int ind, vector<vector<int>> &dp)
    {
        if (stones[jump] + ind == stones.back())
            return true;
        if (mp.find(stones[jump] + ind) == mp.end())
            return false;
        if (dp[jump][ind] != -1)
            return dp[jump][ind];

        bool possible = false;

        possible = jumps(mp, stones, mp[stones[jump] + ind], ind + 1, dp);
        possible |= jumps(mp, stones, mp[stones[jump] + ind], ind, dp);
        if (ind > 1)
            possible |= jumps(mp, stones, mp[stones[jump] + ind], ind - 1, dp);
        return dp[jump][ind] = possible;
    }
};