class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safeNodes;
        vector<bool> visited(graph.size(), false);
        vector<bool> pathVisited(graph.size(), false);
        vector<bool> check(graph.size(), false);

        for(int i=0; i<graph.size(); i++)
        {
            if(!visited[i])
                dfs(i, graph, visited, pathVisited, check);
        }

        for(int i=0; i<check.size(); i++)
        {
            if(check[i])
                safeNodes.push_back(i);
        }
    
        return safeNodes;
    }

    bool dfs(int current, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& pathVisited, vector<bool>& check) {
        visited[current] = true;
        pathVisited[current] = true;
        check[current] = false;

        for(int i=0; i<graph[current].size(); i++)
        {
            if(!visited[graph[current][i]])
            {
                if(dfs(graph[current][i], graph, visited, pathVisited, check))
                    return true;
            }
            else if(pathVisited[graph[current][i]])
                return true;
        }

        pathVisited[current] = false;
        check[current] = true;
        return false;
    }
};