class Solution {
public:
    int jump(vector<int>& a) {
        vector<int> maxSteps;
        int jumpCounter = 0;
        maxSteps.push_back(a[0]);
        for(int i=1;i<a.size();i++)
            maxSteps.push_back(max(a[i]+i,maxSteps[i-1]));
        int i=0;
        while(i<maxSteps.size()-1)
        {
            jumpCounter++;
            i = maxSteps[i];
        }
        return jumpCounter;
    }
};