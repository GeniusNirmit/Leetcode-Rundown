class Solution {
public:
    int minSubArrayLen(int target, vector<int>& a) {
        int j = 0;
        int targetSum = 0;
        int minimumLength = a.size()+1;
        for(int i=0;i<a.size();i++)
        {
            targetSum += a[i];
            if(targetSum>=target)
            {
                while(targetSum>=target)
                {
                    minimumLength = min(minimumLength,i-j+1);
                    targetSum -= a[j];
                    j++;
                }
            }
        }
        if(minimumLength==a.size()+1)
            return 0;
        return minimumLength;
    }
};