// Approach-1

class Solution
{
public:
    int searchInsert(vector<int> &a, int target)
    {
        int l = 0, h = a.size() - 1, mid;
        while (l <= h)
        {
            mid = (l + h) / 2;
            if (a[mid] == target)
                return mid;
            else if (a[mid] > target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        if (a[mid] < target)
            return mid + 1;
        else
            return mid;
    }
};

// Approach-2
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l=0;
        int h=nums.size()-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(nums[mid]<target)
                l++;
            else
                h--;
        }
        if(l<nums.size())
            return l;
        else
            return nums.size();
    }
};