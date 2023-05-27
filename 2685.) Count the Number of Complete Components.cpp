class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        int counter = 0;

        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i=0; i<n; i++)
        {
            int nodeCounter = 0;
            int edgeCounter = 0;

            if(!visited[i]) 
            {
                dfs(i, adj, visited, nodeCounter, edgeCounter);
                if(nodeCounter * (nodeCounter - 1) == edgeCounter)
                    counter++;
            }
        }

        return counter;
    }
    void dfs(int current, vector<vector<int>>& adj, vector<bool>& visited, int& nodeCounter, int& edgeCounter) {
        visited[current] = true;
        nodeCounter++;
        edgeCounter += adj[current].size();

        for(int i=0; i<adj[current].size(); i++)
        {
            if(!visited[adj[current][i]])
                dfs(adj[current][i], adj, visited, nodeCounter, edgeCounter);
        }
    }
};