class Solution {
public:
    int minimumAverageDifference(vector<int>& a) {
        long long sum = 0;
        int min = INT_MAX;
        int index = 0;
        for(int i=0;i<a.size();i++)
            sum += a[i];
        long long temp_sum = 0;
        for(int i=0;i<a.size()-1;i++)
        {
            temp_sum += a[i];
            long long temp = temp_sum/(i+1) - (sum-temp_sum)/(a.size()-i-1);
            if(temp < 0)
                temp = -temp;
            if(temp < min)
            {
                min = temp;
                index = i;
            }
        }
        if(min > (sum/a.size()))
           return a.size()-1;
        return index;
    }
};