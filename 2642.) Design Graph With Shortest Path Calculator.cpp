class Graph
{
    vector<vector<pair<int, int>>> adj;
    int size = 0;

public:
    Graph(int n, vector<vector<int>> &edges)
    {
        adj.resize(n);
        for (int i = 0; i < edges.size(); i++)
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        size = n;
    }

    void addEdge(vector<int> edge)
    {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2)
    {
        vector<int> distances(size, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        distances[node1] = 0;
        pq.push({0, node1});

        while (!pq.empty())
        {
            int dist = pq.top().first;
            int current = pq.top().second;
            pq.pop();

            for (auto i : adj[current])
            {
                int next = i.first;
                int nextDist = i.second;
                if (dist + nextDist < distances[next])
                {
                    distances[next] = dist + nextDist;
                    pq.push({distances[next], next});
                }
            }
        }

        if (distances[node2] == INT_MAX)
            return -1;
        return distances[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */