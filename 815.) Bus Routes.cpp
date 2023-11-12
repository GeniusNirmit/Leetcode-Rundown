class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        int n = routes.size();
        int counter = 0;
        unordered_map<int, vector<int>> mp;
        queue<int> q;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < routes[i].size(); j++)
                mp[routes[i][j]].push_back(i);
        }

        q.push(source);

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int current = q.front();
                q.pop();

                if (current == target)
                    return counter;

                vector<int> buses = mp[current];
                for (int i = 0; i < buses.size(); i++)
                {
                    if (!visited[buses[i]])
                    {
                        for (int j = 0; j < routes[buses[i]].size(); j++)
                        {
                            if (routes[buses[i]][j] != current)
                                q.push(routes[buses[i]][j]);
                        }
                    }
                    visited[buses[i]] = true;
                }
            }
            counter++;
        }

        return -1;
    }
};