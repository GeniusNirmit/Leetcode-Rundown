class Solution {
    public int minDifference(int[] a) {
        int n = a.length;

        if (n <= 4)
            return 0;

        Arrays.sort(a);
        int minDiff = Integer.MAX_VALUE;
        minDiff = Math.min(minDiff, a[n - 4] - a[0]);
        minDiff = Math.min(minDiff, a[n - 3] - a[1]);
        minDiff = Math.min(minDiff, a[n - 2] - a[2]);
        minDiff = Math.min(minDiff, a[n - 1] - a[3]);
        return minDiff;
    }
}