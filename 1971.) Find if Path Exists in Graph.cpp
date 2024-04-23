class Solution
{
    bool dfs(vector<vector<int>> &adj, vector<bool> &visited, int src, int dest)
    {
        if (src == dest)
            return true;

        visited[src] = true;

        bool flag = false;
        int size = adj[src].size();
        for (int i = 0; i < size; i++)
        {
            if (!visited[adj[src][i]])
                flag |= dfs(adj, visited, adj[src][i], dest);

            if (flag)
                return true;
        }

        return flag;
    }

public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        int totalEdges = edges.size();
        for (int i = 0; i < totalEdges; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        return dfs(adj, visited, source, destination);
    }
};