class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int src, int dest)
    {
        vector<vector<pair<double, int>>> adj(n);

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({succProb[i], edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }

        priority_queue<pair<double, int>> pq;
        vector<double> maxProb(n);

        maxProb[src] = 1.0;
        pq.push({1.0, src});

        while (!pq.empty())
        {
            double currentProb = pq.top().first;
            int currentNode = pq.top().second;
            pq.pop();

            if (currentNode == dest)
                return currentProb;

            for (int i = 0; i < adj[currentNode].size(); i++)
            {
                double nextProb = adj[currentNode][i].first;
                int nextNode = adj[currentNode][i].second;

                if (nextProb * currentProb > maxProb[nextNode])
                {
                    maxProb[nextNode] = currentProb * nextProb;
                    pq.push({maxProb[nextNode], nextNode});
                }
            }
        }

        return 0;
    }
};