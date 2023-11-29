class Solution
{
public:
    int MOD = 1e9 + 7;
    vector<vector<int>> jump;
    int knightDialer(int n)
    {
        int counter = 0;
        generateJumps();
        vector<vector<int>> dp(n, vector<int>(10, 0));

        for (int i = 0; i <= 9; i++)
            dp[0][i] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                for (int k = 0; k < jump[j].size(); k++)
                    dp[i][j] = (dp[i][j] + dp[i - 1][jump[j][k]]) % MOD;
            }
        }

        for (int i = 0; i <= 9; i++)
            counter = (counter + dp[n - 1][i]) % MOD;
        return counter;
    }
    void generateJumps()
    {
        jump.push_back({4, 6});
        jump.push_back({6, 8});
        jump.push_back({7, 9});
        jump.push_back({4, 8});
        jump.push_back({0, 3, 9});
        jump.push_back({});
        jump.push_back({0, 1, 7});
        jump.push_back({2, 6});
        jump.push_back({1, 3});
        jump.push_back({2, 4});
    }
};