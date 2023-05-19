class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colored(graph.size(), 0);
        for(int i=0; i<graph.size(); i++)
        {
            if(colored[i] == 0)
            {
                if(helper(graph, colored, i) == false)
                   return false;       
            }
        }
        return true;
    }
    bool helper(vector<vector<int>>& graph,vector<int>& colored, int start) {
        queue<int> q;
        q.push(start);
        int prevColor = -1;
        
        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                int current = q.front();
                q.pop();

                for(int i=0; i<graph[current].size(); i++)
                {
                    if(colored[graph[current][i]] == 0)
                        q.push(graph[current][i]);
                }

                if(colored[current] == 0)
                {
                    if(prevColor == -1)
                        colored[current] = 1;
                    else
                        colored[current] = -1;
                }
                else if(colored[current] == prevColor)
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