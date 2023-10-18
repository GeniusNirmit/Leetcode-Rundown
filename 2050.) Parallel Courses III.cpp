class Solution
{
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        vector<int> maxTime(n);
        queue<int> q;
        int minTime = 0;

        for (int i = 0; i < relations.size(); i++)
            adj[relations[i][0] - 1].push_back(relations[i][1] - 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
                indegree[adj[i][j]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                maxTime[i] = time[i];
            }
        }

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            for (int i = 0; i < adj[current].size(); i++)
            {
                maxTime[adj[current][i]] = max(maxTime[adj[current][i]], maxTime[current] + time[adj[current][i]]);
                indegree[adj[current][i]]--;
                if (indegree[adj[current][i]] == 0)
                    q.push(adj[current][i]);
            }
        }

        for (int i = 0; i < n; i++)
            minTime = max(minTime, maxTime[i]);
        return minTime;
    }
};