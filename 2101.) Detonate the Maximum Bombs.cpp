class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int maxBombs = 0;
        unordered_map<int, vector<int>> adj;

        generateGraph(bombs, adj);

        for(int i=0; i<bombs.size(); i++)
        {
            unordered_set<int> visited;
            if(visited.find(i) == visited.end())
                maxBombs = max(maxBombs, dfs(adj, visited, i));
        }
        return maxBombs;
    }
    void generateGraph(vector<vector<int>>& bombs, unordered_map<int, vector<int>>& adj) {      
        for(int i=0; i<bombs.size(); i++)
        {
            for(int j=0; j<bombs.size(); j++)
            {
                if(i != j)
                {
                    if(withinRange(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1], bombs[i][2]))
                        adj[i].push_back(j);
                }
            }
        }
    }
    bool withinRange(int x1, int y1, int x2, int y2, int rad) {
        long long dist = (pow((x2 - x1), 2) + pow((y2 - y1), 2));

        if(sqrt(dist) <= rad)
            return true;
        return false;
    }
    int dfs(unordered_map<int, vector<int>>& adj, unordered_set<int>& visited
    , int current) {
        visited.insert(current);

        for(int i=0; i<adj[current].size(); i++)
        {
            if(visited.find(adj[current][i]) == visited.end())
                dfs(adj, visited, adj[current][i]);
        }
        return visited.size();
    }
};