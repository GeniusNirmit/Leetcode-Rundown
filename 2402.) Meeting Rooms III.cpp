class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        int m = meetings.size();
        vector<long long> roomAvailabilityTime(n, 0);
        vector<int> meetingCount(n, 0);
        sort(meetings.begin(), meetings.end());

        for (int i = 0; i < m; i++)
        {
            int start = meetings[i][0], end = meetings[i][1];
            long long minRoomAvailabilityTime = LLONG_MAX;
            int minAvailableTimeRoom = 0;
            bool foundUnusedRoom = false;

            for (int j = 0; j < n; j++)
            {
                if (roomAvailabilityTime[j] <= start)
                {
                    foundUnusedRoom = true;
                    meetingCount[j]++;
                    roomAvailabilityTime[j] = end;
                    break;
                }

                if (minRoomAvailabilityTime > roomAvailabilityTime[j])
                {
                    minRoomAvailabilityTime = roomAvailabilityTime[j];
                    minAvailableTimeRoom = j;
                }
            }

            if (!foundUnusedRoom)
            {
                roomAvailabilityTime[minAvailableTimeRoom] += end - start;
                meetingCount[minAvailableTimeRoom]++;
            }
        }

        int maxMeetingCount = 0, maxMeetingCountRoom = 0;
        for (int i = 0; i < n; i++)
        {
            if (meetingCount[i] > maxMeetingCount)
            {
                maxMeetingCount = meetingCount[i];
                maxMeetingCountRoom = i;
            }
        }

        return maxMeetingCountRoom;
    }
};