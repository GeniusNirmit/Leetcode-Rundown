class Solution {
    int time = 1;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n); 
        vector<bool> visited(n, false);
        vector<int> insertionTime(n), lowTime(n);
        vector<vector<int>> bridges;

        for(int i=0; i<connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        dfs(0, -1, visited, adj, insertionTime, lowTime, bridges);
        return bridges;
    }

    void dfs(int current, int parent, vector<bool>& visited, vector<vector<int>>& adj, vector<int>& insertionTime, vector<int>& lowTime, vector<vector<int>>& bridges) {
        visited[current] =  true;
        insertionTime[current] = lowTime[current] = time;
        time++;

        for(int i=0; i<adj[current].size(); i++)
        {
            if(adj[current][i] != parent)
            {
                if(!visited[adj[current][i]])
                {
                    dfs(adj[current][i], current, visited, adj, insertionTime, lowTime, bridges);

                    lowTime[current] = min(lowTime[current], lowTime[adj[current][i]]);
                    if(lowTime[adj[current][i]] > insertionTime[current])
                        bridges.push_back({ current, adj[current][i]});
                }
                else
                    lowTime[current] = min(lowTime[current], lowTime[adj[current][i]]);
            }
        }
    }
};