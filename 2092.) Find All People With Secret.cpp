class Solution
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        int totalMeetings = meetings.size();
        vector<vector<pair<int, int>>> adj(n);
        vector<int> earliestTime(n, INT_MAX);
        vector<int> peopleWithSecret;
        queue<pair<int, int>> q;

        for (int i = 0; i < totalMeetings; i++)
        {
            adj[meetings[i][0]].push_back({meetings[i][1], meetings[i][2]});
            adj[meetings[i][1]].push_back({meetings[i][0], meetings[i][2]});
        }

        earliestTime[0] = 0;
        earliestTime[firstPerson] = 0;
        q.push({0, 0});
        q.push({firstPerson, 0});

        while (!q.empty())
        {
            int current = q.front().first;
            int currentTime = q.front().second;
            q.pop();

            int size = adj[current].size();
            for (int i = 0; i < size; i++)
            {
                int nextPerson = adj[current][i].first;
                int nextTime = adj[current][i].second;

                if (nextTime >= currentTime && earliestTime[nextPerson] > nextTime)
                {
                    earliestTime[nextPerson] = nextTime;
                    q.push({nextPerson, nextTime});
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (earliestTime[i] != INT_MAX)
                peopleWithSecret.push_back(i);
        }
        return peopleWithSecret;
    }
};