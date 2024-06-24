class Solution {
    public int longestSubarray(int[] a, int limit) {
        int n = a.length;
        TreeMap<Integer, Integer> pq = new TreeMap<>();
        int i = 0, maxLength = 0;

        for (int j = 0; j < n; ++j) {
            pq.put(a[j], pq.getOrDefault(a[j], 0) + 1);

            while (pq.lastKey() - pq.firstKey() > limit) {
                pq.put(a[i], pq.get(a[i]) - 1);
                if (pq.get(a[i]) == 0)
                    pq.remove(a[i]);
                i++;
            }

            maxLength = Math.max(maxLength, j - i + 1);
        }

        return maxLength;
    }
}