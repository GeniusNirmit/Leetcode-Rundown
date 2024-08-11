public class Solution {
    int[] topoSort(int[][] edges, int k) {
        List<Integer>[] adj = new ArrayList[k + 1];
        int[] indegree = new int[k + 1];
        int[] order = new int[k];

        for (int i = 0; i < k + 1; i++)
            adj[i] = new ArrayList<Integer>();

        for (int i = 0; i < edges.length; i++) {
            adj[edges[i][0]].add(edges[i][1]);
            indegree[edges[i][1]]++;
        }

        Queue<Integer> q = new LinkedList<>();

        for (int i = 1; i < k + 1; i++) {
            if (indegree[i] == 0)
                q.offer(i);
        }

        int ind = 0;
        while (!q.isEmpty()) {
            int current = q.poll();
            order[ind] = current;
            ind++;
            k--;
            for (int i = 0; i < adj[current].size(); i++) {
                int next = adj[current].get(i);
                indegree[next]--;

                if (indegree[next] == 0)
                    q.offer(next);
            }
        }

        if (k != 0)
            return new int[0];
        return order;
    }

    public int[][] buildMatrix(int k, int[][] rowConditions, int[][] colConditions) {
        int[] orderRows = topoSort(rowConditions, k);
        int[] orderColumns = topoSort(colConditions, k);
        int[][] mat = new int[k][k];

        if (orderRows.length == 0 || orderColumns.length == 0)
            return new int[0][0];

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (orderRows[i] == orderColumns[j])
                    mat[i][j] = orderRows[i];
            }
        }

        return mat;
    }
}