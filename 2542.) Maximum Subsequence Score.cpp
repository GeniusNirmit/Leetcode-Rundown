class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<long long> sums(nums1.size(),0);
        vector<pair<int,int>> pairs;
        multiset<int> s;
        int n = nums1.size();
        long long maximumScore = 0;
        long long sum = 0;
        
        for(int i=0; i<n; i++)
            pairs.push_back({ nums2[i], nums1[i]});
    
        sort(pairs.begin(),pairs.end());
        
        for(int i=n-1; i>=n-k; i--)
        {
            s.insert(pairs[i].second);
            sum += pairs[i].second;
        }
        sums[n-k] = sum;
        
        for(int i=n-k-1; i>=0; i--)
        {
            sum -= *s.begin();
            s.erase(s.begin());
            s.insert(pairs[i].second);
            sum += pairs[i].second;
            sums[i]=sum;
        }
            
        for(int i=0; i<n; i++)
            maximumScore = max(maximumScore, sums[i] * pairs[i].first);
        
        return maximumScore;
    }
};