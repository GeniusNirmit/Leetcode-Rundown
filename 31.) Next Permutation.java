class Solution {
    private void reverse(int[] a, int start, int end) {
        while (start <= end) {
            swap(a, start, end);
            start++;
            end--;
        }
    }

    private void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    public void nextPermutation(int[] a) {
        int n = a.length, breakInd = -1;

        for (int i = n - 2; i >= 0; i--) {
            if (a[i] < a[i + 1]) {
                breakInd = i;
                break;
            }
        }

        if (breakInd == -1) {
            reverse(a, 0, n - 1);
            return;
        }

        for (int i = n - 1; i > breakInd; i--) {
            if (a[breakInd] < a[i]) {
                swap(a, breakInd, i);
                break;
            }
        }

        reverse(a, breakInd + 1, n - 1);
    }
}