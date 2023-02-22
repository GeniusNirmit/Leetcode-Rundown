class Solution {
public:
    bool possible(vector<int> weights, int days, int limit) {
        int totalWeight = 0, currDay = 1;
        for(int i=0;i<weights.size();i++)
        {
            if(weights[i] > limit)
                return false;
            if(totalWeight + weights[i] > limit)
            {
                currDay++;
                totalWeight = weights[i];
            }
            else
                totalWeight += weights[i];
        }
        if(currDay <= days)
            return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1, h = 500*50000, mid;
        while(l<h)
        {
            mid = (l+h)/2;
            if(possible(weights, days, mid))
                h = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};