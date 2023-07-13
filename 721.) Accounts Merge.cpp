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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mailMap;
        DisjointSet d(accounts.size());
        vector<vector<string>> mergedAccounts(accounts.size());

        for(int i=0; i<accounts.size(); i++)
        {
            for(int j=1; j<accounts[i].size(); j++)
            {
                if(mailMap.find(accounts[i][j]) == mailMap.end())
                    mailMap[accounts[i][j]] = i;
                else
                    d.unionBySize(mailMap[accounts[i][j]], i);
            }
        }

        for(auto i: mailMap) 
            mergedAccounts[d.findParent(i.second)].push_back(i.first);
        
        for(int i=0; i<mergedAccounts.size(); i++)
        {
            if(!mergedAccounts[i].size())
            {
                mergedAccounts.erase(mergedAccounts.begin() + i);
                i--;
            }
            else
            {
                sort(mergedAccounts[i].begin(), mergedAccounts[i].end());
                mergedAccounts[i].insert(mergedAccounts[i].begin(), accounts[d.findParent( mailMap[ mergedAccounts[i][0]])][0]);
            }
        }
        return mergedAccounts;
    }
};