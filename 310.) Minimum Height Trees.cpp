class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        int totalEdges = edges.size();
        vector<unordered_set<int>> adj(n);
        vector<int> outerNodes;

        if (n <= 2)
        {
            for (int i = 0; i < n; i++)
                outerNodes.push_back(i);
            return outerNodes;
        }

        for (int i = 0; i < totalEdges; i++)
        {
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (adj[i].size() == 1)
                outerNodes.push_back(i);
        }

        while (true)
        {
            vector<int> innerNodes;
            for (int i = 0; i < outerNodes.size(); i++)
            {
                for (auto j : adj[outerNodes[i]])
                {
                    adj[j].erase(outerNodes[i]);
                    if (adj[j].size() == 1)
                        innerNodes.push_back(j);
                }
            }

            if (innerNodes.empty())
                return outerNodes;

            outerNodes = innerNodes;
        }
        return outerNodes;
    }
};