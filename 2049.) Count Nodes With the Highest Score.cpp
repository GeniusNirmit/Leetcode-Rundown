class Solution
{
    void dfs(int n, vector<vector<int>> &adj, vector<int> &counter, int current, int prev)
    {
        for (int i = 0; i < adj[current].size(); i++)
        {
            if (adj[current][i] != prev)
            {
                dfs(n, adj, counter, adj[current][i], current);
                counter[current] += counter[adj[current][i]];
            }
        }
        counter[current]++;
    }

public:
    int countHighestScoreNodes(vector<int> &parents)
    {
        int n = parents.size();
        vector<vector<int>> adj(n);
        vector<int> counter(n, 0);
        map<long long, int, greater<long long>> mp;

        for (int i = 1; i < n; i++)
            adj[parents[i]].push_back(i);

        dfs(n, adj, counter, 0, -1);

        for (int i = 0; i < n; i++)
        {
            long long maxVal = max(1, n - counter[i]);
            for (int j = 0; j < adj[i].size(); j++)
                maxVal *= counter[adj[i][j]];

            mp[maxVal]++;
        }

        return mp.begin()->second;
    }
};