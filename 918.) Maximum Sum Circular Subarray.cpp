class Solution {
public:
    int kadaneAlgorithm(vector<int> &a)
    {
        int maxSum = INT_MIN;
        int sum = 0;
        for(int i=0;i<a.size();i++)
        {
            sum += a[i];
            if(maxSum < sum)
                maxSum = sum;
            if(sum < 0)
                sum = 0;
        }
        return maxSum;
    }

    int maxSubarraySumCircular(vector<int> &a)
    {
        int conventionalKadane = kadaneAlgorithm(a);
        if(conventionalKadane < 0)
            return conventionalKadane;
        int totalSum = 0;
        for(int i=0;i<a.size();i++)
        {
            totalSum += a[i];
            a[i] *= -1;
        }
        int inverseKadane = totalSum + kadaneAlgorithm(a);
        return max(conventionalKadane,inverseKadane);
    }
};