// Approach - 1

class Solution
{
    int createChain(vector<vector<int>> &pairs, int ind, int prevInd, vector<vector<int>> &dp)
    {
        int n = pairs.size();

        if (ind == n)
            return 0;
        if (dp[prevInd + 1][ind] != -1)
            return dp[prevInd + 1][ind];

        int pick = 0, notPick = 0;
        if (prevInd == -1 || pairs[prevInd][1] < pairs[ind][0])
            pick = createChain(pairs, ind + 1, ind, dp) + 1;

        notPick = createChain(pairs, ind + 1, prevInd, dp);

        return dp[prevInd + 1][ind] = max(pick, notPick);
    }

public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int maxVal = 1;

        for (int i = 0; i < n; i++)
            maxVal = max(maxVal, createChain(pairs, i, -1, dp));

        return maxVal;
    }
};

// Approach - 2

class Solution
{
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }

public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), cmp);

        int prevChainVal = pairs[0][1];
        int maxLenChain = 1;

        for (int i = 1; i < n; i++)
        {
            if (prevChainVal < pairs[i][0])
            {
                maxLenChain++;
                prevChainVal = pairs[i][1];
            }
        }

        return maxLenChain;
    }
};