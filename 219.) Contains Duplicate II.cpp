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

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& a, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<a.size();i++)
        {
            if (mp.count(a[i])==0)
                mp[a[i]] = i;
            else if (i - mp[a[i]]<=k)
                return true;
            else
                mp[a[i]] = i;
        }
        return false;
    }
};
