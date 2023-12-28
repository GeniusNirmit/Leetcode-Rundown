class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int n = colors.length();
        int minTime = 0;

        for (int i = 1; i < n; i++)
        {
            int currentMaxTime = neededTime[i - 1];
            while (colors[i - 1] == colors[i])
            {
                if (currentMaxTime < neededTime[i])
                {
                    minTime += currentMaxTime;
                    currentMaxTime = neededTime[i];
                }
                else
                    minTime += neededTime[i];
                i++;
            }
        }
        return minTime;
    }
};