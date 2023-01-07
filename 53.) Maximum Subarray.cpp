class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int maxSum = INT_MIN,sum = 0;
        for(int i=0;i<a.size();i++)
        {
            sum += a[i];
            maxSum = max(sum,maxSum);
            if(sum < 0)
                sum = 0;
        }
        return maxSum;
    }
};