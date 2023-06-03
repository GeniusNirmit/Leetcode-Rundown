class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n);

        for(int i=0; i<manager.size(); i++)
        {
            if(manager[i] != -1)
                adj[manager[i]].push_back(i);
        }
        
        return dfs(adj, informTime, visited, headID);
    }
    int dfs(vector<vector<int>>& adj, vector<int>& informTime, vector<bool>& visited, int current) {
        visited[current] = true;
        int maxTime = 0;

        for(int i=0; i<adj[current].size(); i++)
        {
            if(!visited[adj[current][i]])
                maxTime = max(maxTime, dfs(adj, informTime, visited, adj[current][i]));
        }

        return maxTime + informTime[current];
    }
};