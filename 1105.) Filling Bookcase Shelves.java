class Solution {
    int placeBooks(int[][] books, int shelfWidth, int ind, int[] dp) {
        int n = books.length;

        if (ind == n)
            return -1;
        if (dp[ind] != -1)
            return dp[ind];

        int minHeight = Integer.MAX_VALUE;
        int width = 0;
        int height = 0;

        for (int i = ind; i < n; i++) {
            width += books[i][0];

            if (width <= shelfWidth) {
                height = Math.max(height, books[i][1]);
                minHeight = Math.min(minHeight, height + placeBooks(books, shelfWidth, i + 1, dp));
            }
        }

        return dp[ind] = minHeight;
    }

    public int minHeightShelves(int[][] books, int shelfWidth) {
        int n = books.length;
        int[] dp = new int[n];

        for (int i = 0; i < n; i++)
            dp[i] = -1;

        return placeBooks(books, shelfWidth, 0, dp) + 1;
    }
}