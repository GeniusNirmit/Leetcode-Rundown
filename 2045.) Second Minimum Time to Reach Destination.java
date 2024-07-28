class Solution {
    public int secondMinimum(int n, int[][] edges, int time, int change) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        int[] time1 = new int[n + 1];
        int[] time2 = new int[n + 1];

        for (int i = 0; i < edges.length; i++) {
            adj.computeIfAbsent(edges[i][0], value -> new ArrayList<Integer>()).add(edges[i][1]);
            adj.computeIfAbsent(edges[i][1], value -> new ArrayList<Integer>()).add(edges[i][0]);
        }

        for (int i = 1; i <= n; i++) {
            time1[i] = -1;
            time2[i] = -1;
        }

        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[] { 1, 1 });
        time1[1] = 0;

        while (!q.isEmpty()) {
            int node = q.peek()[0];
            int freq = q.peek()[1];
            q.poll();

            int timeTaken = -1;
            if (freq == 1)
                timeTaken = time1[node];
            else
                timeTaken = time2[node];

            if ((timeTaken / change) % 2 == 1)
                timeTaken = change * (timeTaken / change + 1) + time;
            else
                timeTaken = timeTaken + time;

            if (adj.containsKey(node)) {
                for (int i = 0; i < adj.get(node).size(); i++) {
                    if (time1[adj.get(node).get(i)] == -1) {
                        time1[adj.get(node).get(i)] = timeTaken;
                        q.offer(new int[] { adj.get(node).get(i), 1 });
                    } else if (time2[adj.get(node).get(i)] == -1 && time1[adj.get(node).get(i)] != timeTaken) {
                        if (adj.get(node).get(i) == n)
                            return timeTaken;
                        time2[adj.get(node).get(i)] = timeTaken;
                        q.offer(new int[] { adj.get(node).get(i), 2 });
                    }
                }
            }

        }

        return 0;
    }
}