class Solution {
    bool cutThreeSections(vector<pair<int, int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        int counter = 1;
        int lastEnd = intervals[0].second;

        for(int i = 1; i < n; i++) {
            if(intervals[i].first < lastEnd) {
                lastEnd = max(lastEnd, intervals[i].second);
            } else {
                counter++;
                lastEnd = intervals[i].second;
            }

            if(counter >= 3) {
                return true;
            }
        }

        return false;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int m = rectangles.size();
        vector<pair<int, int>> xIntervals, yIntervals;

        for(int i = 0; i < m; i++) {
            xIntervals.push_back({rectangles[i][0], rectangles[i][2]});
            yIntervals.push_back({rectangles[i][1], rectangles[i][3]});
        }

        return cutThreeSections(xIntervals) || cutThreeSections(yIntervals);
    }
};