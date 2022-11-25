// Approach-1

class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        unordered_map<int,int> mp;
        vector<int> v;
        for(int i=0;i<a.size();i++)
            mp[a[i]]++;
        int temp = a.size()/3;
        for(auto i:mp)
        {
            if(i.second>temp)
                v.push_back(i.first);
        }
        return v;
    }
};