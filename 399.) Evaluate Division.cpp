class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> adj;
        vector<double> answers;

        for(int i=0; i<equations.size(); i++)
        {
            adj[equations[i][0]].push_back({ equations[i][1], values[i]});
            adj[equations[i][1]].push_back({ equations[i][0], 1/values[i]});
        }

        for(int i=0; i<queries.size(); i++)
        {
            string start = queries[i][0];
            string end = queries[i][1];

            if(adj.find(start) == adj.end() || adj.find(end) == adj.end())
                answers.push_back(-1);
            else
            {
                map<string, bool> visited;
                double answer = 1;
                bool found = false;
                if(start == end)
                    found = true;
                else
                    dfs(start, end, adj, visited, answer, found);
                
                if(found == true)
                    answers.push_back(answer);
                else
                    answers.push_back(-1);
            }
        }

        return answers;
    }

    void dfs(string start, string end, map<string, vector<pair<string, double>>>& adj, map<string, bool>& visited, double& answer, bool& found) {
        visited[start] = true;

        for(auto i:adj[start])
        {
            if(!visited[i.first])
            {
                answer *= i.second;
                if(end == i.first)
                {
                    found = true;
                    return ;
                }
                dfs(i.first, end, adj, visited, answer, found);
                if(found == true)
                    return ;
                else
                    answer /= i.second;
            }
        }
    }
};