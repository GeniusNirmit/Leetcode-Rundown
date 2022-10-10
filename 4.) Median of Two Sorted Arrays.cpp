class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,k=0;
        vector<int> v;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i] > nums2[j])
            {
                v.push_back(nums2[j]);
                j++;
            }
            else
            {
                v.push_back(nums1[i]);
                i++;
            }
            k++;
        }
        while(i<nums1.size())
        {
            v.push_back(nums1[i]);
            i++;
            k++;
        }
        while(j<nums2.size())
        {
            v.push_back(nums2[j]);
            j++;
            k++;
        }
        if(v.size()%2==0)
        {
            double a = v[v.size()/2];
            double b = v[(v.size()/2)-1];            
            return (a+b)/2;
        }
        else
            return v[v.size()/2];
    }
};