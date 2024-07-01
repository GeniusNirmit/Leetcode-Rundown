class DisjointSet {
    List<Integer> parent = new ArrayList<>();
    List<Integer> rank = new ArrayList<>();

    public DisjointSet(int n) {
        for (int i = 0; i <= n; i++) {
            parent.add(i);
            rank.add(1);
        }
    }

    public int findParent(int node) {
        if (parent.get(node) == node)
            return node;

        int ultimateParent = findParent(parent.get(node));
        parent.set(node, ultimateParent);
        return parent.get(node);
    }

    public void unionByRank(int u, int v) {
        int parentU = findParent(u);
        int parentV = findParent(v);

        if (parentU == parentV)
            return;

        if (rank.get(parentU) < rank.get(parentV))
            parent.set(parentU, parentV);
        else if (rank.get(parentU) > rank.get(parentV))
            parent.set(parentV, parentU);
        else
            parent.set(parentV, parentU);
        rank.set(parentV, rank.get(parentU) + 1);
    }
}

class Solution {
    public int maxNumEdgesToRemove(int n, int[][] edges) {
        DisjointSet alice = new DisjointSet(n);
        DisjointSet bob = new DisjointSet(n);
        int counter = 0;
        int aliceNodes = n, bobNodes = n;

        for (int i = 0; i < edges.length; i++) {
            int type = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];

            if (type == 3) {
                int u1 = alice.findParent(u);
                int v1 = alice.findParent(v);
                int u2 = bob.findParent(u);
                int v2 = bob.findParent(v);

                if (u1 != v1) {
                    alice.unionByRank(u1, v1);
                    aliceNodes--;
                }

                if (u2 != v2) {
                    bob.unionByRank(u2, v2);
                    bobNodes--;
                }

                if (u1 == v1 && v2 == u2)
                    counter++;
            }
        }

        for (int i = 0; i < edges.length; i++) {
            int type = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];

            if (type == 1) {
                int u1 = alice.findParent(u);
                int v1 = alice.findParent(v);

                if (u1 == v1)
                    counter++;
                else {
                    aliceNodes--;
                    alice.unionByRank(u1, v1);
                }
            } else if (type == 2) {
                int u2 = bob.findParent(u);
                int v2 = bob.findParent(v);

                if (u2 == v2)
                    counter++;
                else {
                    bobNodes--;
                    bob.unionByRank(u2, v2);
                }
            }
        }

        if (aliceNodes != 1 || bobNodes != 1)
            return -1;
        return counter;
    }
}