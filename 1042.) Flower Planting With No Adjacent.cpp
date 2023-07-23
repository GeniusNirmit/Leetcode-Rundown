class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n+1);
        vector<int> planted(n+1, 0);    
        queue<int> q;

        for(int i=0; i<paths.size(); i++)
        {
            adj[paths[i][0]].push_back(paths[i][1]);
            adj[paths[i][1]].push_back(paths[i][0]);
        }
        
        plantFlower(n, 1, adj, planted);

        planted.erase(planted.begin());
        return planted;
    }
    bool plantFlower(int n, int current, vector<vector<int>>& adj, vector<int>& planted) {
        if(current == n+1)
            return true;
        
        for(int flower=1; flower<=4; flower++)
        {
            if(adjSame(current, flower, adj, planted))
            {
                planted[current] = flower;
                if(plantFlower(n, current + 1, adj, planted))
                    return true;
                planted[current] = 0;
            }
        }
        return false;
    }
    bool adjSame(int current, int flower, vector<vector<int>>& adj, vector<int>& planted) {
        for(int i=0; i<adj[current].size(); i++)
        {
            if(flower == planted[adj[current][i]])
                return false;
        }
        return true;
    }
};