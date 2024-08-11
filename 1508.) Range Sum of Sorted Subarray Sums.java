class Solution {
    public int rangeSum(int[] a, int n, int left, int right) {
        List<Integer> subarraySums = new ArrayList<>();
        int MOD = (int) 1e9 + 7;
        int rangeSum = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += a[j];
                subarraySums.add(sum);
            }
        }

        Collections.sort(subarraySums);

        for (int i = left - 1; i < right; i++)
            rangeSum = (rangeSum + subarraySums.get(i)) % MOD;

        return rangeSum;
    }
}