class Solution
{
public:
    int dijkstraAlgo(int n, vector<vector<pair<int, int>>> &adj, int src, int dest)
    {
        vector<int> minDist(n, 2e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        pq.push({0, src});
        minDist[src] = 0;

        while (!pq.empty())
        {
            int currentNode = pq.top().second;
            int currentDist = pq.top().first;
            pq.pop();

            if (currentDist <= minDist[currentNode])
            {
                for (int i = 0; i < adj[currentNode].size(); i++)
                {
                    int nextDist = adj[currentNode][i].first;
                    int nextNode = adj[currentNode][i].second;
                    if (currentDist + nextDist < minDist[nextNode])
                    {
                        minDist[nextNode] = currentDist + nextDist;
                        pq.push({currentDist + nextDist, nextNode});
                    }
                }
            }
        }

        return minDist[dest];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int source, int destination, int target)
    {
        int m = edges.size();
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<vector<int>> modEdges = edges;

        for (int i = 0; i < m; i++)
        {
            if (edges[i][2] != -1)
            {
                adj[edges[i][0]].push_back({edges[i][2], edges[i][1]});
                adj[edges[i][1]].push_back({edges[i][2], edges[i][0]});
            }
        }

        int shortestDist = dijkstraAlgo(n, adj, source, destination);

        if (shortestDist < target)
            return vector<vector<int>>();

        for (int i = 0; i < m; i++)
        {
            if (edges[i][2] == -1)
            {
                if (shortestDist == target)
                    modEdges[i][2] = 2e9;
                else
                    modEdges[i][2] = 1;

                adj[edges[i][0]].push_back({modEdges[i][2], edges[i][1]});
                adj[edges[i][1]].push_back({modEdges[i][2], edges[i][0]});

                if (shortestDist != target)
                {
                    int currentShortestDist = dijkstraAlgo(n, adj, source, destination);
                    cout << shortestDist << " " << currentShortestDist << endl;
                    if (currentShortestDist <= target)
                    {
                        shortestDist = currentShortestDist;
                        modEdges[i][2] += target - shortestDist;
                    }
                }
            }
        }

        if (shortestDist <= target)
            return modEdges;
        return vector<vector<int>>();
    }
};