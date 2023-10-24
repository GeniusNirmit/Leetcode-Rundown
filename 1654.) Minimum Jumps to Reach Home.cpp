class Solution
{
public:
    int minimumJumps(vector<int> &forbidden, int a, int b, int x)
    {
        int n = forbidden.size();
        vector<vector<int>> dp(6001, vector<int>(2, -1));
        sort(forbidden.begin(), forbidden.end());

        int minJumps = jump(n, forbidden, a, b, x, 0, 0, dp);
        if (minJumps > 1e9)
            return -1;
        return minJumps;
    }
    int jump(int n, vector<int> &forbidden, int a, int b, int x, int ind, int backJump, vector<vector<int>> &dp)
    {
        if (ind == x)
            return 0;
        if (ind < 0 || ind > 6000 || search(n, forbidden, ind))
            return 1e9;
        if (dp[ind][backJump] != -1)
            return dp[ind][backJump];

        dp[ind][backJump] = jump(n, forbidden, a, b, x, ind + a, 0, dp) + 1;
        if (!backJump)
            dp[ind][backJump] = min(dp[ind][backJump], jump(n, forbidden, a, b, x, ind - b, 1, dp) + 1);

        return dp[ind][backJump];
    }
    bool search(int n, vector<int> &forbidden, int target)
    {
        int l = 0, h = n - 1, mid;
        while (l <= h)
        {
            mid = (l + h) / 2;
            if (forbidden[mid] == target)
                return true;
            else if (forbidden[mid] > target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};