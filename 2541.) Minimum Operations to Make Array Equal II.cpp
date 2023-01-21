class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1 == nums2)
            return 0;
        if(nums1 != nums2 && k==0)
            return -1;
        long long counter = 0;
        long long nullifyCounter = 0;
        for(int i=0;i<nums1.size();i++)
        {
            if(abs(nums1[i] - nums2[i]) % k == 0)
            {
                nullifyCounter += (nums1[i] - nums2[i]) / k;
                counter += abs(nums1[i] - nums2[i]) / k;
            }
        }
        if(counter && !nullifyCounter)
            return counter/2;
        return -1;
    }
};