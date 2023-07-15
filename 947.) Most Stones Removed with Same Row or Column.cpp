class DisjointSet {
public:
    vector<int> parent, size;
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
            size[ultParent_v] += (long long)size[ultParent_u];
        }
        else
        {
            parent[ultParent_v] = ultParent_u;
            size[ultParent_u] += (long long)size[ultParent_v];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        int counter = 0;
        for(int i=0; i<stones.size(); i++)
        {
            maxRow = max(maxRow, stones[i][0]);
            maxCol = max(maxCol, stones[i][1]);
        }

        DisjointSet d(maxRow + maxCol + 1);
        unordered_map<int, int> stone;
        for(int i=0; i<stones.size(); i++)
        {
            int row = stones[i][0];
            int col = stones[i][1] + maxRow + 1;
            d.unionBySize(row, col);
            stone[row] = 1;
            stone[col] = 1;
        }

        for(auto i: stone)
        {
            if(d.findParent(i.first) == i.first)
                counter++;
        }

        return stones.size() - counter;
    }
};