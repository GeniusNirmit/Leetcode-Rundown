class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        int counter = 0, maxCounter = 0;
        vector<int> start, end;

        for (int i = 0; i < n; i++)
        {
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int startInd = 0, endInd = 0;

        while (startInd < n)
        {
            if (start[startInd] <= end[endInd])
            {
                counter++;
                startInd++;
            }
            else
            {
                counter--;
                endInd++;
            }

            maxCounter = max(maxCounter, counter);
        }

        return maxCounter;
    }
};