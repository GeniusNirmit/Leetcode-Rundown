class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        long long sum = 0, maxSum = 0;
        for(int i=0; i<gain.size(); i++)
        {
            sum += gain[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};