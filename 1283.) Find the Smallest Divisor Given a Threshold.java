class Solution {
    public int findNumber(int[] nums, int num) {
        int n = nums.length;

        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += Math.ceil((double) nums[i] / num);

        return sum;
    }

    public int smallestDivisor(int[] nums, int threshold) {
        int n = nums.length;

        int low = 1, high = 0;

        for (int i = 0; i < n; i++)
            high = Math.max(high, nums[i]);

        int minValue = -1;
        int minSum = Integer.MAX_VALUE;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int sum = findNumber(nums, mid);

            if (sum <= threshold) {
                minValue = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }

        return minValue;
    }
}