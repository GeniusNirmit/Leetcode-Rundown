class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multimap<int, vector<int>> sortedCoordinates;
        vector<vector<int>> coordinates;
        for(int i=0;i<points.size();i++)
        {
            int distance = (points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            vector<int> coordinate(2);
            coordinate[0] = points[i][0];
            coordinate[1] = points[i][1];
            sortedCoordinates.insert({distance,coordinate});
        }
        auto i = sortedCoordinates.begin();
        while(k--)
        {
            coordinates.push_back(i->second);
            i++;
        }
        return coordinates;
    }
};