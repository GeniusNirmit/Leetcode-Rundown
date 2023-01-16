class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> mergedIntervals;
        vector<int> tempInterval = intervals[0];
        for(int i=0;i<intervals.size();i++)
        {
            if(intervals[i][0] <= tempInterval[1])
                tempInterval[1] = max(tempInterval[1],intervals[i][1]);
            else
            {
                mergedIntervals.push_back(tempInterval);
                tempInterval = intervals[i];
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
    }
};