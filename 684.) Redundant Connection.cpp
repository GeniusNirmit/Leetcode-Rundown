long long MOD = 1e9 + 7;
class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    void unionBySize(int node1, int node2) {
        int ultParent1 = findUltParent(node1);
        int ultParent2 = findUltParent(node2);

        if(ultParent1 == ultParent2) {
            return;
        }

        if(size[ultParent1] > size[ultParent2]) {
            parent[ultParent2] = ultParent1;
            size[ultParent1] += size[ultParent2];
            size[ultParent1] %= MOD;
        } else {
            parent[ultParent1] = ultParent2;
            size[ultParent2] += size[ultParent2];
            size[ultParent2] %= MOD;
        }
    }

    int findUltParent(int node) {
        if(parent[node] == node) {
            return node;
        }

        return parent[node] = findUltParent(parent[node]);
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);

        for(int i = 0; i < n; i++) {
            if(ds.findUltParent(edges[i][0]) == ds.findUltParent(edges[i][1])) {
                return edges[i];
            } else {
                ds.unionBySize(edges[i][0], edges[i][1]);
            }
        }

        return edges[n - 1];
    }
};