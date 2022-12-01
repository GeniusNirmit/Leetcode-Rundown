class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        multiset<int> s;
        for(int i=0;i<a.size();i++)
        {
            s.insert(a[i]);
            if(s.size()>k)
                s.erase(s.begin());
        }
        return *s.begin();
    }
};