class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0, max = 0;
        for(int i=0;i<candies.size();i++)
        {
            sum += candies[i];
            if(candies[i] > max)
                max = candies[i];
        }
        if(sum < k)
            return 0;

        long long l = 1, h = max * 1LL, mid;
        long long maxCandies = 0;
        while(l <= h)
        {
            mid = (l + h)/2;
            long long counter = 0;
            for(int i=0;i<candies.size();i++)
                counter += candies[i]/mid;
            if(counter < k)
                h = mid - 1;
            else
            {
                l = mid + 1;
                maxCandies = mid;
            }
        }
        return maxCandies;
    }
};