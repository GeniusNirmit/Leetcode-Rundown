class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size())
            return -1;
        
        int minDay = *min_element(bloomDay.begin(), bloomDay.end());
        int maxDay = *max_element(bloomDay.begin(), bloomDay.end());
        int minimumDays = -1;

        int l = minDay, h = maxDay, mid;
        while(l <= h)
        {
            mid = (l+h)/2;
            if(ifPossible(bloomDay, mid, m, k))
            {
                minimumDays = mid;
                h = mid - 1;
            }
            else
                l = mid + 1;
        }
        return minimumDays;
    }
    bool ifPossible(vector<int>& bloomDay, int val, int m, int k) {
        int size = k;

        for(int i=0; i<bloomDay.size(); i++)
        {
            if(!m)
                return true;
            if(bloomDay[i] <= val)
            {
                size--;
                if(!size)
                {
                    size = k;
                    m--;
                }
            }
            else
                size = k;
        }

        if(m <= 0)
            return true;
        return false;
    }
};