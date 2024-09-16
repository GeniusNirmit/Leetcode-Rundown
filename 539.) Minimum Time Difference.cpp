class Solution
{
public:
    int timePointToMinute(string timePoint)
    {
        int hr = stoi(timePoint.substr(0, 2));
        int min = stoi(timePoint.substr(3, 2));

        return hr * 60 + min;
    }
    int findMinDifference(vector<string> &timePoints)
    {
        int n = timePoints.size();
        int minTime = INT_MAX;
        vector<int> minutes;

        for (int i = 0; i < n; i++)
            minutes.push_back(timePointToMinute(timePoints[i]));

        sort(minutes.begin(), minutes.end());

        for (int i = 1; i < n; i++)
            minTime = min(minTime, minutes[i] - minutes[i - 1]);

        minTime = min(minTime, 1440 + minutes[0] - minutes[n - 1]);
        return minTime;
    }
};