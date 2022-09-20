// Approach-1

class Solution {
public:
    vector<int> runningSum(vector<int>& a) {
        for(int i=1;i<a.size();i++)
            a[i]+=a[i-1];
        return a;
    }
};

// Approach-2


class Solution {
public:
    vector<int> runningSum(vector<int>& a) {
        vector<int> v;
        int sum=0;
        for(int i=0;i<a.size();i++)
        {
            sum+=a[i];
            v.push_back(sum);
        }
        return v;
    }
};