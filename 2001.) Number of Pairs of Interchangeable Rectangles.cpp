class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double,long long> ratios;
        long long counter = 0;
        for(int i=0;i<rectangles.size();i++)
        {
            if(ratios.find(rectangles[i][0]/(double)rectangles[i][1]) != ratios.end())
                counter += ratios[rectangles[i][0]/(double)rectangles[i][1]];
            ratios[rectangles[i][0]/(double)rectangles[i][1]]++;
        }
        return counter;
    }
};