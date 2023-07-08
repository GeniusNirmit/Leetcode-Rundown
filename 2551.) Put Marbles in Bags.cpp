class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> sum;
        long long max = 0, min = 0;
        for(int i=0; i<weights.size()-1; i++)
            sum.push_back(weights[i] + weights[i+1]);
        sort(sum.begin(), sum.end());
        
        for(int i=0; i<k - 1; i++)
        {
            max += sum[sum.size() - i - 1];
            min += sum[i];
        }

        return max - min;
    }
};