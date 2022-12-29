class Solution {
public:
    double findMaxAverage(vector<int>& a, int k) {
        double maxAverage = INT_MIN;
        double sum = 0;
        for(int i=0;i<a.size();i++)
        {
            sum += a[i];
            if(i+1 >= k)
            {
                if(maxAverage < (sum/k))
                    maxAverage = sum/k;
                sum -= a[i-k+1];
            }
        }
        return maxAverage;
    }
};