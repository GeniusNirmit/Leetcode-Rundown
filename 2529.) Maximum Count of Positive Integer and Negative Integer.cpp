class Solution {
public:
    int maximumCount(vector<int>& a) {
        int positiveCounter = 0, negativeCounter = 0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i] > 0)
                positiveCounter++;
            else if(a[i] < 0)
                negativeCounter++;
        }
        return max(positiveCounter,negativeCounter);
    }
};