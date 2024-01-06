class Solution
{
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<pair<int, pair<int, int>>> mp;
        vector<int> dp(n + 1, -1);

        for (int i = 0; i < n; i++)
            mp.push_back({startTime[i], {endTime[i], profit[i]}});

        sort(mp.begin(), mp.end());
        sort(startTime.begin(), startTime.end());

        return jobSchedule(n, mp, startTime, 0, dp);
    }
    int jobSchedule(int n, vector<pair<int, pair<int, int>>> &mp, vector<int> &startTime, int ind, vector<int> &dp)
    {
        if (ind >= n)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];

        int noJob = jobSchedule(n, mp, startTime, ind + 1, dp);
        int nextStartTime = lower_bound(startTime.begin(), startTime.end(), mp[ind].second.first) - startTime.begin();
        int job = jobSchedule(n, mp, startTime, nextStartTime, dp) + mp[ind].second.second;

        return dp[ind] = max(job, noJob);
    }
};