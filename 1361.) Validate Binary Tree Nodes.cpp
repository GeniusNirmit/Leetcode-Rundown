class DisjointSet
{
    vector<int> parent;

public:
    int trees;

    DisjointSet(int n)
    {
        parent.resize(n + 1);
        trees = n;
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    bool unionBySize(int u, int v)
    {
        int ultParent_u = findParent(u);
        int ultParent_v = findParent(v);

        if (ultParent_u == ultParent_v || ultParent_v != v)
            return false;

        parent[ultParent_v] = ultParent_u;
        trees--;
        return true;
    }
};

class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        DisjointSet d(n);

        for (int i = 0; i < n; i++)
        {
            if (leftChild[i] != -1 && !d.unionBySize(i, leftChild[i]))
                return false;
            if (rightChild[i] != -1 && !d.unionBySize(i, rightChild[i]))
                return false;
        }

        if (d.trees != 1)
            return false;
        return true;
    }
};