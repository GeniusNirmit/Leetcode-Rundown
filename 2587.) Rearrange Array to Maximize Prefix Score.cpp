class Solution {
public:
    int maxScore(vector<int>& nums) {
        vector<int> a = nums;
        sort(a.begin(), a.end(), greater<int> ());
        long long counter = 0, sum = 0;
        for(int i=0;i<a.size();i++)
        {
            sum += a[i];
            if(sum > 0)
                counter++;
        }
        return counter;
    }
};