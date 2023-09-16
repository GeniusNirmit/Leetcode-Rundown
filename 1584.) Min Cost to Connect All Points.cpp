class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ultParent_u = findParent(u);
        int ultParent_v = findParent(v);

        if (ultParent_u == ultParent_v)
        {
            parent[ultParent_u] = ultParent_v;
            size[ultParent_v] += (long long)size[ultParent_u];
        }
        else
        {
            parent[ultParent_v] = ultParent_u;
            size[ultParent_u] += (long long)size[ultParent_v];
        }
    }
};

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
                edges.push_back({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), {i, j}});
        }

        sort(edges.begin(), edges.end());

        DisjointSet d(n);
        int totalEdges = edges.size();
        int minCost = 0;
        for (int i = 0; i < totalEdges; i++)
        {
            int x = edges[i].second.first, y = edges[i].second.second;
            if (d.findParent(x) != d.findParent(y))
            {
                minCost += edges[i].first;
                d.unionBySize(x, y);
            }
        }

        return minCost;
    }
};