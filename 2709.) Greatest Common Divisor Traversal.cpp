class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ultParent_u = findParent(u);
        int ultParent_v = findParent(v);

        if (ultParent_u == ultParent_v)
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

class Solution
{
public:
    bool canTraverseAllPairs(vector<int> &a)
    {
        int n = a.size();
        int MAX = 1e5;

        DisjointSet ds(MAX + 1);
        vector<int> sieve(MAX + 1);

        if (n == 1)
            return true;

        for (int i = 2; i <= MAX; i++)
        {
            if (sieve[i] == 0)
            {
                for (int j = i; j <= MAX; j += i)
                    sieve[j] = i;
            }
        }

        for (int i = 0; i < n; i++)
        {
            int current = a[i];
            if (current == 1)
                return false;

            while (current > 1)
            {
                int factor = sieve[current];
                if (ds.findParent(factor) != ds.findParent(a[i]))
                    ds.unionBySize(factor, a[i]);
                while (current % factor == 0)
                    current /= factor;
            }
        }

        int node = ds.findParent(a[0]);
        for (int i = 1; i < n; i++)
        {
            if (node != ds.findParent(a[i]))
                return false;
        }
        return true;
    }
};