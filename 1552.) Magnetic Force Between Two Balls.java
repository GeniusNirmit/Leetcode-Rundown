class Solution {
    boolean isPossible(int[] position, int distance, int balls) {
        int n = position.length;
        int currentBalls = 1;
        int prevPosition = position[0];
        for (int i = 1; i < n; i++) {
            if (position[i] - prevPosition >= distance) {
                currentBalls++;
                prevPosition = position[i];
            }

            if (currentBalls >= balls)
                return true;
        }
        return false;
    }

    public int maxDistance(int[] position, int m) {
        int n = position.length;
        int minForce = 0;
        Arrays.sort(position);

        int low = 1, high = (position[n - 1] - position[0]) / (m - 1);
        while (low <= high) {
            int mid = (low + high) / 2;

            if (isPossible(position, mid, m)) {
                minForce = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }

        return minForce;
    }
}