class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int m = rolls.size();
        int N = m + n;
        int target;
        vector<int> missingRolls(n, 1);
        int sum = 0, missingSum = n, totalSum = 0;

        for (int i = 0; i < m; i++)
            sum += rolls[i];
        cout << sum;

        target = (N * mean) - sum;

        if (target > n * 6 || target < n || sum > N * mean)
            return {};

        target -= n;
        for (int i = 0; i < n; i++)
        {
            if (target > 0)
            {
                missingRolls[i] += min(target, 5);
                target -= min(target, 5);
            }
        }
        return missingRolls;
    }
};