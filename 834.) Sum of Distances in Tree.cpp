class Solution
{
    void dfs(vector<vector<int>> &adj, vector<int> &counter, vector<int> &distancesSum, int current, int prev)
    {
        for (int i = 0; i < adj[current].size(); i++)
        {
            if (adj[current][i] != prev)
            {
                dfs(adj, counter, distancesSum, adj[current][i], current);
                counter[current] += counter[adj[current][i]];
                distancesSum[current] += distancesSum[adj[current][i]] + counter[adj[current][i]];
            }
        }
        counter[current]++;
    }
    void dfs2(int n, vector<vector<int>> &adj, vector<int> &counter, vector<int> &distancesSum, int current, int prev)
    {
        for (int i = 0; i < adj[current].size(); i++)
        {
            if (adj[current][i] != prev)
            {
                distancesSum[adj[current][i]] = distancesSum[current] - counter[adj[current][i]] + n - counter[adj[current][i]];
                dfs2(n, adj, counter, distancesSum, adj[current][i], current);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        vector<int> counter(n), distancesSum(n);
        int totalEdges = edges.size();
        for (int i = 0; i < totalEdges; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        dfs(adj, counter, distancesSum, 0, -1);
        dfs2(n, adj, counter, distancesSum, 0, -1);
        return distancesSum;
    }
};