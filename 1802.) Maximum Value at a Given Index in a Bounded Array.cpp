class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long l = 1, h = maxSum, mid, maxVal = 1;
        while(l <= h)
        {
            long long sum = 0; 
            mid = (l + h)/2;

            if(mid > index)
                sum = (mid * (mid + 1) - (mid - index) * (mid - index - 1)) / 2;
            else
                sum = ((mid * (mid + 1)) / 2 + (index - mid + 1));
            
            sum -= mid;
            
            if(mid > (n - index - 1))
                sum += (mid * (mid + 1) - (mid - (n - index - 1)) * (mid - (n - index - 1) - 1)) / 2;
            else
                sum += ((mid * (mid + 1)) / 2 + ((n - index - 1) - mid + 1));
            
            if(sum <= maxSum)
            {
                l = mid + 1;
                maxVal = max(maxVal, mid);
            }
            else
                h = mid - 1;
            
        }
        
        return maxVal;
    }
};