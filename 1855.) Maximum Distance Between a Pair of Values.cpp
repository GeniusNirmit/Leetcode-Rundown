// Approach-1

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int max_diff = 0;
        for(int i=nums1.size()-1;i>=0;i--)
        {
            int l = nums2.size()-1, h = i, mid;
            while(h<=l)
            {
                mid = (l+h)/2;
                if(i <= mid && nums1[i] <= nums2[mid])
                {
                    if(mid - i > max_diff)
                        max_diff = mid - i;
                    h = mid + 1;
                        
                }
                else if(i > mid || nums1[i] > nums2[mid])
                    l = mid - 1;
            }
        }
        return max_diff;
    }
};

// Approach-2

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = nums1.size()-1, j = nums2.size()-1;
        int max_diff = 0;
        while(i>=0 && j>=0)
        {
            if(nums1[i]<=nums2[j])
            {
                if(j - i > max_diff)
                    max_diff = j - i;
                i--;
            }
            else
                j--;
        }
        return max_diff;
    }
};