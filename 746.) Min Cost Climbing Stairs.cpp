class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int prev1 = 0, prev2 = 0, current = 0;

        for (int i = 1; i < n; i++)
        {
            prev2 = prev1;
            prev1 = current;
            current = min(cost[i] + prev1, cost[i - 1] + prev2);
        }

        return current;
    }
};