// Approach-1

class Solution {
public:
    bool containsDuplicate(vector<int>& a) {
        unordered_set<int> s;
        for(auto i:a)
            s.insert(i);
        if(a.size()==s.size())
            return false;
        return true;
    }
};