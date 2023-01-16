class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> updatedIntervals;
        vector<int> tempInterval = newInterval;
        for(int i=0;i<intervals.size();i++)
        {
            if(intervals[i][0] > newInterval[1])
            {
                updatedIntervals.push_back(tempInterval);
                tempInterval = intervals[i];
            }
            else if(intervals[i][1] < newInterval[0])
                updatedIntervals.push_back(intervals[i]);
            else
            {
                tempInterval[0] = min(tempInterval[0],intervals[i][0]);
                tempInterval[1] = max(tempInterval[1],intervals[i][1]);
            }
        }
        updatedIntervals.push_back(tempInterval);
        return updatedIntervals;
    }
};