class Solution {
public:
    int totalSteps(vector<int> &v,int n) {
        if(n==0 || n==1)
            return 1;
        v.push_back(totalSteps(v,n-1));
        return v[v.size()-1] + v[v.size()-2];
    }
    int climbStairs(int n) {
        vector<int> v;
        v.push_back(1);
        v.push_back(1);
        return totalSteps(v,n);
    }
};