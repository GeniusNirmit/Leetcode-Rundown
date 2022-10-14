class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> m;
        set<int> s;
        for(int i=0;i<arr.size();i++)
            m[arr[i]]++;
        for(auto i:m)
            s.insert(i.second);
        if(s.size()==m.size())
            return true;
        return false;
    }
};