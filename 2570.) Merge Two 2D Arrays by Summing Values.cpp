class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> mp;
        vector<vector<int>> newArray;
        for(int i=0;i<nums1.size();i++)
            mp[nums1[i][0]] += nums1[i][1];
        for(int i=0;i<nums2.size();i++)
            mp[nums2[i][0]] += nums2[i][1];
        for(auto i:mp)
        {
            vector<int> temp(2);
            temp[0] = i.first;
            temp[1] = i.second;
            newArray.push_back(temp);
        }
        return newArray;
    }
};