class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        vector<int> visited(n, 0);

        int totalEdges = edges.size();
        for (int i = 0; i < totalEdges; i++)
            visited[edges[i][1]] = 1;

        int champion = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
                champion++;
        }

        if (champion > 1)
            return -1;

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
                return i;
        }
        return -1;
    }
};