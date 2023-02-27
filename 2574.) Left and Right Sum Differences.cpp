class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& a) {
        vector<int> rightSum(a.size()), leftSum(a.size());
        for(int i=1;i<a.size();i++)
            leftSum[i] = leftSum[i-1] + a[i-1];
        for(int i=a.size()-2;i>=0;i--)
            rightSum[i] = rightSum[i+1] + a[i+1];
        for(int i=0;i<a.size();i++)
            leftSum[i] = abs(leftSum[i] - rightSum[i]);
        return leftSum;
    }
};