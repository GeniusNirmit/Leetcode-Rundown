class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        multiset<int> s;
        vector<int> v;
        for(int i=0;i<k;i++)
            s.insert(a[i]);
        auto it = s.end();
        it--;
        v.push_back(*it);
        for(int i=k;i<a.size();i++)
        {
            s.insert(a[i]);
            s.erase(s.find(a[i-k]));
            it = s.end();
            it--;
            v.push_back(*it);
        }
        return v;
    }
};