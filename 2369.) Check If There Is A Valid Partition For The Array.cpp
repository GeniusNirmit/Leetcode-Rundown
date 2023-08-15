class Solution
{
public:
    bool validPartition(vector<int> &a)
    {
        int n = a.size();
        vector<int> dp(n + 1, -1);
        return formPartition(n, a, 0, dp);
    }
    bool formPartition(int n, vector<int> &a, int ind, vector<int> &dp)
    {
        if (ind == n)
            return true;
        if (dp[ind] != -1)
            return dp[ind];

        if (ind < n - 1 && a[ind] == a[ind + 1])
        {
            if (formPartition(n, a, ind + 2, dp))
                return dp[ind] = true;
        }
        if (ind < n - 2 && a[ind] == a[ind + 1] && a[ind + 1] == a[ind + 2])
        {
            if (formPartition(n, a, ind + 3, dp))
                return dp[ind] = true;
        }
        if (ind < n - 2 && a[ind] + 1 == a[ind + 1] && a[ind + 1] == a[ind + 2] - 1)
        {
            if (formPartition(n, a, ind + 3, dp))
                return dp[ind] = true;
        }
        return dp[ind] = false;
    }
};