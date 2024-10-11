class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        int n = times.size();
        vector<pair<int, int>> events;
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> friendLeaving;

        for (int i = 0; i < n; i++)
        {
            events.push_back({times[i][0], i});
            events.push_back({times[i][1], -i});
        }
        sort(events.begin(), events.end());

        for (int i = 0; i < n; i++)
            availableChairs.push(i);

        for (int i = 0; i < 2 * n; i++)
        {
            int time = events[i].first;
            int friendInd = events[i].second;

            while (!friendLeaving.empty() && friendLeaving.top().first <= time)
            {
                availableChairs.push(friendLeaving.top().second);
                friendLeaving.pop();
            }

            if (friendInd >= 0)
            {
                int chair = availableChairs.top();
                availableChairs.pop();

                if (friendInd == targetFriend)
                    return chair;

                friendLeaving.push({times[friendInd][1], chair});
            }
        }

        return -1;
    }
};