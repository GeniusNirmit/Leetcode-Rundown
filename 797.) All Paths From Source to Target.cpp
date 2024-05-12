class Solution
{
    void traverse(vector<vector<int>> &graph, int src, int dest, vector<int> &path, vector<vector<int>> &paths)
    {
        if (src == dest)
            paths.push_back(path);

        for (int i = 0; i < graph[src].size(); i++)
        {
            path.push_back(graph[src][i]);
            traverse(graph, graph[src][i], dest, path, paths);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<vector<int>> paths;
        vector<int> path;
        path.push_back(0);

        traverse(graph, 0, n - 1, path, paths);

        return paths;
    }
};