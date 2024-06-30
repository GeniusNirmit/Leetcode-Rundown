class Solution {
    void dfs(List<List<Integer>> ancestors, List<Integer>[] adj, int prev, int current) {
        for (int child : adj[current]) {
            if (ancestors.get(child).isEmpty() || ancestors.get(child).get(ancestors.get(child).size() - 1) != prev) {
                ancestors.get(child).add(prev);
                dfs(ancestors, adj, prev, child);
            }
        }
    }

    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        List<Integer>[] adj = new ArrayList[n];
        List<List<Integer>> ancestors = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            ancestors.add(new ArrayList<>());
            adj[i] = new ArrayList<>();
        }

        for (int i = 0; i < edges.length; i++)
            adj[edges[i][0]].add(edges[i][1]);

        for (int i = 0; i < n; i++)
            dfs(ancestors, adj, i, i);

        return ancestors;
    }
}