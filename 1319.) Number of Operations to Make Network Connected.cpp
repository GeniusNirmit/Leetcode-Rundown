class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i=0; i<=n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ultParent_u = findParent(u);
        int ultParent_v = findParent(v);

        if(ultParent_u == ultParent_v) 
        {
            parent[ultParent_u] = ultParent_v;
            size[ultParent_v] += size[ultParent_u];
        }
        else
        {
            parent[ultParent_v] = ultParent_u;
            size[ultParent_u] += size[ultParent_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet d(n);
        int extraEdges = 0;
        int isolatedComputers = 0;

        for(int i=0; i<connections.size(); i++)
        {
            if(d.findParent(connections[i][0]) == d.findParent(connections[i][1]))
                extraEdges++;
            else
                d.unionBySize(connections[i][0], connections[i][1]);
        }

        for(int i=0; i<n; i++)
        {
            if(d.findParent(i) == i)
                isolatedComputers++;
        }

        if(isolatedComputers - 1 <= extraEdges)
            return isolatedComputers - 1;
        return -1;
    }
};