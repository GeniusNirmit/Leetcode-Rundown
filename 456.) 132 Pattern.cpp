class Solution {
public:
    bool find132pattern(vector<int>& a) {
        stack<int> s;
        int max = INT_MIN;
        for(int i=a.size()-1;i>=0;i--)
        {
            if(a[i]<max)
                return true;
            while(!s.empty() && a[i]>s.top())
            {
                max = s.top();
                s.pop();
            }
            s.push(a[i]);
        }
        return false;
    }
};