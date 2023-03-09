class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hours) {
        int l = 1, h = *max_element(piles.begin(),piles.end()), mid;
        while(l < h)
        {
            mid = (l + h)/2;
            int counter = 0;
            for(int i=0;i<piles.size();i++)
                counter += ceil(piles[i] / (double)mid);
            if(counter <= hours)
                h = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};