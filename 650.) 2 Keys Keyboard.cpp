class Solution
{
public:
    int minSteps(int n)
    {
        if (n == 1)
            return 0;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return operation(n, 1, 1, dp) + 1;
    }
    int operation(int n, int screen, int clipBoard, vector<vector<int>> &dp)
    {
        if (screen == n)
            return 0;
        if (screen > n)
            return 1e9;
        if (dp[screen][clipBoard] != -1)
            return dp[screen][clipBoard];

        int copyPaste = operation(n, screen * 2, screen, dp) + 2;
        int paste = operation(n, screen + clipBoard, clipBoard, dp) + 1;

        return dp[screen][clipBoard] = min(copyPaste, paste);
    }
};