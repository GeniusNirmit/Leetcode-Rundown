class Solution
{
public:
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = factory.size();
        vector<int> factoryPos;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < factory[i][1]; j++)
                factoryPos.push_back(factory[i][0]);
        }

        int m = robot.size();
        n = factoryPos.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        vector<long long> next(n + 1, 0), current(n + 1, 0);

        for (int i = m - 1; i >= 0; i--)
        {
            if (i != m - 1)
                next[n] = 1e12 + 7;
            current[n] = 1e12 + 7;

            for (int j = n - 1; j >= 0; j--)
            {
                long long pick = abs(robot[i] - factoryPos[j]) + next[j + 1];
                long long notPick = current[j + 1];

                current[j] = min(pick, notPick);
            }
            next = current;
        }
        return current[0];
    }
};