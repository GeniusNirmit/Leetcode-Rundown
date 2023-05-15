class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int counter = 0;
        vector<bool> visited(isConnected.size(), false);
        for(int i=0; i<isConnected.size(); i++)
        {
            if(!visited[i])
            {
                counter++;
                dfs(visited, isConnected, i);
            }
        }
        return counter;
    }
    void dfs(vector<bool>& visited, vector<vector<int>>& isConnected, int current) {
        visited[current] = true;
        for(int i=0; i<isConnected.size(); i++)
        {
            if(isConnected[current][i] && !visited[i])
                dfs(visited, isConnected, i);
        }
    }
};