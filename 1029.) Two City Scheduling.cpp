class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int,int>> difference;
        int sum = 0;
        for(int i=0;i<costs.size();i++)
            difference.push_back({costs[i][0]-costs[i][1], i});
        sort(difference.begin(), difference.end());
        for(int i=0;i<difference.size();i++)
        {
            if(i < difference.size()/2)
                sum += costs[difference[i].second][0];
            else
                sum += costs[difference[i].second][1];
        }
        return sum;
    }
};