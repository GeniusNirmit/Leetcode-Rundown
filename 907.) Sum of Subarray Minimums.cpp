class Solution
{
    long long MOD = 1e9 + 7;

public:
    int sumSubarrayMins(vector<int> &a)
    {
        int n = a.size();
        stack<int> s;
        vector<int> dp(n);
        int sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && a[i] <= a[s.top()])
                s.pop();
            if (s.empty())
                dp[i] = -1;
            else
                dp[i] = s.top();
            s.push(i);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (dp[i] == -1)
                a[i] = (n - i) * a[i];
            else
                a[i] = a[dp[i]] + a[i] * (dp[i] - i);
            sum += a[i];
            sum %= MOD;
        }
        return sum % MOD;
    }
};