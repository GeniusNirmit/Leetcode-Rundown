class Solution {
    public boolean threeConsecutiveOdds(int[] a) {
        int n = a.length;
        int counter = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] % 2 != 0)
                counter++;
            else
                counter = 0;

            if (counter == 3)
                return true;
        }

        return false;
    }
}