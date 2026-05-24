class Solution {
    static bool cmp(vector<int> &interval1, vector<int> &interval2) {
        if(interval1[1] < interval2[1]) {
            return true;
        }

        return false;
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int counter = 0;
        sort(intervals.begin(), intervals.end(), cmp);

        vector<int> prevInterval = intervals[0];

        for(int i = 1; i < n; i++) {
            if(prevInterval[1] > intervals[i][0]) {
                counter++;
            } else {
                prevInterval = intervals[i];
            }
        }

        return counter;
    }
};