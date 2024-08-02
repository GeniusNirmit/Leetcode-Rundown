class Solution {
    public int minSwaps(int[] a) {
        int n = a.length;
        int oneCounter = 0;
        int minSwaps = n, swaps = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] == 1)
                oneCounter++;
        }

        for (int i = 0; i < oneCounter; i++) {
            if (a[i] == 0)
                swaps++;
        }

        minSwaps = swaps;
        for (int i = oneCounter; i < 2 * n + 1; i++) {
            if (a[i % n] == 0)
                swaps++;
            if (a[(i - oneCounter) % n] == 0)
                swaps--;

            minSwaps = Math.min(minSwaps, swaps);
        }

        return minSwaps;
    }
}