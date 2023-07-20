class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n, 0);
        vector<vector<int>> adj(n);

        for(int i=0; i<dislikes.size(); i++)
        {
            adj[dislikes[i][1]-1].push_back(dislikes[i][0]-1);
            adj[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
        }
        
        for(int i=0; i<adj.size(); i++)
        {
            if(!color[i])
            {
                if(!helper(i, adj, color))
                    return false;
            }
        }
        return true;
    }
    bool helper(int start, vector<vector<int>>& adj, vector<int>& color) {
        queue<int> q;
        int prevColor = -1;
        q.push(start);

        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int current = q.front();
                q.pop();

                for(int i=0; i<adj[current].size(); i++)
                {
                    if(!color[adj[current][i]])
                        q.push(adj[current][i]);
                }

                if(!color[current])
                {
                    if(prevColor == -1)
                        color[current] = 1;
                    else
                        color[current] = -1;
                }
                else if(color[current] == prevColor)
                    return false;
            }
            if(prevColor == -1)
                prevColor = 1;
            else
                prevColor = -1;
        }
        return true;
    }
};