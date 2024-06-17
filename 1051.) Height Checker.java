class Solution {
    public int heightChecker(int[] heights) {
        int n = heights.length;
        int counter = 0;
        int[] expected = Arrays.copyOf(heights, n);
        Arrays.sort(expected);

        for (int i = 0; i < n; i++) {
            if (heights[i] != expected[i])
                counter++;
        }

        return counter;
    }
}