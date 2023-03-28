class Solution {
public:
    int maxAbsoluteSum(vector<int>& a) {
        int maxSum = INT_MIN, minSum = INT_MAX, sum = 0;

        for(int i=0;i<a.size();i++)
        {
            sum += a[i];
            maxSum = max(sum, maxSum);
            if(sum < 0)
                sum = 0; 
        }

        sum = 0;
        for(int i=0;i<a.size();i++)
        {
            sum += a[i];
            minSum = min(minSum, sum);
            if(sum > 0)
                sum = 0;
        }

        return max(maxSum, -minSum);
    }
};