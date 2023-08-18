class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        int edges = roads.size();
        vector<vector<bool>> adj(n, vector<bool>(n, false));
        vector<int> degree(n, 0);
        int maxCounter = 0;
        for (int i = 0; i < edges; i++)
        {
            adj[roads[i][0]][roads[i][1]] = true;
            adj[roads[i][1]][roads[i][0]] = true;
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    int counter = degree[i] + degree[j];
                    if (adj[i][j])
                        counter -= 1;
                    maxCounter = max(maxCounter, counter);
                }
            }
        }

        return maxCounter;
    }
};