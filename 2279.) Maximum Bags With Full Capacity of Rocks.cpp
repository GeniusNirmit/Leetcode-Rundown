class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int counter = 0;
        for(int i=0;i<capacity.size();i++)
            capacity[i] -= rocks[i];
        sort(capacity.begin(),capacity.end());
        for(int i=0;i<capacity.size();i++)
        {
            if(additionalRocks >= capacity[i])
            {
                additionalRocks -= capacity[i];
                counter++;
            }
            else
                break;
        }
        return counter;
    }
};