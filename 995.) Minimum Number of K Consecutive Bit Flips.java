class Solution {
    public int minKBitFlips(int[] a, int k) {
        int n = a.length;
        Deque<Integer> q = new LinkedList<>();
        int counter = 0;

        for (int i = 0; i < n; i++) {
            while (q.size() != 0 && i > q.peek() + k - 1)
                q.poll();

            if ((a[i] + q.size()) % 2 == 0) {
                if (i + k > n)
                    return -1;
                counter++;
                q.offer(i);
            }
        }
        return counter;
    }
}