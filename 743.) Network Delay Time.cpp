class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        vector<int> minTimes(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int minDelay = INT_MIN;

        for(int i=0; i<times.size(); i++)
            adj[times[i][0]].push_back({ times[i][2], times[i][1]});
        
        minTimes[k] = 0;
        pq.push({0, k});

        while(!pq.empty())
        {
            int time = pq.top().first;
            int current = pq.top().second;
            pq.pop();
            for(auto i: adj[current])
            {
                int nextTime = i.first;
                int next = i.second;
                if(time + nextTime < minTimes[next])
                {
                    minTimes[next] = time + nextTime;
                    pq.push({minTimes[next], next});
                }
            }
        }

        for(int i=1; i<minTimes.size(); i++)
            minDelay = max(minDelay, minTimes[i]);

        if(minDelay == INT_MAX)
            return -1;
        return minDelay;
    }
};