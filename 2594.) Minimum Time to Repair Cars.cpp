class Solution {
public:
    bool isRepair(vector<int>& ranks, long long mid, long long cars) {
        long long repair = 0;
        for(int i = 0; i<ranks.size(); i++)
            repair += sqrt(mid / ranks[i]);
        if(repair >= cars)
            return true;
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1, h = 1e18;
        while(l <= h) 
        {
            long long mid = (l + h) / 2;
            if(isRepair(ranks, mid, cars))
                h = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};