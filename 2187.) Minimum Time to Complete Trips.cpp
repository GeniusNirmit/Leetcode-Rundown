class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 0, h = 1LL * *max_element(time.begin(), time.end()) * totalTrips, mid;
        while(l < h)
        {
            mid = (l + h)/2;
            long long sum = 0;
            for(int i=0;i<time.size();i++)
                sum += mid / time[i];

            if(sum >= totalTrips)
                    h = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};