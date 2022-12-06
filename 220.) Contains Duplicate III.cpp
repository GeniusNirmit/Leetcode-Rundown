class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& a, int indexDiff, int valueDiff) {
        set<int> s;
        for(int i=0;i<a.size();i++)
        {
            if(i>indexDiff)
                s.erase(a[i-indexDiff-1]);
            auto temp = s.lower_bound(a[i] - valueDiff);
            if(temp != s.end() && *temp - a[i] <= valueDiff)
                return true;
            s.insert(a[i]);
        }
        return false;
    }
};