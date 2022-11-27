// Approach-1

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        for(int i=0;i<nums1.size();i++)
        {
            sort(nums2.begin(),nums2.end());
            int l = 0, h = nums2.size()-1,mid;
            while(l<=h)
            {
                mid = (l+h)/2;
                if(nums2[mid] == nums1[i])
                {
                    v.push_back(nums1[i]);
                    nums2[mid] = -1;
                    break;
                }
                else if(nums2[mid] > nums1[i])
                    h = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return v;
    }
};

// Approach-2

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]==nums2[j])
            {
                v.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]>nums2[j])
                j++;
            else
                i++;
        }
        return v;
    }
};

// Approach-3

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp1;
        map<int,int> mp2;
        vector<int> v;       
        for(int i=0;i<nums1.size();i++)
            mp1[nums1[i]]++;
        for(int i=0;i<nums2.size();i++)
            mp2[nums2[i]]++;
        auto it1 = mp1.begin();
        auto it2 = mp2.begin();
        while(it1!=mp1.end() && it2!=mp2.end())
        {
            if(it1->first == it2->first)
            {
                int temp = min(it1->second,it2->second);
                while(temp--)
                    v.push_back(it1->first);
                it1++;
                it2++;
            }
            else if(it1->first > it2->first)
                it2++;
            else
                it1++;
        }
        return v;
    }
};