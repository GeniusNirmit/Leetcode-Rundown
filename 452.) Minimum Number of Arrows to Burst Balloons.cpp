class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int arrows = 0;
        int i = 0;
        while (i < points.size()) {
            int maxVal = points[i][1];
            while (i < points.size() && points[i][0] <= maxVal) {
                maxVal = min(maxVal, points[i][1]);
                i++;
            }
            arrows++;
        }
        return arrows;
    }
};