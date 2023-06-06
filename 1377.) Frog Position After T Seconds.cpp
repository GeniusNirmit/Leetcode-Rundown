class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n);
        vector<double> probablity(n, 0);
        vector<bool> visited(n, false);
        queue<int> q;
        int currentTime = t;

        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0] - 1].push_back(edges[i][1] - 1);
            adj[edges[i][1] - 1].push_back(edges[i][0] - 1);
        }
        
        q.push(0);
        probablity[0] = 1;
        while(!q.empty() && currentTime--)
        {
            double size = q.size();
            while(size--)
            {
                int current = q.front();
                int nextNodes = 0;
                q.pop();
                visited[current] = true;
                
                for(int i=0; i<adj[current].size(); i++)
                {
                    if(!visited[adj[current][i]])
                        nextNodes++;
                }
                
                for(int i=0; i<adj[current].size(); i++)
                {
                    if(!visited[adj[current][i]])
                    {
                        q.push(adj[current][i]);
                        probablity[adj[current][i]] = probablity[current] / nextNodes;
                    }
                } 

                if(nextNodes > 0)
                    probablity[current] = 0;
            }
        }
        return probablity[target - 1];
    }
};