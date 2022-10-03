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

// Approach-2

class Solution {
public:
    bool containsDuplicate(vector<int>& a) {
        sort(a.begin(),a.end());
        for(int i=0;i<a.size()-1;i++)
        {
            if(a[i]==a[i+1])
                return true;
        }
        return false;
    }
};