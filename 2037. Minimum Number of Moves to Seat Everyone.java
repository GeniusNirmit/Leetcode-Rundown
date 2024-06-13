class Solution {
    private int findMax(int[] a) {
        int n = a.length;
        int maxVal = 0;

        for (int i = 0; i < n; i++)
            maxVal = Math.max(maxVal, a[i]);

        return maxVal;
    }

    public int minMovesToSeat(int[] seats, int[] students) {
        int n = seats.length;
        int maxVal = Math.max(findMax(seats), findMax(students));
        int[] diff = new int[maxVal];

        for (int i = 0; i < n; i++)
            diff[seats[i] - 1]++;

        for (int i = 0; i < n; i++)
            diff[students[i] - 1]--;

        int moves = 0;
        int unmatched = 0;
        for (int i = 0; i < maxVal; i++) {
            moves += Math.abs(unmatched);
            unmatched += diff[i];
        }

        return moves;
    }
}