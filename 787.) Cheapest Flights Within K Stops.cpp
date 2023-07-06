class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n); 
        queue<pair<int, pair<int, int>>> q;
        vector<int> minCosts(n, INT_MAX);

        for(int i=0; i<flights.size(); i++)
            adj[flights[i][0]].push_back({ flights[i][1], flights[i][2]});
        
        q.push({0, { src, 0}});
        minCosts[src] = 0;
        while(!q.empty())
        {
            int stops = q.front().first;
            int current = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            for(int i=0; i<adj[current].size(); i++)
            {
                int next = adj[current][i].first;
                int nextCost = adj[current][i].second;

                if(cost + nextCost < minCosts[next] && stops <= k )
                {
                    minCosts[next] = cost + nextCost;
                    q.push({ stops+1, { next, cost + nextCost}});
                }
            }
        }

        if(minCosts[dst] == INT_MAX)
            return -1;
        return minCosts[dst];
    }
};