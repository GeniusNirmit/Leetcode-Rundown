class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int minutes = 0, charCounter = 0;
        unordered_map<char,int> maxPositions;
        for(int i=0;i<garbage.size();i++)
        {
            for(int j=0;j<garbage[i].size();j++)
                maxPositions[garbage[i][j]] = i;
            charCounter += garbage[i].size();
        }
        minutes += charCounter;
        for(auto i:maxPositions)
        {
            for(int j=0;j<i.second;j++)
                minutes += travel[j];
        }
        return minutes;
    }
};