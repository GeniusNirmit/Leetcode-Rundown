/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 0, h = mountainArr.length()-1, mid;
        while(l<h)
        {
            mid = (l+h)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1))
                l = mid + 1;
            else
                h = mid;
        }

        int peak = l;
        l = 0, h = peak;
        while(l<=h)
        {
            mid = (l+h)/2;
            if(mountainArr.get(mid) == target)
                return mid;
            else if(mountainArr.get(mid) < target)
                l = mid + 1;
            else
                h = mid - 1;
        }

        l = peak, h = mountainArr.length()-1;
        while(l<=h)
        {
            mid = (l+h)/2;
            if(mountainArr.get(mid) == target)
                return mid;
            else if(mountainArr.get(mid) > target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return -1;
    }
};