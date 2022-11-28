// Approach-1

class Solution {
public:
    int missingNumber(vector<int>& a) {
        int max = 0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i] > max)
                max = a[i];
        }
        int sum = (max*(max+1))/2;
        bool isZero = false;
        for(int i=0;i<a.size();i++)
        {
            sum -= a[i];
            if(a[i]==0)
                isZero = true;
        }
        if(isZero && sum==0)
            return max+1;
        else if(isZero)
            return sum;
        return 0;
    }
};