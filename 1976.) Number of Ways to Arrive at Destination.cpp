class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long MOD = 1e9 + 7;
        vector<vector<pair<long long,long long>>> adj(n);
        vector<long long> ways(n, 0);
        vector<long long> distance(n, LONG_MAX);
        priority_queue<pair<long long, long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;

        for(long long i=0; i<roads.size(); i++)
        {
            adj[roads[i][0]].push_back({ roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({ roads[i][0], roads[i][2]});
        }

        ways[0] = 1;
        distance[0] = 0;
        pq.push({0, 0});

        while(!pq.empty())
        {
            long long currentDistance = pq.top().first;
            long long current = pq.top().second;
            pq.pop();

            for(long long i=0; i<adj[current].size(); i++)
            {
                long long next = adj[current][i].first;
                long long nextDistance = adj[current][i].second;

                if(currentDistance + nextDistance < distance[next])
                {
                    distance[next] = currentDistance + nextDistance;
                    pq.push({ currentDistance + nextDistance, next});
                    ways[next] = ways[current];
                }
                else if(currentDistance + nextDistance == distance[next])
                    ways[next] +=(ways[current]) % MOD;
            }
        }

        return ways[n - 1] % MOD;
    }
};