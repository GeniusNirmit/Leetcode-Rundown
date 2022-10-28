// Approach-1

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& a, int k) {
        if(k<=0)
            return false;
        if(k>=a.size())
            k = a.size()-1;
        unordered_set<int> s;
        for(int i=0;i<a.size();i++)
        {
            if(i>k)
                s.erase(a[i-k-1]);
            if(s.find(a[i])!=s.end())
                return true;
            s.insert(a[i]);
        }
        return false;
    }
};

// Approach-2

