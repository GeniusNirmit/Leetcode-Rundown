class Solution {
public:
    long long maximumSubarraySum(vector<int>& a, int k) {
        long long sum = 0;
        long long max = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<a.size();i++)
        {
            if(i>=k)
            {
                mp[a[i-k]]--;
                sum -= a[i-k];
                if(mp[a[i-k]] <= 0)
                    mp.erase(mp.find(a[i-k]));
            }
            mp[a[i]]++;
            sum += a[i];
            if(mp.size() == k)
            {
                if(max < sum)
                    max = sum;
            }
        }
        return max;
    }
};