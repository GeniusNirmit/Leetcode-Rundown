
class DisjointSet {
public:
    vector<int> parent;
    vector<int> size;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet d(n*n);

        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<n; j++) 
            {
                if(grid[i][j] == 1) 
                {
                    vector<int> delRow{-1, 0, 1, 0};
                    vector<int> delCol{0, -1, 0, 1};

                    for(int k=0; k<4; k++)
                    {
                        int tempRow = i + delRow[k]; 
                        int tempCol = j + delCol[k];

                        if(isValid(tempRow, tempCol, n) && grid[tempRow][tempCol] == 1) 
                        {
                            int current = i*n + j;
                            int next = tempRow*n + tempCol;
                            d.unionBySize(current, next);
                        }
                    }
                }
            }
        }

        int maxSize = 0;
        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<n; j++) 
            {
                if(grid[i][j] == 0) 
                {
                    vector<int> delRow{-1, 0, 1, 0};
                    vector<int> delCol{0, -1, 0, 1};
                    set<int> components;

                    for(int k=0; k<4; k++)
                    {
                        int tempRow = i + delRow[k]; 
                        int tempCol = j + delCol[k];

                        if(isValid(tempRow, tempCol, n) && grid[tempRow][tempCol] == 1) 
                            components.insert(d.findParent(tempRow*n + tempCol));
                    }

                    int size = 0;
                    for(auto component: components)
                        size += d.size[component];
                    maxSize = max(maxSize, size + 1);
                }
            }
        }

        for(int i=0; i<n*n; i++)
            maxSize = max(maxSize, d.size[d.findParent(i)]);
        return maxSize;
    }
    bool isValid(int row, int col, int n) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }
};