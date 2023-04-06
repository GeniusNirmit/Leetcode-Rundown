class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i=0, j=0;
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] == nums2[j])
                return nums1[i];
            else if(nums1[i] > nums2[j])
                j++;
            else if(nums1[i] < nums2[j])
                i++;
        }
        
        string smallNum;
        if(nums1[0] > nums2[0])
        {
            smallNum += nums2[0] + '0';
            smallNum += nums1[0] + '0';
        }
        else
        {
            smallNum += nums1[0] + '0';
            smallNum += nums2[0] + '0';
        }
        return stoi(smallNum);
    }
};