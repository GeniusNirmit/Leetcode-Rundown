// Approach-1

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(),nums1.end());
        unordered_set<int> s2(nums2.begin(),nums2.end());
        vector<int> v;
        for(auto i:s1)
        {
            if(s2.find(i) != s2.end())
                v.push_back(i);
        }
        return v;
    }
};

// Approach-2

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        unordered_set<int> s;
        vector<int> v;
        int i = 0;
        int j = 0;
        while(i<nums1.size() && j<nums2.size()) 
        {   
            if(nums1[i]<nums2[j]) 
                i++;
            else if(nums2[j]<nums1[i]) 
                j++;
            else
            {
                s.insert(nums1[i]);
                i++;
                j++;
            } 
        }
        for(auto i:s)
            v.push_back(i);
        return v;
    }
};