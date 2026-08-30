class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) {
            return 1;
        }

        int minInd = 0;
        int maxInd = 0;

        for(int i = 0; i < n; i++) {
            if(nums[minInd] > nums[i]) {
                minInd = i;
            }

            if(nums[maxInd] < nums[i]) {
                maxInd = i;
            }
        }

        int left = min(minInd, maxInd);
        int right = max(minInd, maxInd);
        
        return min(right + 1, min(left + 1 + n - right, n - left));
    }
};