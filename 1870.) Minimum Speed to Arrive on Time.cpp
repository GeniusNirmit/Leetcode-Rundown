class Solution {
public:
    bool canReachInTime(vector<int> dist, int speed, double hour) {
        double time = 0;
        for(int i=0;i<dist.size();i++)
        {
            time = ceil(time);
            time += (dist[i]/(speed * 1.0));
        }
        if(time <= hour)
            return true;
        return false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1, h = INT_MAX, mid;
        while(l < h)
        {
            mid = l + (h-l)/2;
            if(canReachInTime(dist, mid, hour))
                h = mid;
            else
                l = mid + 1;
        }
        if(l == INT_MAX)    
            return -1;
        return l;
    }
};