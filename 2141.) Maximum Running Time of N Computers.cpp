class Solution
{
public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        long long maxTime = 0;
        long long totalTime = 0;
        sort(batteries.begin(), batteries.end());

        for (int i = 0; i < batteries.size(); i++)
            totalTime += batteries[i];

        long long l = 1, h = totalTime, mid;
        while (l < h)
        {
            long long currentTime = 0;
            mid = (l + h + 1) / 2;

            for (int i = 0; i < batteries.size(); i++)
            {
                if (batteries[i] < mid)
                    currentTime += batteries[i];
                else
                    currentTime += mid;
            }

            if (mid * n > currentTime)
                h = mid - 1;
            else
                l = mid;
        }
        return l;
    }
};