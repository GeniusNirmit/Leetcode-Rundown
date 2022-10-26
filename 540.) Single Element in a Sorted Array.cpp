class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        unordered_map<int , int> mp;
        for(int i=0;i<a.size();i++)
            mp[a[i]]++;
        for(auto i:mp)
        {
            if(i.second==1)
                return i.first;
        }
        return -1;
    }
};