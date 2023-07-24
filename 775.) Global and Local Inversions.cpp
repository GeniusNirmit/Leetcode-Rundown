class Solution {
public:
    bool isIdealPermutation(vector<int>& a) {
        int maxVal = INT_MIN;
        for(int i=1; i<a.size(); i++)
        {
            if(maxVal > a[i])
                return false;
            maxVal = max(maxVal, a[i-1]);
        }
        return true;
    }
};